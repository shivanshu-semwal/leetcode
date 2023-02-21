#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(s[0]=='0'){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<int>single(n,-1);
        vector<int>dbl(n,-1);
        vector<int>total(n,-1);
        single[0]=1;
        dbl[0]=0;
        total[0]=1;
        for(int i=1;i<n;i++){
            if(s[i-1]!='0' && stoi(s.substr(i-1,2))<=26){
                dbl[i]=single[i-1];
            }
            else{
                dbl[i]=0;
            }
            if(s[i]!='0'){
                single[i]=total[i-1];
            }
            else{
                single[i]=0;
            }
            total[i]=single[i]+dbl[i];
        }
        return total[n-1];
    }
};

int main(){

  return 0;
}
