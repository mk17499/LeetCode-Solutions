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
void lot(TreeNode *root,vector<int> &v,int *height,int curr_height)
{
    if(root == NULL)
        return;
    else
    {
        if(curr_height > (*height))
        {
            v.push_back(root->val);
            (*height)++;
        }
        lot(root->right,v,height,curr_height + 1);
        lot(root->left,v,height,curr_height + 1);
    }
}
int countNodes(TreeNode *root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + countNodes(root->right) + countNodes(root->left);
}
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        int height = 0;
        int *p = &height;
        int N = countNodes(root);
        vector<int> v;
        int current_height = 1;
        if(N == 0)
            return v;
        else
            lot(root,v,p,current_height);
        
        return v;
    }
};
