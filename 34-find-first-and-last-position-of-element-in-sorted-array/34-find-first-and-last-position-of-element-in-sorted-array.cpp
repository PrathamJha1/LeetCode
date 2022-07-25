class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        vector<int>ans(2,-1);
        if(n==0){
            return ans;
        }
        while(l<r){
            int m=(l+(r-l)/2);
            if(nums[m]>=target){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        ans[0]=nums[l]==target?l:-1;
        if(ans[0]==-1){
            return ans;
        }
        r=n-1;
        while(l<r){
            int m=(l+(r-l)/2)+1;
            if(nums[m]>target){
                r=m-1;
            }
            else{
                l=m;
            }
        }
        ans[1]=nums[r]==target?r:-1;
        return ans;
    }
};