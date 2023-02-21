class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<long long> count;
        for (int i = 0; i < s.length();) {
            long long x = 0;
            if (s[i] == '0') {
                while (s[i] == '0') {
                    i++;
                    x++;
                    if (!(i < s.length())) break;
                }
                count.push_back(x);
            } else {
                while (s[i] == '1') {
                    i++;
                    x++;
                    if (!(i < s.length())) break;
                }
                count.push_back(x);
            }
        }
        for(int i=0;i<count.size();i++) cout << count[i] << " ";
        int sum=0;
        for(int i=0;i<count.size()-1;i++){
            sum+=min(count[i], count[i+1]);
        }
        return sum;
    }
};
