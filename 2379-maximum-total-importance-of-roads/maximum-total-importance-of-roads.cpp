class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(auto it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        sort(degree.begin(),degree.end());
        long long ans=0;
        for(int i=0;i<degree.size();i++){
            ans += 1LL * (degree[i]) * (i+1); // (i+1) is the assigned integer and this integer will get added degree[i] times in the ans finally
        }       
        return ans;
    }
};