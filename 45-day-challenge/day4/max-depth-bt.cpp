#include<iostream>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
         return 0;
        int lheight=maxDepth(root->left);
        int rheight=maxDepth(root->right);
        return max(lheight,rheight)+1;

    }
};