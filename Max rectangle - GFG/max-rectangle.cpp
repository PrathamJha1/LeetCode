//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int  getMaxArea(vector<int> arr, int n)
    {
        stack<int>st;
        vector<int > left(n,-1),right (n,n);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        
        for(int i = n - 1;i >= 0 ;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }
        for(int i = 0 ;i < n;i++) {
            //cout<<left[i] <<" "<<right[i] <<" "<<arr[i] << endl;
            int newans = arr[i] * (right[i] - left[i] - 1);
            ans = max(ans,newans);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans = 0 ;
        vector<int> height(m,0);
        for(int i = 0; i < n ;i ++){
            for(int j = 0 ; j < m ;j++){
                if(M[i][j] == 1){
                    height[j]+=1;
                }
                else{
                    height[j]=0;
                }
            }
            ans = max(ans,getMaxArea(height,m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends