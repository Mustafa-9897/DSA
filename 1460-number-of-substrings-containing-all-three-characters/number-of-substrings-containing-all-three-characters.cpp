class Solution {
public:
    int numberOfSubstrings(string s) {
    // BRUTE
    // int n=s.size();
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     vector<int>hash(3,0);
    //     for(int j=i;j<n;j++){
    //         hash[s[j]-'a']=1;
    //         if(hash[0]+hash[1]+hash[2]==3){
    //             ans += n-j;
    //             break;
    //         }
    //     }
    // }
    // return ans;

    //    int cnt=0,n=s.size();
    //    int right=0,left=0;
    //    int cnta=0,cntb=0,cntc=0;
    //    for(right=0;right<s.size();right++){
    //     if(s[right]=='a') cnta++;
    //     else if(s[right]=='b') cntb++;
    //     else cntc++;
    //     while(cnta>=1 && cntb>=1 && cntc>=1){
    //         cnt += n-right;
    //         if(s[left]=='a') cnta--;
    //         else if(s[left]=='b') cntb--;
    //         else cntc--;
    //         left++;
    //     }
    //    }
    //    return cnt;
    

    // CLEAN VERSION OF ABOVE CODE
    int n = s.size();
    vector<int> freq(3, 0);
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        freq[s[right] - 'a']++;
        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            ans += n - right;
            freq[s[left] - 'a']--;
            left++;
        }
    }
    return ans;
    }
};