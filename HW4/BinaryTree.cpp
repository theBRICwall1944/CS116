// BinaryTree.cpp
// Submit only this file. Do NOT add a main() here.

#include <vector>
#include <queue>
#include <iostream>

class BinaryTree {
public:
    using Value = int; // node value type

    BinaryTree() : root_(nullptr) {}
    ~BinaryTree() { clear(root_); }
    void buildFromTraversals(const std::vector<Value>& inorder,
                             const std::vector<Value>& preorder);

    void printLevels(std::ostream& os = std::cout) const;

private:
    struct Node {
        Value val;
        Node* left;
        Node* right;
        explicit Node(Value v) : val(v), left(nullptr), right(nullptr) {}
    };

    Node* root_;

    static void clear(Node* n) {
        if (!n) return;
        clear(n->left);
        clear(n->right);
        delete n;
    }
};

// ============ Implement ONLY the two functions below ============

void BinaryTree::buildFromTraversals(const std::vector<Value>& inorder,
                                     const std::vector<Value>& preorder) {
    // TODO: build the tree from traversals and assign to root_.

    // Types: inorder/preorder are std::vector<int>.
    // Replace any existing tree (delete old nodes first if needed).
    (void)inorder; (void)preorder; // remove after implementing
}

void BinaryTree::printLevels(std::ostream& os) const {
    // TODO: print level-order with "NULL" placeholders as specified.

    // This function also counts for Question 5
    (void)os; // remove after implementing
}