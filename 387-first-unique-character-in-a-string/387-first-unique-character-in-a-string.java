class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character,Integer> hm= new HashMap<>();
        for(int i=0;i<s.length();i++){
            Character c= s.charAt(i);
            if(hm.getOrDefault(c,-1)==-1){
                hm.put(c,1);
            }
            else{
                hm.put(c,hm.get(c)+1);
            }
        }
        for(int i=0;i<s.length();i++){
            Character c=s.charAt(i);
            if(hm.get(c)==1){
                return i;
            }
        }
        return -1;
    }
}