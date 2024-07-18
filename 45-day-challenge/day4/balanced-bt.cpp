#include <iostream>
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
    pair<bool,int>isBalancedTree(TreeNode*root)
    {
       if(root==NULL)
       {
           return make_pair(true,0);
       }
       pair<bool,int>left=isBalancedTree(root->left);
       pair<bool,int>right=isBalancedTree(root->right);
       bool leftAns=left.first;
       bool rightAns=right.first;
       bool check=abs(left.second-right.second)<=1;
       pair<bool,int>ans;
       ans.second=(max(left.second,right.second)+1);
       if(leftAns && rightAns && check)
       {
         ans.first=(true);
       }
       else
       {
           ans.first=(false);
       }
       return ans;

    }
    bool isBalanced(TreeNode* root) {
        return isBalancedTree(root).first;
    }
};