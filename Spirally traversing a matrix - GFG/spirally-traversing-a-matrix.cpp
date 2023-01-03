//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>ans;
        int top = 0 , down = r - 1 , left = 0 , right = c-1 , d = 0;
        while(top <= down && left <= right){
            if(d == 0){
                int i = left;
                while(i <= right){
                    ans.push_back(matrix[top][i]);
                    i++;
                }
                top += 1;
            }
            else if(d == 1){
                int i = top;
                while(i <= down){
                    ans.push_back(matrix[i][right]);
                    i++;
                }
                right -= 1;
            }
            else if(d == 2){
                int i = right;
                while(i >= left){
                    ans.push_back(matrix[down][i]);
                    i--;
                }
                down -= 1;
            }
            else{
                int i = down;
                while(i >= top){
                    ans.push_back(matrix[i][left]);
                    i--;
                }
                left += 1;
            }
            d = (d + 1) % 4;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends