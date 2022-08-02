class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int row= m.size();
        int col=m[0].size();

    int low= m[0][0];
    int high=m[row-1][col-1];
    
    while(low < high){
        int mid=low+(high-low)/2;
        int temp=col-1;
        int count=0;
      
        for(int i=0;i<row;i++){
            while(temp >=0 && m[i][temp] > mid){
                temp--;
            }
            count+=temp+1;
        }
        
        if(count >= k){
            high=mid;
        }
        else{
            low=mid+1;
        }
        
    }
    return low;
}
};