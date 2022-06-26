class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>>s;
    void f(int idx,vector<int>a,int t,int n,vector<int>&temp){
        if(idx==n){
            if(t==0){
                s.insert(temp);
            }
            return;
        }

        if(a[idx]<=t){
            temp.push_back(a[idx]);
            f(idx,a,t-a[idx],n,temp);
            temp.pop_back();
        }
            f(idx+1,a,t,n,temp);        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> a;
        f(0,candidates,target,n,a);
        ans.assign(s.begin(),s.end());
        return ans;
    }
};