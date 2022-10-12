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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> Q;
        vector<vector<int>> res;
        unordered_map<int , vector<int>> hmap; 
        int mi = INT_MAX, mx = INT_MIN; 

        if(root) Q.push({root, 0});
        while(!Q.empty()){
            int n = Q.size();
            multiset<pair<int, int>> tmp;
            while(n--){
                auto [node, x] = Q.front(); Q.pop();
                tmp.insert({node->val, x});
                mi = min(mi, x); mx = max(mx, x);
                if(node->left) Q.push({node->left, x-1});
                if(node->right) Q.push({node->right, x+1});
            }
            for(auto& [val, x]: tmp) hmap[x].push_back(val);
        }

        for(int i = mi; i <= mx; ++i) res.push_back(move(hmap[i]));
            return res;
    }
    
};