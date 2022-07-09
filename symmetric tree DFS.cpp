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
    int ans;
    void tree(TreeNode *A, TreeNode *B)
    {
        if(!ans)
            return;
        if(A==NULL && B==NULL)
            return;
        else if(A==NULL || B==NULL)
        {
            ans =0;
            return;
        }
        if(A->val!=B->val)
        {
            ans =0;
        }
        tree(A->left, B->right);
        tree(A->right, B->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        ans = 1;
        tree(root->left,root->right);
        
        return ans;
    }
};
