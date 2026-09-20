class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //sort(bills.begin(),bills.end());  // you cannot sort this one becuase saare customers queue me khade hai so by sorting you are changing the queue which we cannot do
        int b5=0,b10=0,b20=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) b5++;
            else if(bills[i]==10){
                if(b5==0) return false;
                b5--;
                b10++;
            }
            else{
                if(b5>=1 && b10>=1){
                    b5--;
                    b10--;
                }
                else if(b5>=3){
                    b5 -= 3;
                }
                else{
                    return false;
                }
                b20++;
            }
        }
        return true;
    }
};