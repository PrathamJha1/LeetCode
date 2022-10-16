class Solution {
public:
    int solve(int idx,int 
              days,vector<int>&jobs,vector<vector<int>>&dp){
        //base case
        if(days==0){
            if(idx<jobs.size())return 1e5;
            return 0;
        };
        
        //check the cache
        if(dp[idx][days]!=-1)
            return dp[idx][days];
        
        int mini=INT_MAX;
        int curr_max=-1;
        for(int i=idx;i<=jobs.size()-days;i++){
            curr_max=max(curr_max,jobs[i]);
            int curr= curr_max + solve(i+1,days-1,jobs,dp);
            mini=min(mini,curr);
        }
        return dp[idx][days] =  mini;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        if(jobs.size()<d)
            return -1;
        int n=jobs.size();
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return solve(0,d,jobs,dp);
    }
};