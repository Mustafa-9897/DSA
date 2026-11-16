class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        // run the simulation till the size > k
        while(ans.size()>k){
            // the reduced string after each round is temp
            string temp="";
            int sum=0;
            int cnt=0;
            for(int i=0;i<ans.size();i++){
                sum += ans[i]-'0';
                cnt++;
                if(cnt==k || i==ans.size()-1){
                    // the combined string of each group
                    string t="";
                    if(sum==0) t += '0';
                    while(sum>0){
                        int rem=sum%10;
                        t += rem+'0';
                        sum /= 10;
                    }
                    reverse(t.begin(),t.end());
                    temp += t; // add each group to the new string that we are making
                    sum=0;
                    cnt=0;
                }
            }
            // since we are using ans string in for loop so we have to use an extra string temp , so we do not change the ans string during execution
            ans=temp;
        }
        return ans;
    }
};