class Solution {
public:
    int maxScore(int i,int e,vector<int>t,int power,int score){
        if(i>e){
            return score;
        }
        int ms1=score,ms2=0;
        if(power >= t[i]){
            ms2 = maxScore(i+1,e,t,power-t[i],score + 1);
        }
        else if(score >= 1){
            ms2 = maxScore(i,e-1,t,power + t[e] ,score - 1);
        }
        return max(ms1,ms2);
        
    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        return maxScore(0,tokens.size()-1,tokens,power,0);
    }
};