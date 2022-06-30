// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void solve(vector<vector<int>> a,int n,int i,int j,string s,vector<vector<int>>&vis){
        if(i==n-1 && j==n-1 && a[i][j]==1){
            ans.push_back(s);
            return ;
        }
        if(i>=n || j>=n || j<0 || i<0 || a[i][j]==0|| vis[i][j]==1 )return;
        
        vis[i][j]=1;
        
        s.push_back('D');
        solve(a,n,i+1,j,s,vis);
        s.pop_back();
        s.push_back('U');
        solve(a,n,i-1,j,s,vis);
        s.pop_back();
        s.push_back('L');
        solve(a,n,i,j-1,s,vis);
        s.pop_back();
        s.push_back('R');
        solve(a,n,i,j+1,s,vis);
        s.pop_back();
        
        vis[i][j]=0;
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]!=0 && m[n-1][n-1]!=0){
            solve(m,n,0,0,s,vis);
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends