class Node {
public:
    Node *left, *right;
    int height;
    pair<int, int> key;
    Node(pair<int, int> x) : left(nullptr), right(nullptr), key(x), height(1) {}
};

int height(Node *t) { return (t == nullptr) ? 0 : t->height; }

int getBalance(Node *t) { return (t == nullptr) ? 0 : (height(t->left) - height(t->right)); }

Node *rightRotation(Node *b) {
    Node *a = b->left;
    Node *tree2 = a->right;
    a->right = b;
    b->left = tree2;
    b->height = max(height(b->left), height(b->right) + 1);
    a->height = max(height(a->left), height(a->right) + 1);
    return a;
}

Node *leftRotation(Node *a) {
    Node *b = a->right;
    Node *tree2 = b->left;
    b->left = a;
    a->right = tree2;
    a->height = max(height(a->left), height(a->right) + 1);
    b->height = max(height(b->left), height(b->right) + 1);
    return b;
}

Node *insert(Node *root, pair<int, int> key) {
    if (root == nullptr) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    /* left left case */
    if (balance > 1 && key < root->left->key) return rightRotation(root);
    /* right right case */
    if (balance < -1 && key > root->right->key) return leftRotation(root);
    /* left right case */
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    /* right left case */
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

pair<int, int> *upper_bound(Node *root, int start, pair<int, int> *ans = nullptr) {
    if (root == nullptr) return ans;

    /* right side */
    if (start < (root->key).first) {
        ans = &(root->key);
        // cout << "up: " << root->key.first << "," << root->key.second << "\n";
        return upper_bound(root->left, start, ans);
    } else {
        return upper_bound(root->right, start, ans);
    }
}

class MyCalendar {
public:
    Node *root;
    MyCalendar() : root(nullptr) {}

    bool book(int start, int end) {
        pair<int, int> *it = upper_bound(root, start);
        // if (it == nullptr)
        //     cout << "nullptr found\n";
        // else
        //     cout << (*it).first << " , " << (*it).second << "\n";
        if (it == nullptr || (*it).second >= end) {
            root = insert(root, {end, start});
            return true;
        }
        return false;
    }
};

