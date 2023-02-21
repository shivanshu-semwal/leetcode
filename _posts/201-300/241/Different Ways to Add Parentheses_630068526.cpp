class Solution {
public:
    vector<int> solve(vector<int> e) {
        int n = e.size();
        if (n == 1) return vector<int>{e[0]};
        if (n == 3) {
            //solve
            char c = e[1] - 100;
            if (c == '+')
                return vector<int>{e[0] + e[2]};
            else if (c == '-')
                return vector<int>{e[0] - e[2]};
            else
                return vector<int>{e[0] * e[2]};
        }

        vector<int> sol;
        for (int i = 0; i < n - 2; i += 2) {
            vector<int> part1 = solve(vector<int>(e.begin(), e.begin() + i + 1));

            char o = e[i + 1] - 100;

            vector<int> part2 = solve(vector<int>(e.begin() + i + 2, e.end()));

            for (int j = 0; j < part1.size(); j++) {
                for (int k = 0; k < part2.size(); k++) {
                    int ans = 0;
                    if (o == '+')
                        ans = part1[j] + part2[k];
                    else if (o == '-')
                        ans = part1[j] - part2[k];
                    else
                        ans = part1[j] * part2[k];
                    sol.push_back(ans);
                }
            }
        }
        return sol;
    }

    vector<int> convert(string e) {
        int n = e.length();
        vector<int> c;
        int no = 0;
        for (int i = 0; i < n; i++) {
            if (e[i] == '+' || e[i] == '-' || e[i] == '*') {
                c.push_back(e[i] + 100);
            } else {
                no = e[i] - '0';
                if (i + 1 < n && e[i + 1] >= '0' && e[i + 1] <= '9') {
                    no = no * 10 + (e[i + 1] - '0');
                    i++;
                }
                c.push_back(no);
            }
        }
        return c;
    }

    vector<int> diffWaysToCompute(string e) {
        vector<int> ex = convert(e);
        return solve(ex);
    }
};
