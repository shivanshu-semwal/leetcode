class Solution {
public:
    string minimizeResult(string e) {
        if(e.length() == 3) return "(" + e + ")";
        
        int pos = e.find("+");
        
        string n1 = e.substr(0, pos);
        int n11 = stoi(n1);        
        
        string n2 = e.substr(pos+1);
        int n22 = stoi(n2);
        
        int m = n11 + n22;
        
        int a = 1, b = n11, c = n22, d = 1;
        string ans = "(" + e + ")";
        string temp;
        for(int i=0;i<n1.length();i++){
            if(i==n1.length()-1){a=1;b=n11;}
            else{
                temp = string(&n1[0], &n1[i+1]); a=stoi(temp);
                temp = string(&n1[i+1], &n1[n1.length()]); b=stoi(temp);
            }
            for(int j=0;j<n2.length();j++){
                if(j==n2.length()-1){c=n22; d=1;}
                else{
                    temp = string(&n2[0], &n2[j+1]); c = stoi(temp);
                    temp = string(&n2[j+1], &n2[n2.length()]); d = stoi(temp);
                }
                
                int mm = a * (b+c) * d;
                // cout << "a: " << a << "\tb:" << b << "\tc:" << c << "\td:" << d << "\tm:" << mm <<endl;
                if(mm < m){
                    string aa = (i==n1.length()-1) ? "" : string(&n1[0], &n1[i+1]);
                    string bb = (i==n1.length()-1) ? n1 : string(&n1[i+1], &n1[n1.length()]);
                    
                    string cc = (j==n2.length()-1) ? n2 : string(&n2[0], &n2[j+1]);
                    string dd = (j==n2.length()-1) ? "" : string(&n2[j+1], &n2[n2.length()]);
                    
                    ans = aa + "(" + bb + "+" + cc + ")" + dd;
                    m = mm;
                }
            }
        }
        return ans;
    }
};
