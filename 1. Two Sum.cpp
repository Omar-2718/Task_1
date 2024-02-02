class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,pair<int,bool>>mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]] = {i,true};
        }
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            if(mp[target - nums[i]].second && mp[target - nums[i]].first != i){
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]].first);
                return ans;
            }
        }
        return ans;
    }
};