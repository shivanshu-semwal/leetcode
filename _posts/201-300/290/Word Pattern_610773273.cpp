class Solution {
public:
    vector<string> tokenize(string s) {
        char str[s.length() + 1];
        for (int i = 0; i < s.length(); i++) {
            str[i] = s[i];
        }
        str[s.length()] = '\0';
        vector<string> arr;
        char *temp = strtok(str, " ");
        while (temp) {
            string x(temp);
            arr.push_back(x);
            temp = strtok(NULL, " ");
        }
        return arr;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> arr = tokenize(s);
        if(arr.size() != pattern.length()) return false;
        map<char, string> m;
        unordered_set<string> mm;
        for (int i = 0; i < pattern.length(); i++) {
            auto it = m.find(pattern[i]);
            if (it != m.end()) {
                // key exists
                // cout << "key = " << pattern[i] << " value: " << m[pattern[i]] << endl;
                // cout << "value to check: " << arr[i];
                if (m[pattern[i]] != arr[i]) return false;
            } else {
                // associate key doesn't exists
                // cout << "associating key for " << pattern[i] << " to " << arr[i] << endl;
                if (mm.find(arr[i]) != mm.end()) return false;
                m[pattern[i]] = arr[i];
                mm.insert(arr[i]);
            }
        }
        return true;
    }
};
