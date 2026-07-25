/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;  // empty tree can't contain subRoot
        if (isSameTree(root, subRoot)) return true;  // check current node
        // recursively check left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;   // both null → same
        if (!s || !t) return false;  // one null → not same
        if (s->val != t->val) return false; // values differ
        // check left and right children
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};