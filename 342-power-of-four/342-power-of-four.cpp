class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n>0){
            if((n&n-1)==0&&(n%10==4||n%10==6)){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};