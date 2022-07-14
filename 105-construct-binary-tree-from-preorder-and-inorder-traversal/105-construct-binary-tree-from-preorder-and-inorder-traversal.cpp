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
    TreeNode *build(vector<int>preorder,vector<int>inorder,int isi,int ise,int psi,int pse){
        if(isi>ise){
            return NULL;
        }
        int idx=isi;
        while(inorder[idx]!=preorder[psi]){
            idx++;
        }
        int colse=idx-isi;
        TreeNode *node = new TreeNode(preorder[psi]);
        node->left=build(preorder,inorder,isi,idx-1,psi+1,psi + colse);
        node->right=build(preorder,inorder,idx+1,ise,psi+colse+1,pse);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode *root=build(preorder,inorder,0,n-1,0,n-1);
        return root;
    }
};