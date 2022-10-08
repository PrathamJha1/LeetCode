class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int second=i+1;
            int last=n-1;
            while(second < last){
                int sum = nums[i] + nums[second] + nums[last];
                if(sum==0){
                    s.insert({nums[i],nums[second],nums[last]});
                    last--;
                    second++;
                }
                else if(sum>0){
                    last--;
                }
                else{
                    second++;
                }
            }
        }
        vector<vector<int>>ans;
        ans.assign(s.begin(),s.end());
        return ans;
    }
};