class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> keys;
        string ans="";
        keys.push_back({"M",1000});
        keys.push_back({"CM",900});
        keys.push_back({"D",500});
        keys.push_back({"CD",400});
        keys.push_back({"C",100});
        keys.push_back({"XC",90});
        keys.push_back({"L",50});
        keys.push_back({"XL",40});
        keys.push_back({"X",10});
        keys.push_back({"IX",9});
        keys.push_back({"V",5});
        keys.push_back({"IV",4});
        keys.push_back({"I",1});
        for(auto it:keys){
            if(num % it.second >= 0){
                int val = num / it.second;
                num= num % it.second;
                while(val){
                    ans += it.first;
                    val--;
                }
            }
        }
        return ans;
    }
};