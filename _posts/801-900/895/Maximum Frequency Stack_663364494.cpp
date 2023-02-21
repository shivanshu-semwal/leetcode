
class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxfreq;
    
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        int f = ((freq.find(val) == freq.end())?0:freq[val]) + 1;
        freq[val] = f;
        if(f + 1 > maxfreq) maxfreq = f;
        
        if(group.find(f) == group.end()) group[f] = stack<int>();
        group[f].push(val);
    }
    
    int pop() {
        int x = group[maxfreq].top();
        group[maxfreq].pop();
        freq[x]--;
        
        if(group[maxfreq].empty()) maxfreq--;
        return x;
    }
};
