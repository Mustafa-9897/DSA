class Solution {
public:
    vector<int> sumZero(int n) {
        int max=n;
        vector<int>ans;
        if(n%2!=0){
            max=n-1;
            ans.push_back(0);
        }
        int cnt=1;
        for(int i=0;i<max;i++){
            if(i%2==0)
                ans.push_back(cnt);
            else
                ans.push_back(-(cnt));
            if(i%2!=0)
                cnt++;
        }
        return ans;
    }
};