//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    int ans=0;
	    sort(arr,arr+n,greater<int>());
	    for(int i = 0; i < n - 2 ; i++){
	        int first = i;
	        int second = i+1;
	        int third = n-1;
	        while(second < third){
	            if(arr[first] == arr[second] + arr[third]){
	                //cout<<arr[first]<<" "<<arr[second] <<" "<<arr[third]<<endl;
	                ans++;
	            }
	            if(arr[second] + arr[third] > arr[first]){
	                second++;
	            }
	            else{
	                third--;
	            }
	            
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends