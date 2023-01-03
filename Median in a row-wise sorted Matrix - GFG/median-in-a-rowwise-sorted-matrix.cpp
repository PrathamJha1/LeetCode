//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int check (vector<vector<int>>mat,int mid){
        int count = 0;
        for(int i = 0 ; i < mat.size() ; i++){
            int lo = 0 , hi = mat[i].size()-1;
            while(lo <= hi){
                int m = (lo + hi)/2;
                if(mat[i][m] <= mid){
                    lo = m + 1;
                }
                else{
                    hi = m - 1;
                }
            }
            count += lo;
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int lo = 1 , hi = 2001;
        while(lo <= hi){
            int mid = (lo + hi) / 2 ;
            //cout<<mid<<" ";
            int c = check(matrix,mid);
            if(c > (R * C) / 2){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends