class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b) { // custome comparator
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), compare);

        int ans = 0;

        for(int i = 0; i < boxTypes.size(); i++) {

            int boxes = min(truckSize, boxTypes[i][0]); // important logic

            ans += boxes * boxTypes[i][1];

            truckSize -= boxes;

            if(truckSize == 0)
                break;
        }

        return ans;
    }
};