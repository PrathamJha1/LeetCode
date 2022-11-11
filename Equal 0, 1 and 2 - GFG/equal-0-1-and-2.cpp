//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long
class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        ll ans=0, countZeroes = 0 ,countOnes=0,countTwos=0;
        map<pair<ll,ll>,ll>mp;
        mp[{0,0}]=1;
        for(int i=0;i<str.length();i++){
            char c=str[i];
            if(c == '0'){
                countZeroes +=1;
            }
            else if(c=='1'){
                countOnes++;
            }
            else{
                countTwos ++;
            }
            
            pair<ll,ll>temp = {countOnes-countZeroes,countTwos - countOnes};
            if(mp.find(temp) != mp.end()){
                ans += mp[temp];
            }
            mp[temp]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends