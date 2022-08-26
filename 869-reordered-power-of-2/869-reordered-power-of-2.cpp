class Solution {
public:
    vector<int>count(int n){
        vector<int> ans(10,0);
        while(n>0){
            ans[n%10]++;
            n/=10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> freqN(10,0);
        freqN = count(n);
        int num=1;
        for(int i=0;i<31;i++){
            if(freqN == count(num)){
                return true;
            }
            num=num<<1;
        }
        return false;
    }
};