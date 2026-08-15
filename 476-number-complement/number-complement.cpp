class Solution {
public:
    int findComplement(int num) {
        // int n=~num;   this negates all the 32 bits ,but we only need to negate given no.of bits
        // return n;
        string res="";
        while(num!=1){
            res += char((num&1)+'0');
            num=num>>1;
        }
        res += '1';
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            if(res[i]=='1') res[i]='0';
            else res[i]='1';
        }
        int p2=1;
        int sum=0;
        for(int i=res.size()-1;i>=0;i--){
            if(res[i]=='1')
                sum +=p2;
            if(i!=0)
                p2 *= 2;
        }
        return sum;
    }
};