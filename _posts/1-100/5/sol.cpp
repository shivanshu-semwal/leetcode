class Solution {
public:
string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> table(n, vector<bool>(n, false));
    int maxlength = 1;
    int start = 0;

    // for length 1
    for (int i = 0; i < n; i++) {
        table[i][i] = true;
    }

    // for length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            maxlength = 2;
            start = i;
        }
    }

    // for other lengths
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int end = i + l - 1;
            if (table[i + 1][end - 1] && s[i] == s[end]) {
                table[i][end] = true;
                if (l > maxlength) {
                    maxlength = l;
                    start = i;
                }
            }
        }
    }

    string ans = s.substr(start, maxlength);
    return ans;
}
};
