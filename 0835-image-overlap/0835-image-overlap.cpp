class Solution {
public:
    int solve(vector<vector<int>> A,vector<vector<int>>B,int i,int j){
        int count=0;
        for(int row=0;row<A.size();row++){
            for(int col=0;col<A.size();col++){
                if((row + i < 0 || row + i >= A.size()) ||(col + j < 0 || col + j >=A.size())){
                    continue;
                }
                else{
                    if(A[row][col]  + B[row + i][col + j] == 2){
                        count++;
                    }
                }
            }
        }
        
        return count;
        
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n=img1.size(),ans=0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                ans = max(ans,solve(img1,img2,i,j));
            }
        }
        return ans;
    }
};