#include <iostream>
#include <queue>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void printChild(TNode *node) {
    if (node != NULL) {
        cout << "Anak Dari " << node->data << " : ";
        if (node->left != NULL) {
            cout << node->left->data << " ";
        }
        if (node->right != NULL) {
            cout << node->right->data << " ";
        }
        if (node->left == NULL && node->right == NULL) {
            cout << "Tidak Ada Anak.";
        }
        cout << endl;
    }
}

void printDescendant(TNode *node) {
    if (node != NULL) {
        if (node->left != NULL || node->right != NULL) {
            cout << "Turunan Dari " << node->data << " : ";
            queue<TNode*> q;
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            while (!q.empty()) {
                TNode* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            cout << endl;
        } else {
            cout << "Turunan Dari " << node->data << " : Tidak Ada Turunan." << endl;
        }
    }
}

TNode* findNode(TNode* node, int value) {
    if (node == NULL) return NULL;
    if (node->data == value) return node;
    TNode* foundNode = findNode(node->left, value);
    if (foundNode == NULL) {
        foundNode = findNode(node->right, value);
    }
    return foundNode;
}

int main() {
    int n;
    cout << "Masukkan Jumlah Node : ";
    cin >> n;

    TNode *root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Masukkan Nilai Node " << i + 1 << " : ";
        cin >> value;

        TNode *node = new TNode(value);

        if (root == NULL) {
            root = node;
        } else {
            // Temukan Node Induk
            int parentValue;
            cout << "Masukkan Node Induk Dari " << value << " : ";
            cin >> parentValue;
            TNode *parent = findNode(root, parentValue);
            if (parent == NULL) {
                cout << "Node Induk Tidak Dapat Ditemukan!" << endl;
                delete node;
                i--;
                continue;
            }
            if (parent->left == NULL) {
                parent->left = node;
            } else if (parent->right == NULL) {
                parent->right = node;
            } else {
                cout << "Node Induk Sudah Memiliki Dua Anak!" << endl;
                delete node;
                i--;
            }
        }
    }

    cout << "\nTraversal Pre-Order      : ";
    preOrder(root);
    cout << endl;

    cout << "Traversal In-Order       : ";
    inOrder(root);
    cout << endl;

    cout << "Traversal Post-Order     : \n";
    postOrder(root);
    cout << endl;

    for (int i = 0; i < n; i++) {
        printChild(findNode(root, i + 1));
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        printDescendant(findNode(root, i + 1));
    }
    cout << endl;

    return 0;
}