class Solution {
public:
    // bool check(int num){
    //     string s=to_string(num);
    //     int cnt=0;
    //     for(int i=0;i<s.size()-1;i++){
    //         if(s[i+1]==s[i]+1){
                
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    vector<int> sequentialDigits(int low, int high) {
        // vector<int>ans;
        // for(int i=low;i<=high;i++){
        //     if(check(i)==true){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        // OPTIMAL
        string s="123456789";
        vector<int>ans;
        for(int len=2;len<=9;len++){
            for(int i=0;i+len<=9;i++){
                int num=stoi(s.substr(i,len));
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};