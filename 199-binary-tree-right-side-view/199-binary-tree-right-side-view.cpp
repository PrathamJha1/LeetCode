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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.back()->val);
            //cout<<q.back()->val<<" ";
            queue<TreeNode *>cq;
            while(n--){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left != NULL){
                    cq.push(curr->left);                    
                }
                if(curr->right!=NULL){
                    cq.push(curr->right);
                }
            }
            q=cq;
        }
        return ans;
    }
};