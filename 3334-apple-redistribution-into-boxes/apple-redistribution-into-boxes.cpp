class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int sum=0;
        for(int i=0;i<apple.size();i++){
            sum += apple[i];
        }
        int s=0;
        int ans=0;
        for(int i=capacity.size()-1;i>=0;i--){
            s += capacity[i];
            ans++;
            if(s>=sum){
                break;;
            }
        }
        return ans;
    }
};