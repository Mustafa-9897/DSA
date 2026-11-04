class Solution {
public:
    void dfs(int node,vector<vector<int>>&rooms,unordered_set<int>&st,vector<int>&vis){
        st.insert(node);
        vis[node]=1;
        for(auto it:rooms[node]){
            if(!vis[it])
                dfs(it,rooms,st,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //  WE CANNOT USE KAHN'S ALGORITHM OR TOPO SORT HERE BECUASE IT IS NOT A DAG , THERE ARE EVEN SELF LOOPS HERE

        // int n=rooms.size();
        // vector<int>topo;
        // queue<int>q;
        // vector<int>indegree(n,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<rooms[i].size();j++){
        //         indegree[rooms[i][j]]++;
        //     }
        // }

        // for(int i=0;i<indegree.size();i++){
        //     if(indegree[i]==0) q.push(i);
        // }

        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     topo.push_back(node);
        //     vis[node]++;
        //     for(auto it:rooms[node]){
        //         indegree[it]--;
        //         if(indegree[it]==0) q.push(it);
        //     }
        // }      
        // return topo.size()==n;


        //  THIS METHOD IS WRONG TOO , BECAUSE IT CHECKS IF THE CURRENT ROOM CAN BE VISITED OR NOT ON THE BASIS OF THE KEYS WE OBTAINED BEFORE , BUT WE HAVE TO CHECK IFWE CAN VISIT ALL ROOMS AT THE END

        // unordered_map<int,int>mpp;
        // for(int i=0;i<rooms[0].size();i++){
        //     mpp[rooms[0][i]]++;
        // }
        // for(int i=1;i<rooms.size();i++){
        //     if(mpp.find(i)==mpp.end()) return false;
        //     for(int j=0;j<rooms[i].size();j++){
        //         mpp[rooms[i][j]]++;
        //     }
        // }
        // return true;

        //  THIS IS WRONG BECAUSE YOU ARE ONLY ITERATING A ROOM ONLY ONCE , IT MAY HAPPEN THAT ROOM AT IDX 1 MAY BE ACCESSIBLE AFTER DISCOVERING ROOM AT IDX 2 AND ROOM AT IDX 1 CONSISTS THE KEYS OF THE ROOMS THAT ARE UNVISITED BECAUSE YOU NEVER REVISITED ROOM AT IDX 1
        // int n=rooms.size();
        // unordered_map<int,int>mpp;
        // vector<int>vis(n,0);
        // for(int i=0;i<rooms[0].size();i++){
        //     mpp[rooms[0][i]]++;
        //     vis[rooms[0][i]]++;
        // }
        
        // for(int i=1;i<rooms.size();i++){
        //     if(mpp.find(i)==mpp.end()) continue;
        //     for(int j=0;j<rooms[i].size();j++){
        //         mpp[rooms[i][j]]++;
        //         vis[rooms[i][j]]++;
        //     }
        // }
        // for(int i=1;i<vis.size();i++){
        //     if(vis[i]==0) return false;
        // }
        // return true;

        unordered_set<int>st;
        int n=rooms.size();
        vector<int>vis(n,0);
        dfs(0,rooms,st,vis);
        return st.size()==rooms.size();
    }
};