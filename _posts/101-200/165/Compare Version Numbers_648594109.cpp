class Solution {
public:
    int compareVersion(string ver1, string ver2) {    
        int s1=0, s2=0;
        
        while(s1 < ver1.length() && s2 < ver2.length()){
            
            int no1 = 0;
            int no2 = 0;
            int i;
            
            for(i=s1;i<ver1.length();i++){
                if(ver1[i]=='.'){
                    s1 = i+1;
                    break;
                } else{
                   no1 = no1*10 + (ver1[i]-'0'); 
                }
            }
            cout << i <<  endl;
            if(i>=ver1.length()) s1 = ver1.length();
            
            for(i=s2;i<ver2.length();i++){
                if(ver2[i]=='.'){
                    s2 = i+1;
                    break;
                } else{
                   no2 = no2*10 + (ver2[i]-'0'); 
                }
            }
            cout << i <<  endl;
            if(i>=ver2.length()) s2 = ver2.length();
            cout << no1 << " " << no2 << endl;
            if(no1 < no2) return -1;
            else if(no1 > no2) return 1;
        }
        
        
        
        
        
        cout << "hi " << endl;
        
        
        
        
        while(s1 < ver1.length()){
            int no1 = 0;            
            int i;
            for(i=s1;i<ver1.length();i++){
                if(ver1[i]=='.'){
                    s1 = i+1;
                    break;
                } else{
                   no1 = no1*10 + (ver1[i]-'0'); 
                }
            }
            if(no1 != 0) return 1;
            if(i>=ver1.length()) s1 = ver1.length();
        }
        
        
        
        
        while(s2 < ver2.length()){
            int no2 = 0;            
            int i;
            for(i=s2;i<ver2.length();i++){
                if(ver2[i]=='.'){
                    s2 = i+1;
                    break;
                } else{
                   no2 = no2*10 + (ver2[i]-'0'); 
                }
            }
            if(no2 != 0) return -1;
            if(i>=ver2.length()) s2 = ver2.length();
        }
        return 0;
    }
};
