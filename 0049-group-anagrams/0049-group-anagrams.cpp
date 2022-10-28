class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<vector<int>,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            string s=strs[i];
            vector<int> temp(26,0);
            for(int j=0;j<s.length();j++){
                temp[s[j]-'a']++;
            }
            mp[temp].push_back(s);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};