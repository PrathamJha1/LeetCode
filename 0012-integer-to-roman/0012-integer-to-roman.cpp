class Solution {
public:
    string intToRoman(int num) {
        map<string,int>mp;
        vector<string> keys;
        keys.push_back("M");
        keys.push_back("CM");
        keys.push_back("D");
        keys.push_back("CD");
        keys.push_back("C");
        keys.push_back("XC");
        keys.push_back("L");
        keys.push_back("XL");
        keys.push_back("X");
        keys.push_back("IX");
        keys.push_back("V");
        keys.push_back("IV");
        keys.push_back("I");
        string ans="";
        mp.insert({"M",1000});
        mp.insert({"CM",900});
        mp.insert({"D",500});
        mp.insert({"CD",400});
        mp.insert({"C",100});
        mp.insert({"XC",90});
        mp.insert({"L",50});
        mp.insert({"XL",40});
        mp.insert({"X",10});
        mp.insert({"IX",9});
        mp.insert({"V",5});
        mp.insert({"IV",4});
        mp.insert({"I",1});
        for(auto it:keys){
            cout<<num <<" "<<it<<endl;
            if(num % mp[it] >= 0){
                int val = num / mp[it];
                num= num%mp[it];
                while(val){
                    ans+=it;
                    val--;
                }
            }
        }
        return ans;
    }
};