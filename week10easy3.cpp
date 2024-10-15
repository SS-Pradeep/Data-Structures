#include <iostream>
#include <string>
#include <vector>

class FamilyMember {
public:
    std::string name;
    FamilyMember* left;  // Left child (first child or spouse)
    FamilyMember* right; // Right child (second child or spouse)

    FamilyMember(std::string name)
        : name(name), left(nullptr), right(nullptr) {}
};

class FamilyTree {
public:
    FamilyTree() : root(nullptr) {}

    void addMember(std::string name) {
        root = addRecursive(root, name);
    }

    void findAncestors(std::string name) {
        std::vector<std::string> ancestors;
        if (findAncestorsRecursive(root, name, ancestors)) {
            std::cout << "Ancestors of " << name << ": ";
            for (const auto& ancestor : ancestors) {
                std::cout << ancestor << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << name << " not found in the family tree." << std::endl;
        }
    }

    void displayFamily() {
        std::cout << "Family Relationships:\n";
        displayRecursive(root, 0);
    }

private:
    FamilyMember* root;

    FamilyMember* addRecursive(FamilyMember* node, std::string name) {
        if (!node) {
            return new FamilyMember(name);
        }

        if (name < node->name) {
            node->left = addRecursive(node->left, name);
        } else {
            node->right = addRecursive(node->right, name);
        }

        return node;
    }

    bool findAncestorsRecursive(FamilyMember* node, std::string name, std::vector<std::string>& ancestors) {
        if (!node) return false;

        // Check if the current node is the target member
        if (node->name == name) return true;

        // If the member is found in the left or right subtree
        if (findAncestorsRecursive(node->left, name, ancestors) ||
            findAncestorsRecursive(node->right, name, ancestors)) {
            ancestors.push_back(node->name); // Add current node to ancestors
            return true;
        }

        return false; // Not found in either subtree
    }

    void displayRecursive(FamilyMember* node, int level) {
        if (node) {
            displayRecursive(node->right, level + 1); // Higher rank on the right
            for (int i = 0; i < level; i++) std::cout << "   ";
            std::cout << node->name << "\n";
            displayRecursive(node->left, level + 1); // Lower rank on the left
        }
    }
};

int main() {
    FamilyTree family;

    // Adding family members
    family.addMember("John");
    family.addMember("Alice");
    family.addMember("Bob");
    family.addMember("Charlie");
    family.addMember("Diana");

    // Displaying family relationships
    family.displayFamily();

    // Finding ancestors of a specific member
    family.findAncestors("Charlie");

    return 0;
}
