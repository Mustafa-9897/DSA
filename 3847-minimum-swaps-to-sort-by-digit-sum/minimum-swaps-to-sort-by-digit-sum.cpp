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
            // if we have already checked the cycle for an elemnt or if the elemnt is already at the correct place the continue.
            if(vis[i]==true || mpp[nums[i]]==i) continue;

            int j=i;
            int cyclesize=0;
            // 1->3->1 , for this cycle the cycle size is 3 but swaps needed are only 2 (cyclesize-1), traverse over the elemnts thorough linking provided by the map until you reach an element that has already been marked.
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