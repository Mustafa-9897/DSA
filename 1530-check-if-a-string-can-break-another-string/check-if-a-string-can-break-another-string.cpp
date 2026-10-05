class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        // int n=s1.size();
        // vector<int>hash1(26,0);
        // vector<int>hash2(26,0);
        // for(int i=0;i<n;i++){
        //     hash1[s[i]-'a']=1;
        //     hash2[s[i]-'a']=1;
        // }
        // int i=0,j=0;
        // while(i<n){
        //     if(hash1[i]==0){
        //         continue;
        //     }
        //     if(hash2[j]!=0 && j<i){
        //         j++;
        //     }
        //     i++;
        // }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool ans1=true;
        bool ans2=true;
        int i=0,n=s1.size();
        while(i<n){
            if(s1[i]>=s2[i]){

            }
            else{
                ans1=false;
            }
            if(s2[i]>=s1[i]){
                
            }
            else{
                ans2=false;
            }
            i++;
        }
        return (ans1 || ans2);
    }
};