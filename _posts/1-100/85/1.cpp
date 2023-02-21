// https://leetcode.com/problems/maximal-rectangle

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> v) {
    cout << "[";
    for (auto i : v) cout << i << ", ";
    cout << "]" << endl;
}

class Solution {
public:
    int solve(vector<int> &v) {
        stack<int> t;
        vector<int> lmin, rmin;
        for (int i = 0; i < v.size(); i++) {
            while (!t.empty() && v[t.top()] >= v[i]) t.pop();
            lmin.push_back(t.empty() ? -1 : t.top());
            t.push(i);
        }
        t = stack<int>();
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!t.empty() && v[t.top()] >= v[i]) t.pop();
            rmin.push_back(t.empty() ? v.size() : t.top());
            t.push(i);
        }
        reverse(rmin.begin(), rmin.end());
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans = max(ans, v[i] * (rmin[i] - lmin[i] - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>> &m) {
        vector<int> v(m[0].size(), 0);
        int ans = INT_MIN;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) 
                v[j] = (m[i][j] == '0') ? 0 : (v[j] + 1);
            ans = max(ans, solve(v));
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 4, 4, 5, 6, 2, 1};
    cout << s.solve(v);
    return 0;
}

/*
0 0 1 0
0 0 1 0
0 0 1 0
0 0 1 1
0 1 1 1
0 1 1 1
1 1 1 1

1 0 1 1 1
0 1 0 1 0
1 1 0 1 1
1 1 0 1 1
0 1 1 1 1

*/