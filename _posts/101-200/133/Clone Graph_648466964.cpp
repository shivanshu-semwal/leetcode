/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void insert(unordered_map<int, pair<Node *, bool>>& m, Node *node){
        Node *temp = m[node->val].first;
        m[node->val] = {temp, true};
        
        //cout << "on node " << node->val << endl;
        
        for(int i=0;i<node->neighbors.size();i++){
            
            //cout << "finding the neighbour " << node->neighbors[i]->val << endl;
            
            if(m.find(node->neighbors[i]->val) != m.end()){
                temp->neighbors.push_back(m[node->neighbors[i]->val].first);
                //cout << "found the neighbour " << node->neighbors[i]->val << endl;
            } else {
                Node *t = new Node(node->neighbors[i]->val);
                m[node->neighbors[i]->val] = {t, false};
                temp->neighbors.push_back(t);
                //cout << "not found the neighbour " <<  node->neighbors[i]->val << endl;
            } 
        }
        
        // now run for it's neighbour
        for(int i=0;i<node->neighbors.size();i++){
            if(! m[node->neighbors[i]->val].second){
                //cout << "recursing the neighbour" << node->neighbors[i]->val << endl;
                insert(m, node->neighbors[i]);
            }            
        }
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<int, pair<Node *, bool>> m; // val, location, isinserted
        
        if(node == NULL) return NULL;
        
        Node *newnode = new Node(node->val);
        m[node->val] = {newnode, true};
        //cout << "inserting node " << node->val << endl;
        
        for(int i=0;i<node->neighbors.size();i++){
            Node *temp = new Node(node->neighbors[i]->val);
            m[node->neighbors[i]->val] = {temp, false};
            newnode->neighbors.push_back(temp);
            //cout << "Inserting neighbour " << node->neighbors[i]->val << endl;
        }
        
        for(int i=0;i<node->neighbors.size();i++){
            //cout << "recursing the neighbour " << node->neighbors[i]->val << endl;
            if(! m[node->neighbors[i]->val].second)
                insert(m, node->neighbors[i]);
        }
        
        return newnode; 
    }
};
