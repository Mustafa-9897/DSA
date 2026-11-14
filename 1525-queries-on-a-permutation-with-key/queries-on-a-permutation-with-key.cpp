class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int,int>mpp;
        for(int i=1;i<=m;i++){
            mpp[i]=i-1;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int q=queries[i];
            ans.push_back(mpp[q]);
            for(auto &it:mpp){  // when you do (auto it:something) it creates a copy of that item , so when you do it.second++ it only increments the copy not the real map , so use (auto &it)
                if(it.second<mpp[q]) it.second++;
            }
            mpp[q]=0;
        }
        return ans;
    }
};