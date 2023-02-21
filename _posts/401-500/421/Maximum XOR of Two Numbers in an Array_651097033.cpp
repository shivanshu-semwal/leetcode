class trie{
public:
    trie *child[2];
    trie(){
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
public:
    trie *newnode;
    void insert(int n){
        trie *t = newnode;
        bitset<32> x(n);
        for(int i=31;i>=0;i--){
            if(t->child[x[i]] == nullptr)  t->child[x[i]]  = new trie();
            t = t->child[x[i]];
        }
    }
    int XOOR(int n){
        trie *t = newnode;
        bitset<32> bs(n);
        int ans = 0;
        for(int j=31;j>=0;j--){
            if(t->child[!bs[j]]){
                ans += (1 << j);
                t = t->child[!bs[j]];
            } else {
                t = t->child[bs[j]];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        newnode = new trie();
        for(auto i: nums) insert(i);
        
        int m = 0;
        for(auto i:nums){
            m = max(m, XOOR(i));
        }
        return m;
    }
    
};
