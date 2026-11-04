class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // JO NODES KI INDEGREE 0 HAI VO NODES BAS KHUD SE HI ACCESSIBLE HAI SO UNKO INCLUDE KARNA HI PADHEGA AND JO OTHER NODES HAI JINKI INDEGREE 0 NAHI HAI VO NODES ACCESSIBLE HAI UN NODES SE JINKI INDEGREEE 0 HAI .


        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        vector<int>ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};