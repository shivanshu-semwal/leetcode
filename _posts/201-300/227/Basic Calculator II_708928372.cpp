class Solution {
public:
    int eval(int a, int b, char o){
        if(o=='/') return a/b;
        if(o=='*') return a*b;
        if(o=='+') return a+b;
        return a-b;
    }
    
    int calculate(string s) {
        stack<int> o;
        stack<char> op;
        
        int n = s.length();   
        int no = 0;
        for(int i=0;i<n;i++){
            if('0' <= s[i] && s[i] <= '9'){
                no = no * 10 + (s[i]-'0');
            } else if(s[i] == ' ') {
                continue;
            } else {
                o.push(no);
                cout << no << endl;
                no = 0;
                if(op.empty()) op.push(s[i]);
                else{
                    if(s[i] == '/'){ 
                        while(!op.empty() && 
                              op.top() != '+' && op.top() != '-'
                             ){
                            int b = o.top(); o.pop();
                            int a = o.top(); o.pop();
                            o.push(eval(a, b, op.top()));
                            op.pop();
                        }
                        op.push(s[i]); 
                    }
                    else if (s[i] == '*'){
                        while(!op.empty() && 
                              op.top() != '+' && op.top() != '-'
                             ){
                            int b = o.top(); o.pop();
                            int a = o.top(); o.pop();
                            o.push(eval(a, b, op.top()));
                            op.pop();
                        }
                        op.push(s[i]); 
                    }
                    else {
                        while(!op.empty()){
                            int b = o.top(); o.pop();
                            int a = o.top(); o.pop();
                            o.push(eval(a, b, op.top()));
                            op.pop();
                        }
                        op.push(s[i]);
                    }
                }
            }
        }
        if(op.empty()) return o.empty() ? no : o.top();
        o.push(no);
        while(!op.empty()){
            int b = o.top(); o.pop();
            int a = o.top(); o.pop();
            cout << eval(a, b, op.top()) << endl;
            o.push(eval(a, b, op.top()));
            op.pop();
        }
        
        return o.top();
    }
};
