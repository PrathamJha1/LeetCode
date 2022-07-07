class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]==target){
                return m;
            }
            if(arr[l]<=arr[m]){
                if(target <= arr[m] && target>=arr[l]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(target >= arr[m] && arr[r]>=target){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        return -1;
    }
};