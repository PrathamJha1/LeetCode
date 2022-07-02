class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        long long  mh=max(hC[0],h-hC[hC.size()-1]),mw=max(vC[0],w-vC[vC.size()-1]), ans;
        for(int i=0;i<hC.size()-1;i++){
            mh=max((int)mh,hC[i+1]-hC[i]);
        }
        for(int i=0;i<vC.size()-1;i++){
            mw=max((int)mw,vC[i+1]-vC[i]);
        }
        ans=mh*mw;
        return (ans)%1000000007;
    }
};