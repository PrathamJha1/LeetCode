class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        int n=words.size();
        
        vector<int>res;
        
        for(int i = 0; i < n; i++){
            mp[words[i]]++;
        }
        
        //Size of each word;
        int m=words[0].size();
        
        if(n*m > s.length()){
            return {};
        }
        
        for(int i=0 ; i + n*m <= s.length(); i++){
            unordered_map<string,int> curr;
            for(int j = 0;j + m <= n*m ;j += m){
                string temp = s.substr(i + j, m);
                curr[temp]++;
            }
            if(curr == mp){
                res.push_back(i);
            }
        }
        return res;
    }
};