class Solution {
public:
        void heapify(vector<int> &heap,int n,int i){
        int l=2*i,r=2*i+1;
        int smallest=i;
        if(l<n && heap[l]<heap[smallest]){
            smallest=l;
        }
        if(r<n && heap[r]<heap[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            swap(heap[i],heap[smallest]);
            heapify(heap,n,smallest);
        }
    }
    void buildheap(vector<int>&arr,int n){
        for(int i=n;i>=0;i--){
            heapify(arr,n,i);
        }
    }
    int del(vector<int>&heap,int n){
        swap(heap[0],heap[n-1]);
        int val=heap[n-1];
        heap.pop_back();
        heapify(heap,n-1,0);
        return val;

    }
    int findKthLargest(vector<int>& nums, int k) {
        buildheap(nums,nums.size());
        k=nums.size()-k;
        int ans;
        while(k--){
           ans= del(nums,nums.size());
        }
        return del(nums,nums.size());
    }
};