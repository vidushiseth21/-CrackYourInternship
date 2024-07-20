/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root)
         return result;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToright=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>ans(size);
            for(int i=0;i<size;i++)
            {
                TreeNode*frontNode=q.front();
                q.pop();
                int index=leftToright?i:size-i-1;
                ans[index]=frontNode->val;
                if(frontNode->left)
                 q.push(frontNode->left);
                if(frontNode->right)
                 q.push(frontNode->right);
            }
            leftToright=!leftToright;
            
            result.push_back(ans);
        }
        return result;
    }
};