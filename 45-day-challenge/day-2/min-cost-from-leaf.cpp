class Solution {
public:
    int solve(vector<int>& arr,vector<vector<int>> &dp,map<pair<int,int>,int>&m,int start,int end)
    {
        if(start==end)
         return 0;
        if(dp[start][end]!=-1)
         return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<end;i++)
        {
            ans=min(ans,m[{start,i}]*m[{i+1,end}]+solve(arr,dp,m,start,i)+solve(arr,dp,m,i+1,end));
        }
        return dp[start][end]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        map<pair<int,int>,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++)
            {
                m[{i,j}]=max(arr[j],m[{i,j-1}]);
            }
        }
        return solve(arr,dp,m,0,n-1);
    }
};