class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n=score.size();
        int m=score[0].size();
        for(int i=0;i<n-1;i++){
            int minidx=i;
            for(int j=i+1;j<n;j++){
                if(score[j][k]>score[minidx][k]){
                    minidx=j;
                }
            }
            swap(score[i],score[minidx]);
        }
        return score;
    }
};