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
    int count = 0;
    int solve(TreeNode *root){
        if(!root) return INT_MIN;

        int leftmax = solve(root->left);
        int rightmax = solve(root->right);

        int mx = max({root->val, leftmax, rightmax});

        if(root->val == mx) count++;

        return mx;
    }
    
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return count;
    }
};