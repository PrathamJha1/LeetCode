class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        int ans=0;
        for(string i : words){
            m[i]++;
        }
        bool f=false;
        for(string i:words){
            char c1=i[0];
            char c2=i[1];
            //cout<<i<<" "<<ans<<"\n";
            if(c1==c2){
                if(m[i]%2==0){
                    ans+=2*m[i];
                    m[i]=0;
                }
                else{
                    if(f==false){
                        ans+=2*m[i];
                        f=true;
                        m[i]=0;
                    }
                    else{
                        ans+=2*(m[i]-1);
                        m[i]=1;
                    }
                    
                }
            }
            else{
                string t = i;
                reverse(t.begin(),t.end());
                if(m[t] > 0 && m[i]>0){
                    m[t]--;
                    m[i]--;
                    ans+=4;
                }
            }
        }
        return ans;
    }
};