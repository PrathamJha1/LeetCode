class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        vector<int> ans;
        for(int i : nums){
            mp[i]++;
        }
        for(int i =1;i<=nums.size();i++){
            if(mp[i] == 2){
                ans.push_back(i);
            }
        }
        for(int i =1 ;i<=nums.size();i++){
            if(mp[i] == 0){
                ans.push_back(i);
            }
        }
        mp.clear();
        return ans;
    }
};