class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int count=1;
        int mc=0;
        vector<int> v;
        v.assign(s.begin(),s.end());
        int temp=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]== temp+1){
                count++;
            }
            else{
                mc=max(mc,count);
                count=1;
            }
            temp=v[i];
        }
        mc=max(mc,count);
        return mc;
    }
};