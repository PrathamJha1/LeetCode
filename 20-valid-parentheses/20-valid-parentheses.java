class Solution {
    public boolean isValid(String s) {
        boolean ans=false;
        Stack<Character> st = new Stack<>();
        int n=s.length();
        for(int i=0;i<n;i++){
            Character c=s.charAt(i);
            if(c==')'){
                if(st.isEmpty() || st.peek()!='('){
                    return false;
                }
                st.pop();
            }
            else if(c=='}'){
                if(st.isEmpty() || st.peek()!='{'){
                    return false;
                }
                st.pop();
            }
            else if(c==']'){
                if(st.isEmpty() || st.peek()!='['){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.isEmpty();
    }
}