//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            for(int j=i;j<=n;j++){
                int maxi=-1,mini=-1;
                for(int k=0;k<26;k++){
                    if(temp[k] != 0){
                        if(maxi == -1){
                            maxi = temp[k];   
                        }
                        if(mini == -1){
                            mini =temp[k];
                        }
                        else if(maxi < temp[k]){
                            maxi=temp[k];
                        }
                        else if(mini > temp[k]){
                            mini=temp[k];
                        }
                    }
                }
                //cout<<i<< " "<<j<<" "<<maxi<<" "<<mini<<" "<<ans<<endl;
                if(j<n){
                    temp[s[j]-'a']++;
                }
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends