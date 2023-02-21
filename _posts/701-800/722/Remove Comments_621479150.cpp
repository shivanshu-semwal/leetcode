class Solution {
public:
    vector<string> removeComments(vector<string> &source) {

        vector<string> ans;

        for (int i = 0; i < source.size();) {
            int inc = 1;
            if (source[i].empty()) {
                ans.push_back(source[i]);
                i += inc;
                continue;
            }

            /* iterating the source[i] string */

            for (int j = 0; !source[i].empty() && j < source[i].length() - 1; j++) {

                /* found inline comment starting */
                if (source[i][j] == '/' && source[i][j + 1] == '/') {
                    source[i] = source[i].substr(0, j);
                    continue;
                }

                /* found block comment starting */
                if (source[i][j] == '/' && source[i][j + 1] == '*') {

                    /* find the closing block i,j */

                    bool found = false;
                    // found on the same line
                    for (int l = j + 2; l < source[i].length() - 1; l++) {
                        if (source[i][l] == '*' && source[i][l + 1] == '/') {
                            source[i] = source[i].substr(0, j) +
                                        ((l + 2 < source[i].length())
                                             ? source[i].substr(l + 2, source[i].length())
                                             : "");
                            found = true;
                            break;
                        }
                    }

                    // found on other lines
                    if (!found) {
                        found = false;
                        int k = i + 1;
                        for (k = i + 1; !found && k < source.size(); k++) {
                            for (int l = 0; l < source[k].length(); l++) {
                                if (source[k][l] == '*' && source[k][l + 1] == '/') {
                                    source[i] = source[i].substr(0, j) +
                                                ((l + 2 < source[k].length())
                                                     ? source[k].substr(l + 2, source[k].length())
                                                     : "");
                                    found = true;
                                    break;
                                }
                            }
                            source[k] = "";
                        }
                        inc = k - i;
                    }
                    j -= 1;
                }
            }

            if (!source[i].empty()) {
                ans.push_back(source[i]);
                // cout << source[i] << "\n";
                // return ans;
            }

            i = i + inc;
        }
        return ans;
    }
};

