//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(int arr[] , int N , int mid, int k){
      int sum = 0 ,count = 0;
      for(int i = 0 ; i < N ; i++){
          if(sum + arr[i] <= mid){
              sum += arr[i];
          }
          else if(arr[i] > mid){
              return false;
          }
          else{
              sum = arr[i];
              count++;
          }
      }
      if(sum > 0){
          count ++;
      }
      return count <= k;
  }
    int splitArray(int arr[] ,int N, int K) {
        int sum = 0;
        for(int i = 0; i < N ; i++){
            sum += arr[i];
        }
        int lo = 0;
        int hi = sum;
        while(lo < hi){
            int mid = (lo + hi)/2;
            //cout<<mid<<"->";
            if(check(arr,N,mid,K)){
                hi = mid ;
            }
            else{
                lo = mid + 1;
            }
            
        }
        return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends