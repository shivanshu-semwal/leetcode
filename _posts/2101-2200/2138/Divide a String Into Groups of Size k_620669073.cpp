class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();

        char group[k + 1];
        group[k] = '\0';

        for (int i = 0; i < n; i += k) {
            // cout << "i: " << i << endl;
            int j = i;
            // cout << "j: " << j << endl;
            for (j = i; j < n && j < i + k; j++) {
                group[j - i] = s[j];
            }
            // cout << "xj: " << j << endl;
            // j--;
            if (j != i + k) {
                while (j < i + k) {
                    group[j - i] = fill;
                    j++;
                }
            }
            string s(group);
            ans.push_back(s);
        }
        return ans;
    }
};
