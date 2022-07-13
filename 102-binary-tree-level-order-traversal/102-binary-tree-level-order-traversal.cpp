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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        if(!root)return ans;
        q.push(root);

        while(!q.empty()){
            queue<TreeNode*>cq;
            vector<int>temp;
            while(!q.empty()){
                TreeNode *curr=q.front();
                temp.push_back(curr->val);
                if(curr->left){
                    cq.push(curr->left);
                }
                if(curr->right){
                    cq.push(curr->right);
                }
                q.pop();
            }
            ans.push_back(temp);
            q=cq;
        }
        return ans;
    }
};