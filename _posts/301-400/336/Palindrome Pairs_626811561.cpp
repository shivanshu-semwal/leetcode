bool isPalindrome(string &s, int i, int n) {
    if (i > n) return false;
    while (i < n) {
        if (s[i] != s[n]) return false;
        i++;
        n--;
    }
    return true;
}

class Node {
public:
    vector<Node *> child;
    int isWord;
    vector<int> id;
    Node() : isWord(-1), child(vector<Node *>(26, nullptr)) {}
    void insert(string &word, int izi);
    unordered_set<int> search(string &word);
};

void Node::insert(string &word, int ii) {
    Node *temp = this;
    for (int i = word.length() - 1; i >= 0; i--) {
        int index = word[i] - 'a';
        if (temp->child[index] == nullptr) {
            temp->child[index] = new Node();
        }
        temp = temp->child[index];
        if (isPalindrome(word, 0, i - 1)) {
            temp->id.push_back(ii);
        }
    }
    temp->id.push_back(ii);
    temp->isWord = ii;
}

unordered_set<int> Node::search(string &word) {
    unordered_set<int> ans;
    Node *temp = this;
    int n = word.length();
    for (int i = 0; i < n; i++) {
        int index = word[i] - 'a';

        if (temp->isWord > -1 && isPalindrome(word, i, n - 1)) {
            ans.insert(temp->isWord);
        }
        if (temp->child[index] == nullptr) return ans;
        temp = temp->child[index];
    }
    if (temp->isWord > -1) {
        ans.insert(temp->isWord);
    }
    if (!temp->id.empty()) {
        for (auto i : temp->id) {
            ans.insert(i);
        }
    }
    return ans;
}

vector<int> palindromes(vector<string> &words) {
    vector<int> ans;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] != "" && isPalindrome(words[i], 0, words[i].length() - 1)) {
            ans.push_back(i);
        }
    }
    return ans;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> sol;
        Node n1;
        bool flag = true;
        vector<int> pWords;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "") {
                if (flag) {
                    pWords = palindromes(words);
                    flag = !flag;
                }
            }
            n1.insert(words[i], i);
        }
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "") {
                for (int j = 0; j < pWords.size(); j++) {
                    sol.push_back(vector<int>{i, pWords[j]});
                }
            }
            unordered_set<int> ans = n1.search(words[i]);
            if (!ans.empty()) {
                for (auto x : ans) {
                    if (x != i) {
                        sol.push_back(vector<int>{i, x});
                    }
                }
            }
        }
        return sol;
    }
};
