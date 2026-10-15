class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // int n=nums.size();
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<int,int>mpp;
        //     for(int j=i;j<n;j++){
        //         if(mpp.find(nums[j])==mpp.end()){   // USING MAP
        //             mpp[nums[j]]=1;
        //         }
        //         int size=mpp.size();
        //         sum += size*size;
        //     }
        // }
        // return sum;

        // int n=nums.size();
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     set<int>st;
        //     for(int j=i;j<n;j++){
        //         st.insert(nums[j]);                    //  USING SET
        //         int size=st.size();
        //         sum += size*size;
        //     }
        // }
        // return sum;

        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            vector<int>hash(101,0);
            int size=0;
            for(int j=i;j<n;j++){
                if(hash[nums[j]]==0){          // USING VECTOR SINCE CONSTARINTS ARE SMALL
                    size++;
                }
                hash[nums[j]]++; 
                sum += size*size;
            }
        }
        return sum;
    }
};