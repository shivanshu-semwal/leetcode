class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (words.size() == 0) return vector<int>();

        int n = s.length();
        int k = words[0].length();
        int l = k * words.size();

        unordered_map<string, int> m;

        for (int i = 0; i < words.size(); i++) {
            if (m.find(words[i]) == m.end()) m[words[i]] = 0;
            m[words[i]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n - l + 1; i++) {
            int c = 0;
            unordered_map<string, int> mm(m);

            for (int j = i; j < i + l; j += k) {
                if (
                    mm.find(s.substr(j, k)) != m.end() &&
                    mm[s.substr(j, k)] != 0) {
                    mm[s.substr(j, k)]--;
                    c++;
                } else
                    break;
            }
            if (c == words.size()) ans.push_back(i);
        }
        return ans;
    }
};