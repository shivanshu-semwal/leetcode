// https://leetcode.com/problems/sqrtx
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = INT_MAX;
        while (l < h) {
            cout << l << " " << h << endl;
            long c = l + (h - l) / 2;
            if (c * c == x) return c;
            if (c * c < x)
                l = c + 1;
            else
                h = c - 1;
        }
        if(l * l <= x) return l;
        else return l-1;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(2);
    return 0;
}