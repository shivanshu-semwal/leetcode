#define lli long long 
class Solution {
public:
    lli calculateHash(string s, lli power, lli m) {
        lli k = s.length();
        vector<int> p(k + 1, 1);
        lli temp = 1;
        p[0] = 1;
        for (int i = 1; i < k + 1; i++) {
            temp = (temp * power) % m;
            p[i] = temp;
        }
        // running hash
        lli hash = 0;
        for (int i = 0; i < k; i++) {
            hash = (hash + (lli)(s[i] - 'a' + 1) * p[i]) % m;
        }
        return hash;
    }
    string subStrHash(string s, lli power, lli m, lli k, lli ans) {
        // val(a) = (a - 'a' + 1)
        lli hash = 0;
        lli n = s.length();

        lli p1 = 1;
        // running hash
        for (int i = 0; i < k; i++) {
            hash = (hash + (lli)(s[i] - 'a' + 1) * p1) % m;
            p1 = (p1 * power) % m;
        }
        //cout << "hash(" << s.substr(0, k) << ") = " << hash << "\n";
        if (hash == ans) return s.substr(0, k);

        lli newhash = 0;
        int p2 = 1;
        for (int i = k; i < n; i++) {

            lli remove = ((lli)(s[i - k] - 'a' + 1) * p2) % m;
            lli addVal = ((lli)(s[i] - 'a' + 1) * p1) % m;

            newhash = (hash - remove + addVal) % m;
            while (newhash < 0) newhash += m;

            //cout
            //    << "hash: " << newhash << " addval: " << addVal << " remove: " << remove
            //    << " p2: " << p2 << " p1: " << p1 << "\n";

            hash = newhash;
            //cout << "hash(" << s.substr(i - k + 1, k) << ") = " << hash;

            p2 = (p2 * power) % m;

            //cout << " ans: " << ((ans * p2) % m) << " p2: " << p2 << "\n";
            if (newhash == (ans * p2) % m && 
                calculateHash(s.substr(i - k + 1, k), power, m) == ans)
                return s.substr(i - k + 1, k);

            p1 = (p1 * power) % m;
        }

        return "";
    }
};
