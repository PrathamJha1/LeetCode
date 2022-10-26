class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int  n = nums.size();
        int currsum = 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            currsum += nums[i];
            if(currsum % k == 0){
                if(i>0){
                    return true;
                }
            }
            if(mp.find(currsum%k) != mp.end()){
                if(i - mp[currsum % k] > 1){
                    return true;
                }
            }
            else{
                mp[currsum%k] = i;                
            }
        }
        return false;
    }
};