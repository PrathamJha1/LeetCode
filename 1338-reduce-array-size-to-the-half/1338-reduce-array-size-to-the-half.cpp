class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int t=(n)/2;
        map<int,int>mp;
        int x=0,ans=0;
        priority_queue<int>pq;
        for(int i:arr){
            mp[i]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            int top=pq.top();
            //cout<<top<<" ";
            if(x<t){
                x+=top;
                ans++;
            }
            pq.pop();
        }
        return ans;
    }
};