class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int k=0;k<n;k++){
                    sum+=matrix[k][j]-(i==0 ? 0 : matrix[k][i-1]);
                    count+=mp[sum-target];
                    mp[sum]+=1;
                }
            }
        }
        return count;
    }
};