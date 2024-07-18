
  Definition for a binary tree node.
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
    bool solve(TreeNode* root,int sum,int targetSum)
    {
        if(!root)
         return false;
        sum=sum+root->val;
        if(!(root->left) && !(root->right))
         return (sum==targetSum);
        
         return solve(root->left,sum,targetSum)||solve(root->right,sum,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};