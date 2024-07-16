class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxFrequency=0;
        int maxAns=0;
        int n=nums.size();
        unordered_map<int,int>count;
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
            if(count[nums[i]]>maxFrequency){
            maxFrequency=max(maxFrequency,count[nums[i]]);
            maxAns=nums[i];}
        }
        return maxAns;
        
    }
};