class Solution {
public:
    int minimumSum(int num) {
        vector<int>hash;
        int q=num;
        while(q>0){
            hash.push_back(q%10);
            q /= 10;
        }
        sort(hash.begin(),hash.end());
        int num1=0;
        int num2=0;
        // num1=num1*10+hash[0];
        // num1=num1*10+hash[3];
        // num2=num2*10+hash[1];
        // num2=num2*10+hash[2];
        for(int i=0;i<hash.size();i++){
            if(i==0 || i==3)
                num1=num1*10+hash[i];
            else
                num2=num2*10+hash[i];
        }
        return num1+num2;
    }
};