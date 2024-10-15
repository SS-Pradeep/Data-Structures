#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node()
    {
        data=0;
        left=right=NULL;
    }
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert1(Node* node, int val) {
    if (!node) {
            return new Node(val);
        }
    if (val <= node->data) {
        node->left = insert1(node->left, val);
    } else if (val > node->data) {
            node->right = insert1(node->right, val);
        }
        return node;
    }

Node* delete1(Node* node) {
        if (!node) return nullptr;

        node->left = delete1(node->left);
        node->right = delete1(node->right);

        if (node->left && node->left->data == node->data) {
            Node* temp = node->left;
            node->left = temp->left;
            delete temp;
        }
        if (node->right && node->right->data == node->data) {
            Node* temp = node->right;
            node->right = temp->right;
            delete temp;
        }
        return node;
    }

Node* ances(Node* node, int n1, int n2) {
        if (!node) return nullptr;
        if (node->data > n1 && node->data > n2) {
            return ances(node->left, n1, n2);
        }
        if (node->data < n1 && node->data < n2) {
            return ances(node->right, n1, n2);
        }
        return node; // This node is the LCA
    }

Node* findMin(Node* node) {
        if (!node || !node->left) {
            return node;
        }
        return findMin(node->left);
    }

int count1(Node* root) {
    if(!root)
        return 0;

    int l = count1(root->left);
    int r = count1(root->right);

    return 1 + l + r;
    }
void inorder(Node *node){
    if(!node)
        return;

    inorder(node->left);
    cout<<node->data<<" ";

    inorder(node->right);
}
int main() {
    Node *root = new Node();
    int choice, val, n1, n2;
    Node *lca = nullptr;
    Node *tep=NULL;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Delete duplicates\n";
        cout << "3. Find LCA of two nodes\n";
        cout << "4. Find minimum value in BST\n";
        cout << "5. Count nodes in BST\n";
        cout << "6. Diaplay\n";
        cout << "7.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert1(root,val);
                break;
            case 2:
                root = delete1(root);
                cout << "Duplicates deleted.\n";
                break;
            case 3:
                cout << "Enter first node value: ";
                cin >> n1;
                cout << "Enter second node value: ";
                cin >> n2;
                lca = ances(root,n1,n2);
                if (lca) {
                    cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
                } else {
                    cout << "LCA not found.\n";
                }
                break;
            case 4:
                tep = findMin(root);
                if (tep->data != -1) {
                    cout << "Minimum value in the BST is: " << tep->data << endl;
                } else {
                    cout << "The BST is empty.\n";
                }
                break;
            case 5:
                cout << "Number of nodes in the BST: " << count1(root) << endl;
                break;
            case 6:
                inorder(root);
                break;
            case 7:
                cout<<"Exit/n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

