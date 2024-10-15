#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    std::string name;
    std::string department; // e.g., "Sales", "Production", "Marketing"
    Employee* left;  // Left child (lower rank)
    Employee* right; // Right child (higher rank)

    Employee(std::string name, std::string department)
        : name(name), department(department), left(nullptr), right(nullptr) {}
};

class Organization {
public:
    Organization() : root(nullptr) {}

    void addEmployee(std::string name, std::string department) {
        root = addRecursive(root, name, department);
    }

    void displayHierarchy() {
        std::cout << "Organization Hierarchy:\n";
        displayRecursive(root, 0);
    }

    Employee* searchHighestSalesEmployee() {
        return searchHighestSalesRecursive(root);
    }

private:
    Employee* root;

    Employee* addRecursive(Employee* node, std::string name, std::string department) {
        if (!node) {
            return new Employee(name, department);
        }

        if (name < node->name) {
            node->left = addRecursive(node->left, name, department);
        } else {
            node->right = addRecursive(node->right, name, department);
        }

        return node;
    }

    void displayRecursive(Employee* node, int level) {
        if (node) {
            displayRecursive(node->right, level + 1); // Higher rank on the right
            for (int i = 0; i < level; i++) std::cout << "   ";
            std::cout << node->name << " (" << node->department << ")\n";
            displayRecursive(node->left, level + 1); // Lower rank on the left
        }
    }

    Employee* searchHighestSalesRecursive(Employee* node) {
        if (!node) return nullptr;

        Employee* highest = nullptr;

        if (node->department == "Sales") {
            highest = node;
        }

        Employee* leftHighest = searchHighestSalesRecursive(node->left);
        Employee* rightHighest = searchHighestSalesRecursive(node->right);

        if (leftHighest && (!highest || leftHighest->name > highest->name)) {
            highest = leftHighest;
        }

        if (rightHighest && (!highest || rightHighest->name > highest->name)) {
            highest = rightHighest;
        }

        return highest;
    }
};

int main() {
    Organization org;

    // Adding employees
    org.addEmployee("Alice", "Sales");
    org.addEmployee("Bob", "Production");
    org.addEmployee("Charlie", "Marketing");
    org.addEmployee("David", "Sales");
    org.addEmployee("Eve", "Production");

    // Displaying the hierarchy
    org.displayHierarchy();

    // Searching for the highest-ranked employee in Sales
    Employee* highestSalesEmployee = org.searchHighestSalesEmployee();

    if (highestSalesEmployee) {
        std::cout << "\nHighest-ranked employee in Sales: "
                  << highestSalesEmployee->name << "\n";
    } else {
        std::cout << "\nNo employees found in Sales.\n";
    }

    return 0;
}
