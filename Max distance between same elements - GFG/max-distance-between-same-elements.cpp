//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        map<int,int>mp;
        int ans=0;
        for(int i = 0;i < n;i++){
            mp[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            //cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
            ans= max(ans,mp[arr[i]]-i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends