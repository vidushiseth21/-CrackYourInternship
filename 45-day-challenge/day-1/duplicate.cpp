class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            int count=0;
            for(auto num:nums)
            {
                if(num<=mid)
                 count++;
            }
            if(count>mid)
             r=mid;
            else
             l=mid+1;
        }
        return l;
    }
};