class TimeMap {
public:
     unordered_map<string,vector<pair<int,string>>> mp;
    
    string find(vector<pair<int,string>> &v, int timestamp){
        int low=0,high=v.size()-1;
        string ans="";
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid].first<=timestamp){
                if(v[mid].first==timestamp){
                    return v[mid].second;
                }
                ans=v[mid].second;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){
            return "";
        }
        string ans=find(mp[key],timestamp);
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */