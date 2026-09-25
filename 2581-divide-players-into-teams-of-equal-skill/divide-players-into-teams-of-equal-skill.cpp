class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=1,j=n-2;
        int sk=skill[0]+skill[n-1];
        long long ans=skill[0]*skill[n-1];
        while(i<j){
            if(skill[i]+skill[j] != sk) return -1;
            ans += skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;
    }
};