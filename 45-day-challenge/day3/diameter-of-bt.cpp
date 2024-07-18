class Solution {
public:
    int height(TreeNode*root)
    {
        if(!root)
         return 0;
        int lheight=height(root->left);
        int rheight=height(root->right);
        return max(lheight,rheight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
         return 0;
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=height(root->left)+height(root->right);
        return max(op1,max(op2,op3));
    }
};