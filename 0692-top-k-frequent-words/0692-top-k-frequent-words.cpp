class Solution {
public:
    static bool cmp(pair<int,string>&a,pair<int,string>&b){
        if(a.first == b.first){
            if(a.second<b.second){
                return true;
            }
            else{
                return false;
            }
        }
        else if(a.first>b.first){
            return true;
        }
        else{
            return false;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int>mp;
        vector<string>ans;
        for(string word:words){
            mp[word]++;
        }
        if(mp.size()<k){
            return ans;
        }
        vector<pair<int,string>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};