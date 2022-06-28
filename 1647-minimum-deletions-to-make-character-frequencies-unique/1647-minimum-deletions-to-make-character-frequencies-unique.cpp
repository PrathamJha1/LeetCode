class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        int ans=0;
        unordered_map<int,bool>mp;
        vector<int> a(26,0);
        for(char c:s){
            a[c-'a']++;
        }
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<26;i++){
            if(a[i]==0){
                continue;
            }
            else if(mp[a[i]]==true){
                int times=a[i];
                while(times!=0){
                    if(mp[times] && times !=0){
                        ans++;
                        times--;
                    }
                    else{
                        mp[times]=true;
                        break;
                    }
                }
            }
            else{
                mp[a[i]]=true;
            }
        }
        return ans;
        
    }
};