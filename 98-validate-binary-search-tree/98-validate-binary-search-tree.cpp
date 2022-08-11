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
    long long curr = -2147483649;
    bool ans=true;
    void dfs(TreeNode * root){
        if(root==NULL){
            return ;
        }
        dfs(root->left);
        if(root->val <= curr){
            ans=false;
        }
        else{
            curr=root->val;
        }
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        //cout<<curr;
        return ans;
    }
};