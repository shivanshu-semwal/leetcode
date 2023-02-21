// https://leetcode.com/problems/permutation-sequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fact(int n) {
        if (n == 1 || n == 0) return 1;
        return n * fact(n - 1);
    }

    string solve(int n, int t, int k, vector<bool> &taken) {
        if (t <= 0) return "";
        if (t == 1) {
            for (int i = 1; i <= n; i++)
                if (!taken[i])
                    return to_string(i);
        }
        if (t == 2) {
            string ans = "";
            if (k == 1) {
                for (int i = 1; i <= n; i++)
                    if (!taken[i]) ans += to_string(i);
            } else {
                for (int i = n; i >= 1; i--)
                    if (!taken[i]) ans += to_string(i);
            }
            return ans;
        }
        int f = fact(t - 1);
        int q = (k - 1) / f + 1;
        int c = 0, i = 1;

        cout << f << " " << q << " " << t << " " << endl;
        for (i = 1; i <= n && c != q; i++) {
            if (taken[i] == false) c++;
            if (c == q) break;
        }
        taken[i] = true;
        return to_string(i) + solve(n, t - 1, (k % f == 0) ? f : (k % f), taken);
    }

    string getPermutation(int n, int k) {
        vector<bool> taken(n + 1, false);
        return solve(n, n, k, taken);
    }
};

int main() {
    Solution s;
    int n = 4, k = 12;
    cout << s.getPermutation(n, k);
    return 0;
}

/*
"123"
"132"
"213"
"231"
"312"
"321"

so now choose the first char as 1
1 not 2 char - 2 permutaitons

choose 5th permutation

2 + 2 + 2 > 5 > 2 + 2
so not first char is 2
now 5 - 2 = 1
choose the first permutation
 */