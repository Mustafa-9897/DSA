class Solution {
public:
    static bool comparator(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int minSetSize(vector<int>& arr) {
        vector<vector<int>>temp;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        temp.push_back({arr[0],1});
        for(int i=1;i<n;i++){
            if(arr[i]==temp.back()[0]){
                temp.back()[1]++;
            }
            else{
                temp.push_back({arr[i],1});
            }
        }
        sort(temp.begin(),temp.end(),comparator);
        int cnt=0;
        int size=0;
        for(int i=0;i<temp.size();i++){
            cnt++;
            size += temp[i][1];
            if(n-size<=n/2){
                break;
            }
        }
        return cnt;
    }
};