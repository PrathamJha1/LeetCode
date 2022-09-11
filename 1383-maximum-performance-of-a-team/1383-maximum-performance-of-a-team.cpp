class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int mod = 1e9 + 7 ;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({efficiency[i],speed[i]});
        }
        sort(a.begin(),a.end(),greater<>());
        long long sum =0,ans=0;
        for(int i=0;i<n;i++){
            int currSpeed = a[i].second;
            int currEff = a[i].first;
            //cout<<currSpeed<<" "<<currEff<<endl;
            if(pq.size() == k){
                sum-=pq.top();
                pq.pop();
            }
            
            pq.push(a[i].second);
            sum += a[i].second;
            ans = max(ans,sum * currEff) ;
        }
        return ans % mod;
    }
};