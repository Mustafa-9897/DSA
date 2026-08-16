class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask=1;
        int temp=n;            // num=5  ->  101
        while(temp!=1){          // mask   ->  111
            mask=mask<<1|1;      // num^mask -> 010  -> ans in decimal
            temp /= 2;           // mask=(mask<<1|1) , eg, mask=11 then mask<<1 -> 110 then
        }                        // mask<<1|1 whill be 110|1 -> 111 , used to add 1 to right 
        return mask^n;         // side in binary numbers
    }
};