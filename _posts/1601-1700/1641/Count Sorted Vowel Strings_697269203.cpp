class Solution {
public:
    unordered_map<int, unordered_map<char, int>> m;
        
    int count(int n, char last_char){
        
        if(n==1){
            switch(last_char){
                case 'a': return 5;
                case 'e': return 4;
                case 'i': return 3;
                case 'o': return 2;
                case 'u': return 1;
            }
        }
        
        if(m.find(n) != m.end()){
            if(m[n].find(last_char) != m[n].end()){
                return m[n][last_char];
            }
        }
        
        long ans = 0;
        if(last_char <= 'a') ans += count(n-1, 'a');
        if(last_char <= 'e') ans += count(n-1, 'e');
        if(last_char <= 'i') ans += count(n-1, 'i');
        if(last_char <= 'o') ans += count(n-1, 'o');
        if(last_char <= 'u') ans += count(n-1, 'u');
        
        if(m.find(n) == m.end()) m[n] = unordered_map<char, int>();
        m[n][last_char] = ans;
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        return count(n, 'a');
    }
};
