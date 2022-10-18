class Solution {
public:
    string count(string str){
        int count=1;
        string res="";
        for(int i=1;i<str.size();i++){
            if(str[i]==str[i-1]){
                count++;
            }
            else{
              char ch=count+'0';
               res+=ch;
                res+=str[i-1];
                count=1;
            }
        }
        char ch=count+'0';
         res+=ch;
        res+=str[str.size()-1];
        count=1;
        return res;
    }
    string countAndSay(int n) {
        string s="1";
        while(n>1){
            s=count(s);
            n--;
        }
        return s;   
    }
};