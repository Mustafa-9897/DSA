class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int left=0;
        int right=0;
        int n=s.size();
        // left pass , it can detect substrings like ()) when right>left but can't detect (() for (() this string it will give ans=0 but its ans is 2
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                ans=max(ans,2*right);
            }
            // means eg. for string )() at i=0 right=1 so ) can't be included in the valid substring so remove it from our valid substring length by resetting left and right
            if(right>left){
                left=0;
                right=0;
            }
        }
        left=0;
        right=0;
        // the right is for strings like (() it can detect when the left exceeds right 
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                ans=max(ans,2*right);
            }
            if(left>right){
                left=0;
                right=0;
            }
        }
        return ans;
    }
};