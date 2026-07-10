/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mpp;
    void in(TreeNode *root){
        if(!root) return;

        if(root->left) mpp[root->left] = root;
        in(root->left);

        if(root->right) mpp[root->right] = root;
        in(root->right);
    }

    void BFS(TreeNode *tar, int k, vector<int> &ans){
        queue<TreeNode *> q;
        q.push(tar);

        unordered_set<int> vis;
        vis.insert(tar->val);

        while(!q.empty()){
            int n = q.size();

            if(!k) break;

            while(n--){
                TreeNode *curr = q.front();
                q.pop();

                if(curr->left && !vis.count(curr->left->val)){
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }

                if(curr->right && !vis.count(curr->right->val)){
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }

                if(mpp.count(curr) && !vis.count(mpp[curr]->val)){
                    q.push(mpp[curr]);
                    vis.insert(mpp[curr]->val);
                }
            }

            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        in(root);

        vector<int> ans;
        BFS(target, k, ans);

        return ans;
    }
};