class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[0] + nums[1] + nums[2],diff=INT_MAX;
        for(int i =0;i<n-2;i++){
            int first=i;
            int second=i+1;
            int last=n-1;
            while(second<last)
            {
                int sum = nums[first] + nums[second]  + nums[last];
                int mindiff= abs(target - sum);
                if(mindiff<diff){
                    ans=sum;
                    diff=mindiff;
                }
                if(sum>target){
                    last--;
                }
                else{
                    second++;
                }
            }
        }
        return ans;
    }
};