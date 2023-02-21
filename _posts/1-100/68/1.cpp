// https://leetcode.com/problems/text-justification

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSpace(int n) {
        string ans = "";
        while (n--) ans += " ";
        return ans;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<vector<string>> ans;
        vector<int> len;
        int n = words.size();
        for (int noLines = 0, i = 0; i < n; noLines++) {
            int s = words[i].length();
            ans.push_back(vector<string>{words[i++]});
            while (i < n) {
                if (s + words[i].length() + 1 <= maxWidth) {
                    ans[noLines].push_back(words[i]);
                    s += words[i].length() + 1;
                    i++;
                } else {
                    break;
                }
            }
            len.push_back(s - (ans.back().size() - 1));
        }
        vector<string> s;
        string t = "";
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i].size() == 1)
                s.push_back(ans[i][0] + getSpace(maxWidth - ans[i][0].length()));
            else {
                int noSpaces = maxWidth - len[i];
                while (noSpaces) {
                    for (int j = 0; j < ans[i].size() - 1; j++) {
                        ans[i][j] += " ";
                        noSpaces--;
                        if (noSpaces == 0) break;
                    }
                }
                t = "";
                for (int j = 0; j < ans[i].size(); j++) t += ans[i][j];
                s.push_back(t);
            }
        }
        t = ans.back()[0];
        for (int i = 1; i < ans.back().size(); i++) t += " " + ans.back()[i];
        t += getSpace(maxWidth - t.length());
        s.push_back(t);
        return s;
    }
};

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxwith = 16;

    Solution s;
    auto ans = s.fullJustify(words, maxwith);

    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}