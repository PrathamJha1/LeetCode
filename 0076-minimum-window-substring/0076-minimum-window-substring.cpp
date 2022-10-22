class Solution {
public:
    string minWindow(string s, string t) {
     map<char,int>mp;
        for(int i = 0; i<t.size(); i++)
        {
            mp[t[i]]++;
        }
        int i = 0, j = 0, f = 0, l = INT_MAX, count = 0, sz = mp.size();
        
        map<char,int>m;
        
        while(i<s.size())
        {
            m[s[i]]++;
            if(m[s[i]] == mp[s[i]])
            {
                count++;
            }
            while(count == sz)
            {
                cout<<sz;
                if(i-j < l-f)
                {
                    f = j; l = i;
                }
                m[s[j]]--;
                if(m[s[j]] == 0)
                {
                    m.erase(s[j]);
                }
                if(mp[s[j]]>0  &&  m[s[j]]<mp[s[j]]) count--;
                j++;
                if(count < sz) break;
            }
            
            i++;
        }
        if(l == INT_MAX) return "";
        return s.substr(f, l-f+1);
    }
};