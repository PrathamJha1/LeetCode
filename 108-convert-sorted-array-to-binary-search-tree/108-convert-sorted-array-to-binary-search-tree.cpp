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
TreeNode *construct(vector<int> arr, int lo, int hi){
    if (lo > hi)
    {
        return NULL;
    }
    int mid = (hi + lo) / 2;
    int val = arr[mid];
    TreeNode *l = construct(arr, lo, mid - 1);
    TreeNode *r = construct(arr, mid + 1, hi);
    TreeNode *newnode = new TreeNode();
    newnode->val = val;
    newnode->left = l;
    newnode->right = r;
    return newnode;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};