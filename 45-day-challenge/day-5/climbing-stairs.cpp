class Solution {
public:
    int solve(int n)
    {
        if(n<=2)
         return n;
        int prev1=1;
        int prev2=2;
        int current=0;
        for(int i=2;i<n;i++)
        {
            current=prev1+prev2;
            prev1=prev2;
            prev2=current;
        }
        return current;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};