class Solution {
public:
    int solve(vector<int>& prices)
    {
        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    int buy1=-prices[index]+next[0];
                    int ignore1=next[1];
                    profit=max(buy1,ignore1);
                }
                else
                {
                    int sell1=prices[index]+next[1];
                    int ignore2=next[0];
                    profit=max(sell1,ignore2);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        
        return next[1];

    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};