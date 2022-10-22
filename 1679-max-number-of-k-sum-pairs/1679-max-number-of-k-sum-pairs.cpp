class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        for(int i=0;i<n;i++){
            int rem = k - nums[i];
            if(rem == nums[i]){
                int times= mp[rem];
                ans+=times/2;
                mp[rem]=times%2;
            }
            else if(mp[rem]!=0){
                int mini = min(mp[nums[i]],mp[rem]);
                mp[rem]-=mini;
                mp[nums[i]]-=mini;
                ans+=mini;
            }
        }
        return ans;
    }
};