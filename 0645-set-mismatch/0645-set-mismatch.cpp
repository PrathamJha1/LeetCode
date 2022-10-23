class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        vector<int> ans(2,0);
        for(int i : nums){
            mp[i]++;
        }
        for(int i =1;i<=nums.size();i++){
            if(mp[i] == 2){
                ans[0]=i;
            }
        
            if(mp[i] == 0){
                ans[1]=i;;
            }
        }
        mp.clear();
        return ans;
    }
};