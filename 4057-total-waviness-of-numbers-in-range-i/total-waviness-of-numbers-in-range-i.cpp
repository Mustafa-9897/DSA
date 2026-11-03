class Solution {
public:
    vector<int>helper(int num){
        vector<int>ans;
        while(num!=0){
            ans.push_back(num%10);
            num=num/10;
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            if(i/100==0) continue;
            vector<int>temp=helper(i);
            for(int j=1;j<temp.size()-1;j++){
                if((temp[j]>temp[j-1] && temp[j]>temp[j+1]) || (temp[j]<temp[j-1] && temp[j]<temp[j+1])) ans++;
            }
        }
        return ans;
    }
};