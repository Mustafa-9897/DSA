class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>temp;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            temp.push_back(capacity[i]-rocks[i]);
        }
        sort(temp.begin(),temp.end());
        int cnt=additionalRocks;
        int ans=0;
        for(int i=0;i<temp.size();i++){
            if(cnt>=temp[i]){
                ans++;
                cnt -= temp[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};