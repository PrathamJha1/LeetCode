class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    void f(int idx,int n,vector<int>a,vector<int>&x,int t,int k){
        if(idx==n){
            if(t==0 && k==0){
                s.insert(x);
            }
            return;
        }
        if(k<0){
            return;
        }
        if(t<0){
            return;
        }
        x.push_back(a[idx]);
        f(idx+1,n,a,x,t-a[idx],k-1);
        x.pop_back();
        
        f(idx+1,n,a,x,t,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a(10);
        for(int i=1;i<=9;i++){
            a[i]=i;
        }
        vector<int> temp;
        f(1,a.size(),a,temp,n,k);
        ans.assign(s.begin(),s.end());
        return ans;
    }
};