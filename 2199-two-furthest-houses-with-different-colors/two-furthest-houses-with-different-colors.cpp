class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxdist=0;
        for(int i=0;i<colors.size();i++){
            for(int j=i+1;j<colors.size();j++){
                if(colors[j]!=colors[i]){
                    maxdist=max(maxdist,j-i);
                }
            }
        }
        return maxdist;
    }
};