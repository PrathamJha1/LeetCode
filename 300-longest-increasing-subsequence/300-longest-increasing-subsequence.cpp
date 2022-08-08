class Solution {
public:
    int solve(vector<int>&nums,int i,int n,int lastidx,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(lastidx!=-1 && dp[i][lastidx]!=-1){
            return dp[i][lastidx];
        }
        int ans=0;
        if(lastidx == -1 || nums[lastidx] <nums[i]){
            ans=1+solve(nums,i+1,n,i,dp);
        }
        ans=max(ans,solve(nums,i+1,n,lastidx,dp));
        if(lastidx==-1){
            return dp[i][i]=ans;
        }
        return dp[i][lastidx]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(nums,0,n,-1,dp);
        return ans;
    }
};