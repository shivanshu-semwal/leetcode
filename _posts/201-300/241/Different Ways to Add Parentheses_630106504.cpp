class Solution {

public:
    vector<int> *dp[100][100];

    vector<int> solve(vector<int> &values, vector<char> &op, int start, int end) {

        if (dp[start][end] != nullptr) return *dp[start][end];

        if (start == end) {
            dp[start][end] = new vector<int>{values[start]};
            return *dp[start][end];
        }

        vector<int> *sol = new vector<int>;
        int n = values.size();

        for (int i = start; i < end; i++) {
            /* part one sol */
            vector<int> part1;
            if (dp[start][i] != nullptr)
                part1 = *dp[start][i];
            else
                part1 = solve(values, op, start, i);

            char o = op[i];

            vector<int> part2;
            if (dp[i + 1][end] != nullptr)
                part2 = *dp[i + 1][end];
            else
                part2 = solve(values, op, i + 1, end);

            for (int j = 0; j < part1.size(); j++) {
                for (int k = 0; k < part2.size(); k++) {
                    int ans = 0;
                    if (o == '+')
                        ans = part1[j] + part2[k];
                    else if (o == '-')
                        ans = part1[j] - part2[k];
                    else
                        ans = part1[j] * part2[k];
                    sol->push_back(ans);
                }
            }
        }
        dp[start][end] = sol;
        return *sol;
    }

    void convert(string e, vector<int> &values, vector<char> &op) {
        int n = e.length();
        int no = 0;
        for (int i = 0; i < n; i++) {
            if (e[i] == '+' || e[i] == '-' || e[i] == '*') {
                op.push_back(e[i]);
            } else {
                no = e[i] - '0';
                if (i + 1 < n && e[i + 1] >= '0' && e[i + 1] <= '9') {
                    no = no * 10 + (e[i + 1] - '0');
                    i++;
                }
                values.push_back(no);
            }
        }
    }

    vector<int> diffWaysToCompute(string e) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                dp[i][j] = nullptr;
            }
        }
        vector<int> values;
        vector<char> op;
        convert(e, values, op);
        return solve(values, op, 0, values.size() - 1);
    }
};
