class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return 0;
        
        // 3^19=1162261467
        return 1162261467%n==0;
    }
};