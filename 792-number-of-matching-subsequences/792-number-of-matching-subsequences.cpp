class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i= 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        int count=0;
        for(auto x : mp){
            string s1 = x.first;
            int n = s1.size();
            int i = 0, j = 0;
            while(i < n && j < s.size()){
                if(s1[i] == s[j]){
                    i++;
                }
                j++;
            }
            if(i == n){
                count += x.second;   
            }
        }
        
        return count;
    }
};