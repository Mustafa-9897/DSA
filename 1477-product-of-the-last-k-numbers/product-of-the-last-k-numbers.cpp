class ProductOfNumbers {
public:
    // vector<int>nums;
    // ProductOfNumbers() {
    //     nums={};
    // }
    
    // void add(int num) {
    //     nums.push_back(num);
    // }
    
    // int getProduct(int k) {
    //     int cnt=0;
    //     long long ans=1;
    //     for(int i=nums.size()-1;i>=0;i--){
    //         ans *= nums[i];
    //         cnt++;
    //         if(cnt==k) break;
    //     }
    //     return ans;
    // }

    //   OPTIMAL
    vector<int>nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            nums.clear();
            nums.push_back(1);
        }
        else{
            nums.push_back(num*nums.back());
        }
    }
    
    int getProduct(int k) {
        if(k>=nums.size()) return 0;
        return nums.back()/nums[nums.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */