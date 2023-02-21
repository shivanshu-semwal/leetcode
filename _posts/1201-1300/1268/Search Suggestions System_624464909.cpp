class Node {
public:
    vector<Node *> child;
    bool isEndOfWord;
    string word;
    Node() {
        isEndOfWord = false;
        child = vector<Node *>(26, nullptr);
    }
    void insert(string &word);
    vector<vector<string>> search1(string word);
};

void Node::insert(string &word) {
    Node *temp = this;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (temp->child[index] == nullptr) {
            temp->child[index] = new Node();
        }
        temp = temp->child[index];
    }
    temp->isEndOfWord = true;
    temp->word = word;
}

void dfs(Node *root, int limit, vector<string> &result) {
    if (root == nullptr) return;
    if(result.size() == limit) return;
    if(root->isEndOfWord) result.push_back(root->word);
    for(int i=0;i<26;i++){
        if(root->child[i] != nullptr){
            dfs(root->child[i], limit, result);
        }
    }
}

vector<vector<string>> Node::search1(string word) {
    int n = word.length();
    vector<vector<string>> sol(n);
    Node *temp = this;
    for (int i = 0; i < n; i++) {
        int index = word[i] - 'a';
        if (temp->child[index] == nullptr) {
            break;
        }
        temp = temp->child[index];
        vector<string> result;
        dfs(temp, 3, result);
        sol[i] = result;
    }
    return sol;
}


class Solution {
public:
    vector<vector<string>>
    suggestedProducts(vector<string> &products, string searchWord) {
        Node n1;
        // inseting string in tire
        for (int i = 0; i < products.size(); i++) {
            n1.insert(products[i]);
        }
        return n1.search1(searchWord);
    }
};
