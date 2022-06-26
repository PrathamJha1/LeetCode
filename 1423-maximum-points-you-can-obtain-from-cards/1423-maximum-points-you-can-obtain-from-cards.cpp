class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int sum=0,ans=0,w=n-k;
        int ts=0;
        for(int i:cp){
            ts+=i;
        }
        for(int i=0;i<w;i++){
            sum+=cp[i];
        }
        for(int i=w;i<n;i++){
            cout<<ts<<" "<<sum<<endl;
            ans=max(ans,ts-sum);
            sum-=cp[i-w];
            sum+=cp[i];
        }
        ans=max(ans,ts-sum);
        return ans;
    }
};