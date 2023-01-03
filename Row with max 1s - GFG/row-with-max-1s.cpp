//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans = -1,maxcount=0;
	    for(int i = 0; i < n; i++){
	        int count = 0;
	        int lo = 0 , hi = m - 1;
	        while(lo <= hi){
	            int mid = (lo + hi)/2;
	            if(arr[i][mid] == 0){
	                lo = mid + 1;
	            }
	            else{
	                hi = mid - 1;
	            }
	        }
	        
	        count  = m - lo;
	        if(count > maxcount){
	            maxcount = count;
	            ans = i;
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
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends