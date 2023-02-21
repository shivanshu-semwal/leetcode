// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int uniqueLetterString(string s) {
    unordered_map<char, vector<int>> m;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (m.find(s[i]) == m.end()) m[s[i]] = vector<int>();
      m[s[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
      if (m.find(i) == m.end()) continue;
      vector<int>& t = m[i];
      for (int j = 0; j < t.size(); j++) {
        int j_b = (j == 0) ? -1 : t[j - 1];
        int j_f = (j == t.size() - 1) ? n : t[j + 1];

        int b = (t[j] - j_b - 1);
        int f = (j_f - t[j] - 1);
        int temp = 1 + b + f + b * f;
        ans += temp;
        cout << (char)i << " " << temp << endl;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  string a = "LEETCODE";
//   string a = "ABC";
  cout << s.uniqueLetterString(a);
  return 0;
}

/*


abc


abcdef
aabbcdeff


abcadc


__|l|e|e|t|c|o|d|e|_
-1|0|1|2|3|4|5|6|7|8

c -> 4
d -> 6
e -> 1, 2
l -> 0
o -> 5
t -> 3


 */