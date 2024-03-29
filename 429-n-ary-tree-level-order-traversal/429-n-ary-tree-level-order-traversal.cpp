/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> a;
            while(n--){
                Node *curr=q.front();
                q.pop();
                for(Node *child:curr->children){
                    q.push(child);
                }
                a.push_back(curr->val);
            }
            ans.push_back(a);
        }
        return ans;
        
    }
};