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
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        else
            return 1 + max(height(root->left) , height(root->right));
    }
    int balance(TreeNode *root)
    {
        if(root->left == NULL && root->right == NULL)
            return 1;
        else
        {
            int l = height(root->left);
            int r = height(root->right);
            
            int d = abs(l-r);
            
            if(d > 1)
                return -1;
            else
                return 1;
        }
    }
    void traverse(TreeNode *root,int *ans)
    {
        if(root == NULL)
            return ;
        else
        {
            int z = balance(root);
            if(z == -1)
            {
                *ans = 0;
                return;
            }
            else
            {
                traverse(root->left,ans);
                traverse(root->right,ans);
            }
        }
    }
    bool isBalanced(TreeNode* root) 
    {
        int ans = 1;
        int *p = &ans;
        
        traverse(root,p);
        
        if(*p == 0)
            return 0;
        else
            return 1;
    }
};
