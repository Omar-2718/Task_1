class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string>temp;
    temp = strs;
    for(int i =0;i<strs.size();i++){
        sort(strs[i].begin(),strs[i].end());
    }
    vector<vector<string>> ans;
    vector<bool>arr(strs.size(),false);
    for(int i = 0;i<strs.size();i++){
        vector<string>temp1;
        temp1.push_back(temp[i]);
        if(!arr[i]){
        for(int j = i+1;j<strs.size();j++){
            
            if(strs[i] == strs[j]){
                arr[j] = true;
                temp1.push_back(temp[j]);
            }
        }
        arr[i] = true;
        ans.push_back(temp1);
        }
    }
    return ans;
    }
};