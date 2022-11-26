//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    
   Node *treeFromString(string str){
        // code here
    
        stack<int> stk;
        map<int, Node*> mp;
        
        
        for(int i = 0; i < str.length(); i++) {
            
            if(str[i] == ')') {
                
                int child = stk.top();
                Node* chd;
                if(mp.find(child) == mp.end())
                    chd = new Node(child);
                else 
                    chd = mp[child];
                    
                stk.pop(); stk.pop();
                
                int parent = stk.top();
                
                if(mp.find(parent) == mp.end()) {
                    Node* par = new Node(parent);
                    par->left = chd;
                    mp[parent] = par;
                }
                else {
                    Node* par = mp[parent];
                    par->right = chd;
                }
            }
            else {
                int num = 0;
                if(str[i] == '(') {
                    stk.push(-1);
                }
                else {
                    while(isdigit(str[i])) {
                        num = num*10 + (str[i]-'0');
                        i++;
                    }
                    i--;
                    stk.push(num);
                }
                
            }
            
        }
        if(mp.size() == 0) return new Node(stk.top());
        return mp[stk.top()];
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends