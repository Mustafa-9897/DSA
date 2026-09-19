class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int r=cardPoints.size()-1;
        int lsum=0,rsum=0;
        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
        }
        int sum=lsum;
        int l=k-1;
        while(l>=0){
            lsum -= cardPoints[l];
            rsum += cardPoints[r];
            l--;
            r--;
            sum = max(sum,lsum+rsum);
        }
        return sum;
    }
};