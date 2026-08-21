class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr=0;
        for(int i=0;i<derived.size();i++){
            xorr ^= derived[i];
        }
        if(xorr==0) return true; // since in derived array each element is formed by 
        return false;            // using each element 2 times from the original array
    }                            // so upon xorring derived array it should become 0
};