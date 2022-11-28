//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int> ans,temp={-1};
	    vector<int>nums;
	    int currsum=0,maxsum=0;
	    bool edge=false;
	    for(int i=0;i<=n;i++){
	        if(i<n && a[i]>=0){
	            currsum+=a[i];
	            nums.push_back(a[i]);
	        }
	        else if(i==n || a[i]<0){
	            if(currsum > maxsum){
	                maxsum=currsum;
	                ans=nums;
	                edge=false;
	            }
	            nums.clear();
	            currsum=0;
	            continue;
	        }
	    }
	    return ans.size()==0?temp:ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends