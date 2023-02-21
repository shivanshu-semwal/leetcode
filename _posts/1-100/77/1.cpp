// https://leetcode.com/problems/combinations

#include <bits/stdc++.h>

using namespace std;

void printVectorVector(vector<vector<int>> v) {
    for (auto i : v) {
        cout << "[";
        for (auto j : i) cout << j << ",";
        cout << "]";
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int n, int k, int k2, int idx, int s) {
        if (idx == k2) {
            for (auto i : temp) cout << i << " ";
            cout << endl;
            ans.push_back(temp);
            return;
        }
        for (int i = s; i <= n - k + 1; i++) {
            temp[idx] = i;
            solve(n, k - 1, k2, idx + 1, i + 1);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ans = vector<vector<int>>();
        temp = vector<int>(k, 0);
        solve(n, k, k, 0, 1);
        return ans;
    }
};

int main() {
    Solution s;
    int n = 4, k = 2;
    auto ans = s.combine(n, k);
    printVectorVector(ans);
    return 0;
}