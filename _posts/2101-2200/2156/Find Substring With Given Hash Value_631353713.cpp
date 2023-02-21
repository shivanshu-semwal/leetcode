#define lli long long
class Solution {
public:
    vector<int> p;
    lli calculateHash(string s, lli power, lli m) {
        lli hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = (hash + (lli)(s[i] - 'a' + 1) * p[i]) % m;
        }
        return hash;
    }
    string subStrHash(string s, lli power, lli m, lli k, lli ans) {
        p = vector<int>(k, 1);
        lli hash = 0, n = s.length(), p1 = 1, newhash = 0, p2 = 1;
        for (int i = 0; i < k; i++) {
            hash = (hash + (lli)(s[i] - 'a' + 1) * p1) % m;
            p[i] = p1;
            p1 = (p1 * power) % m;
        }
        if (hash == ans) return s.substr(0, k);
        for (int i = k; i < n; i++) {
            lli remove = ((lli)(s[i - k] - 'a' + 1) * p2) % m;
            lli addVal = ((lli)(s[i] - 'a' + 1) * p1) % m;
            hash = (hash - remove + addVal) % m;
            while (hash < 0) hash += m;
            p2 = (p2 * power) % m;
            if (hash == (ans * p2) % m &&
                calculateHash(s.substr(i - k + 1, k), power, m) == ans)
                return s.substr(i - k + 1, k);
            p1 = (p1 * power) % m;
        }
        return "";
    }
};
