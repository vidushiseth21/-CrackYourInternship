#include<stdio.h>
 #include<iostream>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void solve(TreeNode*root,string path,vector<string>&ans)
    {
        if(!root)
         return;
        path+=to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(path);
            
        }
        else{
            path=path+"->";
            solve(root->left,path,ans);
            solve(root->right,path,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        solve(root,"",ans);
        return ans;
    }
};