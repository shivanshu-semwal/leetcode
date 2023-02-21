class Solution {
public:
    vector<int> computeLPSArray(string &pattern){
        int len = 0;     
        vector<int> lps;
        lps.push_back(0);
        int i=1;
        while(i<pattern.length()){
            if(pattern[i] == pattern[len]){
                len++; i++;
                lps.push_back(len);
            } else {
                if(len != 0) len = lps[len-1];
                else {
                    lps.push_back(0);
                    i++;
                }
            }
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        vector<int> lps = computeLPSArray(needle);
        int i=0, j=0;
        while(i<haystack.length()){
            if(needle[j] == haystack[i]){
                j++;i++;
            }
            if(j==needle.size()){
                return i-j;
            }
            else if(i<haystack.size() && needle[j] != haystack[i]){
                if(j!=0) j = lps[j-1];
                else i++;
            }
        }
        return -1;
    }
};
