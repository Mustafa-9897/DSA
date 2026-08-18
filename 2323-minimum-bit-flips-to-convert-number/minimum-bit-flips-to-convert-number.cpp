class Solution {
public:
    int minBitFlips(int start, int goal) {
        // string res1="";
        // string res2="";
        // if(start==0) res1 = "0";
        // else{
        //     while(start!=1){
        //         if(start%2==1) res1 += '1';
        //         else res1 += '0';
        //         start /= 2;
        //     }
        //     res1 += '1';
        //     reverse(res1.begin(),res1.end());
        // }
        // if(goal==0) res2 = "0";
        // else{
        //     while(goal!=1){
        //         if(goal%2==1) res2 += '1';
        //         else res2 += '0';
        //         goal /= 2;
        //     }
        //     res2 += '1';
        //     reverse(res2.begin(),res2.end());
        // }      
        // int i=res1.size()-1;
        // int j=res2.size()-1;
        // int x1,y1;
        // int cnt=0;
        // while(i>=0 || j>=0){
        //     if(i>=0) x1=res1[i];
        //     else x1='0';
        //     if(j>=0) y1=res2[j];
        //     else y1='0';
        //     if(x1!=y1) cnt++;
        //     i--;j--;
        // }
        // return cnt;


        //  OPTIMAL 
        int ans=start^goal;
        int cnt=0;
        while(ans!=0){
            if(ans%2==1) cnt++;
            ans=ans>>1;
        }
        return cnt;
    }
};