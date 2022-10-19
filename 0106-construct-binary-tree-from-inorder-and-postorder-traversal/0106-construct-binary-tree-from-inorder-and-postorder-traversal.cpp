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
    
    TreeNode *buildTree(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int pStart,int pEnd,map<int,int>&mp){
        if(inStart > inEnd || pStart < pEnd)return NULL;
        
        int idx = mp[postorder[pStart]];
        int numsleft = idx - inStart;
        
        TreeNode *root = new TreeNode (postorder[pStart]);
        root->left = buildTree(inorder,postorder,inStart,idx-1,pEnd+numsleft-1,pEnd,mp);
        root->right = buildTree(inorder,postorder,idx+1,inEnd,pStart-1,pEnd+numsleft,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        
        TreeNode *root= buildTree(inorder,postorder,0,n-1,n-1,0,mp);
        return root;
    }
};