//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int currsum=0;
        int res=0;
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            currsum += Arr[i];
            if(currsum == k){
                res++;
            }
            
            if(mp.find(currsum - k)!=mp.end()){
                res += mp[currsum - k];
            }
            
            mp[currsum] ++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends