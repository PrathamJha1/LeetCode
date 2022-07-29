class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        unordered_map<char, char> m1, m2;
        for(auto ele : words) {
            int i;
            for(i=0; i<pattern.length(); i++) {
                if (m1.find(pattern[i]) == m1.end() && m2.find(ele[i]) == m2.end()) {
                    m1[pattern[i]] = ele[i];
                    m2[ele[i]] = pattern[i];
                }
                else if (m1[pattern[i]] != ele[i] || m2[ele[i]] != pattern[i])
                    break;
            }
            
            if (i == pattern.length())
                res.push_back(ele);
            m1.clear();
            m2.clear();
        }
        return res;
    }
};