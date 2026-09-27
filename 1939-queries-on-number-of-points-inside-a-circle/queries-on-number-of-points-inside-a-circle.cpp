class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int cnt=0;
            for(int j=0;j<points.size();j++){
                int x=(queries[i][0]-points[j][0]);
                int y=(queries[i][1]-points[j][1]);
                if(queries[i][2]>=sqrt(x*x+y*y)){ // check if the distance of the point from 
                    cnt++;                        // the center is less than radius or not
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};