class Solution {
public:
    int countAsterisks(string s) {
        int n=s.length();
        bool f=false;
        int ans=0;
        int k=0;
        while(k<n && s[k]!='|'){
            if(s[k]=='*'){
                ans++;
            }
            k++;
        }
        for(int i=0;i<n;){
            if(s[i]=='|'){
                int count=0;
                int j=i+1;
                while( j<n && s[i]!=s[j]){
                    if(s[j]=='*')count++;
                    j++;
                }
                i=j;
                if(f){
                    ans+=count;
                }
                f=!f;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};