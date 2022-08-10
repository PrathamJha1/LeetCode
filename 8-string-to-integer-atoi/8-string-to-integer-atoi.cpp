class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        if(n==0)return 0;
        int i=0;
        bool f=false;
        //avoiding front white spaces
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n){
            if(s[i]=='-'){
                f=true;
                i++;
            }
            else if(s[i] == '+'){
                f=false;
                i++;
            }
        }
        int res=0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(res > (INT_MAX / 10) || (res == (INT_MAX / 10) && digit > 7)){
                    return f ? INT_MIN : INT_MAX;
            }

            res = (res * 10) + digit;
            i++;
        }
        return f==true?-res:+res;
    }
};