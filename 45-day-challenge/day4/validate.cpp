
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
    bool valid(TreeNode*root,long long int min,long long int max)
    {
        if(!root)
         return true;
        if(root->val>=min && root->val<=max)
        {
            bool left=valid(root->left,min,root->val-1LL);
            bool right=valid(root->right,root->val+1LL,max);
            return left && right;
        }
        else
         return false;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};