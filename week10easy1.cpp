#include <vector>
#include <iostream>
using namespace std;


class Node {
public:
     string name;
    Node* left;
    Node* right;

    Node( string name) : name(name), left(nullptr), right(nullptr) {}
};

class FileSystem {
public:
    FileSystem() : root(nullptr) {}

    void add( string name) {
        root = addRecursive(root, name);
    }

    void deleteNode( string name) {
        root = deleteRecursive(root, name);
    }

     vector< string> listFiles() {
         vector< string> files;
        inorderTraversal(root, files);
        return files;
    }

private:
    Node* root;

    Node* addRecursive(Node* node,  string name) {
        if (!node) {
            return new Node(name);
        }

        if (name < node->name) {
            node->left = addRecursive(node->left, name);
        } else {
            node->right = addRecursive(node->right, name);
        }

        return node;
    }

    Node* deleteRecursive(Node* node,  string name) {
        if (!node) {
            return nullptr;
        }

        if (name < node->name) {
            node->left = deleteRecursive(node->left, name);
        } else if (name > node->name) {
            node->right = deleteRecursive(node->right, name);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            node->name = findMin(node->right)->name;
            node->right = deleteRecursive(node->right, node->name);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    void inorderTraversal(Node* node,  vector< string>& files) {
        if (node) {
            inorderTraversal(node->left, files);
            files.push_back(node->name);
            inorderTraversal(node->right, files);
        }
    }
};

int main() {
    FileSystem fs;
    fs.add("file1.txt");
    fs.add("dir1");
    fs.add("file2.txt");

     vector< string> files = fs.listFiles();
    for (const auto& file : files) {
         cout << file << " ";
    }
     cout <<  endl;  // Output: dir1 file1.txt file2.txt

    fs.deleteNode("file1.txt");
    files = fs.listFiles();
    for (const auto& file : files) {
         cout << file << " ";
    }
     cout <<  endl;  // Output: dir1 file2.txt

    return 0;
}
