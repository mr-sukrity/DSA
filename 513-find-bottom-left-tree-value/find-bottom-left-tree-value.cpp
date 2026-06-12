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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
     q.push(root);
     int ans=root->val;

    while(!q.empty()){
        int size=q.size();
        ans=q.front()->val; //leftmost node of current level
        for(int i=0;i<size;i++){
            TreeNode*node=q.front();
            q.pop();

            if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);

        }
    }   
    return ans;
    }
};