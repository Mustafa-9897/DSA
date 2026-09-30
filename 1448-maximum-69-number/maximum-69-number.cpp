class Solution {
public:
    int maximum69Number (int num) {
        // string s="";
        // int q=num;
        // int len=0;
        // int reversenum=0;
        // while(q>0){
        //     int rem=q%10;
        //     len++;
        //     s += char(rem);
        //     q /= 10;
        //     reversenum=reversenum*10+rem;
        // }
        // reverse(s.begin(),s.end());
        // int cnt;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='6'){
        //         cnt=i+1;
        //         break;
        //     }
        // }
        // int ans=0;
        // int cnt2=0;
        // while(reversenum>0){
        //     cnt2++;
        //     int rem=reversenum%10;
        //     if(cnt2==cnt){
        //         ans=ans*10+9;
        //     }
        //     else{
        //         ans=ans*10+rem;
        //     }
        //     reversenum /= 10;
        // }
        // return ans;
        int q=num;
        int rnum=0;
        int pos=0;
        int cnt=1;
        while(q>0){
            int rem=q%10;
            if(rem==6){
                pos=cnt;
            }
            rnum=rnum*10+rem;
            q/=10;
            cnt++;
        }
        cnt=0;
        int ans=0;
        q=num;
        while(q>0){
            int rem=q%10;
            cnt++;
            if(cnt==pos){
                ans=ans*10+9;
            }
            else{
                ans=ans*10+rem;
            }
            q /= 10;
        }
        int finalans=0;
        while(ans>0){
            int rem=ans%10;
            finalans=finalans*10+rem;
            ans/=10;
        }
        return finalans;
    }
};