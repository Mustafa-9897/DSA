class Solution {
public:
    void dfs(int node,int target,vector<vector<int>>&ans,vector<int>&seq,vector<vector<int>>&graph){
        if(node==target){
            seq.push_back(node);
            ans.push_back(seq);
            seq.pop_back();
            return ;
        }
        seq.push_back(node);
        for(auto it:graph[node]){
            dfs(it,target,ans,seq,graph);
        }
        seq.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>seq;
        vector<vector<int>>ans;
        int target=n-1;
        dfs(0,target,ans,seq,graph);
        return ans;
    }
};