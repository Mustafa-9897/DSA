class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps=0;
        int water=capacity;
        for(int i=0;i<plants.size();i++){
            if(water<plants[i]){
                steps += 2*i;      // when you are at plant i ,if the (i+1)th plant needs 
                water = capacity;  // more water than current capacity then we are walking to the river from the ith position and not from position i+1 and while returning back to water the plant i+1 we are walking i+1 steps so total=2*i+1
            }
            steps += 1;
            water -= plants[i];
        }
        return steps;
    }
};