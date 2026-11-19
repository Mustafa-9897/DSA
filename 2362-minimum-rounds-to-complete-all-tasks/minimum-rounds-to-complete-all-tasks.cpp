class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }
        for(auto it:mpp){
            int temp=it.second;
            if(temp<2) return -1;
            while(temp>0){
                ans++;
                temp -= 3;
            }
        }
        return ans;
    }
};