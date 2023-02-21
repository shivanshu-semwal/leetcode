// https://leetcode.com/problems/minimum-window-substring

#include <bits/stdc++.h>

using namespace std;

void printMap(unordered_map<int, int> m) {
    for (auto i : m) cout << "{" << i.first << " " << i.second << "}, ";
    cout << endl;
}

class Solution {
public:
    bool check(unordered_map<int, int> &a, unordered_map<int, int> &b) {
        for (auto i = a.begin(); i != a.end(); i++) {
            if ((*i).second != 0) {
                auto t = b.find((*i).first);
                if (t == b.end()) return false;
                if ((*t).second < (*i).second) return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n < m) return "";
        unordered_map<int, int> ss, tt;
        for (auto i : t) tt[i] += 1;
        int right = 0, left = 0;
        pair<int, int> ans = {0, INT_MAX};

        while (right < n) {
            while (right < n) {
                ss[s[right]]++;
                if (check(tt, ss)) {
                    if (ans.second - ans.first > right - left) {
                        ans = {left, right};
                    }
                    right++;
                    break;
                }
                right++;
            }
            int tright = right - 1;
            int tleft = left;
            while (left <= tright) {
                ss[s[left]]--;
                if (!check(tt, ss)) {
                    if (right >= n && left == tleft) break;
                    if (ans.second - ans.first >= tright - left) {
                        ans = {left, tright};
                    }
                    left++;
                    break;
                }
                left++;
            }
        }
        if (ans.second == INT_MAX) return "";
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};

int main() {
    // test cases
    string a = "abc";
    string t = "b";

    Solution s;
    cout << s.minWindow(a, t);

    return 0;
}