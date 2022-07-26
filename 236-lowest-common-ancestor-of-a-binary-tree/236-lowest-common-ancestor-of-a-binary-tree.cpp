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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, int &found) {
        found = 0;
        if (root == p) found |= 1;
        if (root == q) found |= 2;
        int found1 = 0;
        int found2 = 0;
        TreeNode* lowest = nullptr;
        if (root->left)
        {
            lowest = lowestCommonAncestor(root->left,p,q,found1);
            if (lowest != nullptr)  return lowest;
            found |= found1;
            if (found == 3) return root;
        }
        if (root->right)
        {
            lowest = lowestCommonAncestor(root->right,p,q,found2);
            if (lowest != nullptr)  return lowest;
            found |= found2;
            if (found == 3) return root;
        }
        return lowest;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int found;
        return lowestCommonAncestor(root,p,q,found);
    }
};