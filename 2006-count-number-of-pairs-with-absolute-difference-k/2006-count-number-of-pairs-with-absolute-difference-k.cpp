class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(),ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[nums[i] + k] != 0){
                ans += mp[nums[i] + k];
            }
        }
        return ans;
    }
};