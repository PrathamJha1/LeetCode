class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> sbnak(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({start, 0});

        while(q.size()) {
            string s = q.front().first;
            int d = q.front().second; q.pop();

            if(s == end) return d;

            for(int i=0; i<8; i++) {
                string t = s;
                for(char c : "ACGT") {
                    t[i] = c;
                    if(sbnak.find(t) != sbnak.end()) q.push({t, d + 1}), sbnak.erase(t);
                }
            }
        }
        return -1;
    }
};