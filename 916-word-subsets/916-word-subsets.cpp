class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      int fin[26] = {0};
      for(auto &word : words2){
          int temp[26]={0};
            for(char ch : word){
              temp[ch-'a']++;
              fin[ch-'a']=max(fin[ch-'a'], temp[ch-'a']);
            }
      }
      vector<string> ans;
      for(auto &word : words1){
        int temp[26]={0};
        for(auto ch : word)
          temp[ch-'a']++;
        bool chk=true;
        for(int i=0; i<26; i++)
          if(fin[i]!=0 and temp[i]<fin[i]){
            chk=false;
            break;
          }
        if(chk) ans.push_back(word);
      }
      return ans;
    }
};