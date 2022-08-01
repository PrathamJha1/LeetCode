class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for(int j=0;j<n;j++){
            prev[j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    curr[j]=prev[j];
                }
                else{
                    curr[j]=prev[j] + curr[j-1];
                }
                
            }
            prev=curr;
        }
        return prev[n-1];
    }
};