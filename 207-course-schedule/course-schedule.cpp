class Solution {
public:
    // bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    //     vis[node]=1;
    //     for(auto adjnode:adj[node]){
    //         if(!vis[adjnode]){
    //             if(dfs(adjnode,adj,vis)) return true;
    //         }
    //         if(vis[adjnode]==1) return true;
    //     }
    //     vis[node]=2;
    //     return false;
    // }

    bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,adj,vis,dfsvis)) return true;
            }
            else if(vis[adjnode] && dfsvis[adjnode]) return true;
        }
        dfsvis[node]--;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // if there is a cycle int he graph that means any two subjects are dependant on each other eg,  [1,0],[0,1]   1->0->1 cycle that makes the course scheduling impossible therefore [cycle-yes](ans no)  , [cycle-no](ans yes);

        vector<vector<int>>adj(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>dfsvis(numCourses,0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsvis)) return false;
            }
        }
        return true;
    }
};