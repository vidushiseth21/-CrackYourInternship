class Solution {
  public:
    bool dfs(vector<int>&visited,vector<int>&pathVisited,int node,vector<int> adj[])
    {
        visited[node]=1;
        pathVisited[node]=1;
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                if(dfs(visited,pathVisited,i,adj))
                 return true;
            }
            else if(pathVisited[i])
             return true;
            
        }
        pathVisited[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>visited(V,0);
       vector<int>pathVisited(V,0);
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               if(dfs(visited,pathVisited,i,adj))
                return true;
           }
       }
       return false;
    }
};