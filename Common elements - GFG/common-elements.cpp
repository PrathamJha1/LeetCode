//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            map<int,int>mp;vector<int>ans;
            for(int i = 0 ; i < n1 ;i++){
                mp[A[i]] = 1;
            }
            for(int j = 0; j < n2 ;j++){
                if(mp[B[j]] == 1){
                    mp[B[j]] = 2;
                }
            }
            for(int j = 0; j < n3 ;j++){
                if(mp[C[j]] == 2){
                    mp[C[j]] = 3;
                }
            }
            for(auto it:mp){
                if(it.second == 3){
                    ans.push_back(it.first);
                }
            }
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends