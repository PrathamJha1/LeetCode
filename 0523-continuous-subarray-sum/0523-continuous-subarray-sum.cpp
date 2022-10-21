class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum % k ==0){
                if(i>0){
                    return true;
                }
            }
            if(mp.find(sum % k ) != mp.end()){
                if(i - mp[sum%k] >1){
                    return true;
                }
            }
            else{
                mp[sum % k]=i;                
            }
            
        }
        return false;
    }
};