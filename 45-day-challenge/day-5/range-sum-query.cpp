class NumArray {
private:
    vector<int>prefixSum;
public:
    NumArray(vector<int>& nums) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int leftS;
        if(left>0)
         leftS=prefixSum[left-1];
        else
         leftS=0;
        int rightS=prefixSum[right];
        return rightS-leftS;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */