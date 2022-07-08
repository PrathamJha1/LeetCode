class Solution {
public:
    long long dp[109][109][39];
    vector<vector<int>>cost;
    vector<int> h;
    int n, m;
    int target;
    long long solve(int idx,int nums,int prev){
        if(nums>target)return INT_MAX;
        
        if(idx==m){
            return nums==target?0:INT_MAX;
        }
        if(dp[idx][nums][prev]!=-1){
            return dp[idx][nums][prev];
        }
        long long ans=INT_MAX;
        int new_nums=nums;
        
        if(h[idx]!=0){
            if(prev!=h[idx]){
                new_nums=nums+1;
            }
            ans=min(ans,solve(idx+1,new_nums,h[idx]));
        }
        else{
            for(int i=1;i<=n;i++){
                new_nums=nums;
                if(prev!=i){
                    new_nums=nums+1;
                }
            ans=min(ans,solve(idx+1,new_nums,i)+ cost[idx][i-1]);
            }
        }
        return dp[idx][nums][prev]=ans;
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->h=houses;
        this->cost=cost;
        this->n=n;
        this->m=m;
        this->target=target;
        memset(dp,-1,sizeof(dp));
        long long  ans=solve(0,0,29);
        return ans==INT_MAX ? -1:ans;
    }
};