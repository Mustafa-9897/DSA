class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>mpp;
        for(int i=0;i<logs.size();i++){
            mpp[logs[i][0]].insert(logs[i][1]);
        }
        vector<int>frq(k+1,0);
        for(auto it:mpp){
            int id=it.first;
            int uniquemin=it.second.size();
            frq[uniquemin]++;
        }
        vector<int>ans;
        for(int i=1;i<frq.size();i++){
            ans.push_back(frq[i]);
        }
        return ans;
    }
};