//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n=s.length();
        int left=0,ans=-1;
        map<char,int>mp;
        for(int i =0 ;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
            }
            else{
                mp[s[i]]=1;
            }
            while(left <= i && mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            if(mp.size()==k){
                ans=max(ans,i-left+1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends