class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<0 || j<0 ||i>=n || j>=m || grid[i][j]==0 ){
            return 0;
        }
        int count=0;
        grid[i][j]=0;
        //cout<<i<<" "<<j<<endl;
        count=count + helper(i+1,j,n,m,grid);
        count=count + helper(i,j+1,n,m,grid);
        count=count + helper(i-1,j,n,m,grid);
        count= count + helper(i,j-1,n,m,grid);

        //cout<<endl;
        return count+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   int curr=helper(i,j,n,m,grid);
                    ans=max(curr,ans);
                }
            }
        }
        return ans;
    }
};