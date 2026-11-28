class Solution {
public:
    int minRange(int a, int b, int c) {
        int mini=min({a,b,c});
        int maxi=max({a,b,c});
        int flag=1;
        while(flag==1){
            int sum1=min({a+b,b+c,a+c});
            if(maxi>sum1){
                maxi=sum1;
                flag=1;
            }
            else{
                flag=0;
            }
        }
        int range=maxi-mini;
        //int mini=max({})
        return range;
    }
};