/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node *top=NULL, *prev=NULL;
        queue<Node *> q;
        vector<Node *> pp;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            prev = top;
            top = q.front();

            // pp.push_back(q.front());
            q.pop();
            
            if(prev!=NULL){
                prev->next = top;
            }
            
            if (top == NULL) {
                if (!q.empty()) q.push(NULL);
                continue;
            } else if (top->right != NULL) {
                q.push(top->left);
                q.push(top->right);
            } else if (top->left != NULL) {
                q.push(top->left);
            }
        }

        // for (int i = 0; i < pp.size() - 1; i++) {
        //     if (pp[i] == NULL) continue;
        //     pp[i]->next = pp[i + 1];
        // }

        return root;
    }
};
