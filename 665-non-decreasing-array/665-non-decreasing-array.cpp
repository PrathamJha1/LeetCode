class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int c=0,prev=0;
       for(int i=0;i<n-1;i++){
           if(nums[i]<=nums[i+1]){
               prev=nums[i];
               continue;
           }
           if(nums[i+1]>=prev){
               nums[i]=nums[i+1];
           }
           else{
               nums[i+1]=nums[i];
           }
           prev=nums[i];
           c++;
       }
        return c<2;
    }
};