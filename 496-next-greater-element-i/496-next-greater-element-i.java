class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n=nums2.length;
        int [] nge = new int[n+1];
        int [] ans= new int[nums1.length];
        if(n==0 || nums1.length==0){
            return nge;
        }
        LinkedList<Integer> l = new LinkedList<Integer>();
        l.add(nums2[n-1]);
        nge[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(l.size()!=0 && l.peekLast()<=nums2[i]){
                l.removeLast();
            }
            if(l.size()==0){
                nge[i]=-1;
            }
            else{
                nge[i]=l.peekLast();
            }
            l.add(nums2[i]);
        }
        HashMap<Integer,Integer> h = new HashMap<>();
        for(int i=0;i<n;i++){
            h.put(nums2[i],nge[i]);
        }
        for(int i=0;i<nums1.length;i++){
            ans[i]=h.get(nums1[i]);
        }
        return ans;
    }
}