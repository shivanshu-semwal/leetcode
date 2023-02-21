/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> m;
    
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *t = new Node(head->val);
        Node *tt = t;
        m[head] = t;
        m[NULL] = NULL;
        while(head){
            if(m.find(head->next) == m.end()){
                 m[head->next] = new Node(head->next->val);
            }
            if(m.find(head->random) == m.end()){
                m[head->random] = new Node(head->random->val);
            }
            t->next = m[head->next];
            t->random = m[head->random];
            t = t->next;
            head = head->next;
        }
        return tt;
    }
};
