class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int>mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        vector<pair<int,int>>st;
        for(auto e:mp){
            st.push_back({e.first,e.second});
        }
        sort(st.begin(),st.end(),cmp);
        for(int i =0;i<k;i++){
            ans.push_back(st[i].first);
        }
        
        return ans;
    }
};