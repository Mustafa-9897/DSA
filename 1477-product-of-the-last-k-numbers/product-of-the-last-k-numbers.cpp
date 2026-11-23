class ProductOfNumbers {
public:
    vector<int>nums;
    ProductOfNumbers() {
        nums={};
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int cnt=0;
        long long ans=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans *= nums[i];
            cnt++;
            if(cnt==k) break;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */