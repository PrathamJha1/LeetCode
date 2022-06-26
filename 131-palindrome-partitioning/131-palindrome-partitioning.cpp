class Solution {
public:
    vector<vector<string>> ret;
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void dfs(string& s, int start, vector<string>& par) {
        int n = s.length();
        if (start == n) {
            ret.push_back(par);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    par.push_back(s.substr(start, i - start + 1));
                    dfs(s, i + 1, par);
                    par.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        if(s.empty())return ret;
        dfs(s,0,path);
        return ret;
    }
};