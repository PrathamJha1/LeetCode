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
    bool pruningTree(TreeNode* root){
        if(root == nullptr) return false;
        bool isLeft = pruningTree(root->left);
        if(!isLeft){
            root->left = nullptr;
        }
        bool isRight = pruningTree(root->right);
        if(!isRight){
            root->right = nullptr;
        }
        
        if(isLeft || isRight || root->val ==1){
            return true;
        }
        else{
            return false;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
       return pruningTree(root)? root : nullptr;
    }
};