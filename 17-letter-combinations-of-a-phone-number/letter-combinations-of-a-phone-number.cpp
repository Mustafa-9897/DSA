class Solution {
public:
    void helper(int index,string digits,string combos[],vector<string>&ans,string s){
        if(index==digits.size()){
            ans.push_back(s);
            return ;
        }
        int digit=digits[index]-'0';
        for(int i=0;i<combos[digit].size();i++){
            helper(index+1,digits,combos,ans,s+combos[digit][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        helper(0,digits,combos,ans,"");
        return ans;
    }
};