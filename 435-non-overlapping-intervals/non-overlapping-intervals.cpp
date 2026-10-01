class Solution {
public:
    static bool comparator(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // JUST OPPOSITE ANSWER OF N MEETINGS IN A ROOM
        int ans=0;
        int end=INT_MIN;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comparator);
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=end){
                ans++;
                end=intervals[i][1];
            }
        }
        return n-ans;
    }
};