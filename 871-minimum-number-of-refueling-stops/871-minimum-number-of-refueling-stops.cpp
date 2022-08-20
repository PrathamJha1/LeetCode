class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans,i=0;
        for(ans=0;target>startFuel;ans++){
            while(i<stations.size() && stations[i][0]<=startFuel){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())return -1;
            startFuel+=pq.top();
            pq.pop();
        }
        return ans;
    }
};