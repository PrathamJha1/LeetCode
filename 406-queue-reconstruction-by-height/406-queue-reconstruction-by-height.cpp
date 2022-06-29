class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        if(a[1]<b[1]){
            return true;
        }
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j>=0;j--){
                if(i!=j){
                    if(people[j][0]>=people[i][0]){
                        count++;
                    }
                }
            }
            if(count==people[i][1]){
                continue;
            }
            else if(count>people[i][1]){
                int diff=count-people[i][1];
                int k=i,l=i-1;
                while(diff--){
                    swap(people[k],people[l]);
                    k--,l--;
                }
            }
        }
        return people;
    }
};