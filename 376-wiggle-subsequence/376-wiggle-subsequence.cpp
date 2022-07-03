class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up=0,dO=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])up=dO+1;
            else if(nums[i]<nums[i-1]){
                dO=up+1;
            }
        }
        return max(up,dO) +1;
    }
};