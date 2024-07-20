class Solution{
    public:
    int solve(string &S1, string &S2)
    {
        int n=S1.length();
        int m=S2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                
                if(S1[i]==S2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                    maxi=max(maxi,dp[i][j]);
                }
                 
                else
                 dp[i][j]=0;
                
            }
            
        }
        return maxi;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
       return solve(S1,S2);
    }
};