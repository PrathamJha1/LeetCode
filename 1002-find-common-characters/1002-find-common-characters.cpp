class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int>v(26,INT_MAX);
        for(int j=0;j<words.size();j++){
            string s=words[j];
            vector<int>a(26,0);
            for(int i=0;i<s.length();i++){
                a[s[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                v[i]=min(a[i],v[i]);
            }
            
        }
        for(int i=0;i<26;i++){
            while(v[i]!=0){
                char x = 'a' + i;
                string y (1,x);
                ans.push_back(y);
                v[i]--;
            }
        }
        return ans;
    }
};