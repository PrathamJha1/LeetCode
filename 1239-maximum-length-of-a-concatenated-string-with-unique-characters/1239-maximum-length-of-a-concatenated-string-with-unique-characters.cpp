class Solution {
public:
    int ans=0;
    bool check(string s,string t){
        vector<int>mp(26,0);
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            if(mp[t[i]-'a']){
                return false;
            }
            mp[t[i]-'a']++;
        }
        return true;
    }
    void solve(int idx,vector<string>arr,int currans,string s){
        if(idx == arr.size()){
            ans=max(ans,currans);
            return;
        }
        if(check(s,arr[idx])){
            solve(idx+1,arr,currans + arr[idx].size(),s + arr[idx]);
        }
        solve(idx+1,arr,currans,s);
    }
    int maxLength(vector<string>& arr) {
        solve(0,arr,0,"");
        return ans;
    }
};