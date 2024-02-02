class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
            return b[1] > a[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     sort(intervals.begin(),intervals.end(),cmp);
     int cnt = 0;

    for(int i =0;i<intervals.size()-1;i++){
    
        if(intervals[i+1][0] < intervals[i][1]){
        cnt++;
        intervals[i+1][1] = intervals[i][1];
        intervals[i+1][0] = intervals[i][0];
        }
    }
    // |    /  |     -  /   - 
    // for each index look at the one after it if it is best to remove
    // assume everything behind is correct then we better get rid of the next ie /
    // since it may also destroy another interval thats it
    return cnt;
    }
};