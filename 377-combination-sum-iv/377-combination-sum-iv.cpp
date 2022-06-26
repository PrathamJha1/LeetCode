class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<uint> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j:nums){
                if(j<=i){
                    dp[i]+=dp[i-j];
                }
            }
        }

        return dp[target];
    }
};