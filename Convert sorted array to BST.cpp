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
    TreeNode *creatTree(TreeNode *root,vector<int> &v,int lo,int hi)
    {
        if(lo > hi)
            return NULL;
        else
        {
            int mid = lo + (hi-lo)/2;
            TreeNode *t = new TreeNode;
            t->val = v[mid];
            t->left = creatTree(t->left,v,lo,mid-1);
            t->right = creatTree(t->right,v,mid+1,hi);
            
            return t;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root;
        int lo = 0;
        int hi = nums.size()-1;
        
        root = creatTree(root,nums,lo,hi);
        
        return root;
    }
};
