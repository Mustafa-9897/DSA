class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k){
            string temp="";
            int sum=0;
            int cnt=0;
            for(int i=0;i<ans.size();i++){
                sum += ans[i]-'0';
                cnt++;
                if(cnt==k || i==ans.size()-1){
                    string t="";
                    if(sum==0) t += '0';
                    while(sum>0){
                        int rem=sum%10;
                        t += rem+'0';
                        sum /= 10;
                    }
                    reverse(t.begin(),t.end());
                    temp += t;
                    sum=0;
                    cnt=0;
                }
            }
            ans=temp;
        }
        return ans;
    }
};