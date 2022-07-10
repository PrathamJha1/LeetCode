class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int secondlast=cost[0];
        int last=cost[1];
        int n=cost.size();
        for(int i=2;i<n;i++){
            int x=min(last,secondlast) + cost[i];
            secondlast=last;
            last=x;
        }
        return min(last,secondlast);
    }
};