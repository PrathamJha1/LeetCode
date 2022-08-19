class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> counts, sequence;
        
        for(int num : nums){
            counts[num]++;
        }
        
        for(int num : nums){
            if(counts[num] <= 0)
                continue;            
            counts[num]--;
            if(sequence[num-1]){
                sequence[num-1]--;
                sequence[num]++;
            }
            else if(counts[num+1] && counts[num+2]){
                counts[num+1]--;
                counts[num+2]--;
                sequence[num+2]++;
            }
            else{
                return false;
            }
        }
        
        
        return true;
    }
};