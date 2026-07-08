class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // int maxdist=0;
        // for(int i=0;i<colors.size();i++){
        //     for(int j=i+1;j<colors.size();j++){
        //         if(colors[j]!=colors[i]){
        //             maxdist=max(maxdist,j-i);
        //         }
        //     }
        // }
        // return maxdist;

          // OPTIMAL
        int ans=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[0]){
                ans=max(ans,i);
            }
            if(colors[i]!=colors[n-1]){
                ans=max(ans,n-1-i);
            }
        }
        return ans;
    }
};