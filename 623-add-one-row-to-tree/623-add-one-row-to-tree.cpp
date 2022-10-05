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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *newRoot= new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
            int d=1;
            queue<TreeNode *>q;
            q.push(root);
            int f=0;
            while(!q.empty()){
                
                int s=q.size();
                while(s--){        
                    TreeNode *x = q.front();
                    q.pop();
                    if(d == depth - 1){
                        f++;
                        //cout<<("HHHH");
                        TreeNode *a = new TreeNode(val);
                        TreeNode *b = new TreeNode(val);
                        a->left = x->left;
                        x->left=a;
                        b->right=x->right;
                        x->right=b;

                    }
                    if(x->left)q.push(x->left);
                    if(x->right)q.push(x->right);
                }
                if(f) break;
            d++;
        }
        return root;
    }
};