class Solution {
public:
    static bool comparator(int a,int b){
        int p=a,q=b;
        int suma=0,sumb=0;
        while(p!=0){
            suma += p%10;
            p /= 10;
        }
        while(q!=0){
            sumb += q%10;
            q /= 10;
        }
        if(suma==sumb) return a<b;
        return suma<sumb;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        sort(nums.begin(),nums.end(),comparator);

        // int cnt=0;
        // for(int i=0;i<nums.size();i++){    // wrong method of counting swaps
        //     if(mpp[nums[i]]!=i){
        //         cnt++;
        //     }
        // }
        // if(cnt%2==0) return cnt/2;
        // return cnt/2+1;

        vector<bool>vis(n,false);
        int swaps=0;
        for(int i=0;i<n;i++){
            if(vis[i]==true || mpp[nums[i]]==i) continue;

            int j=i;
            int cyclesize=0;
            while(!vis[j]){
                vis[j]=true;
                j=mpp[nums[j]];
                cyclesize++;
            }
            swaps += cyclesize-1;
        }
        return swaps;
    }
};