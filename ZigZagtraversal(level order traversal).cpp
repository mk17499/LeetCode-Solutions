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
    int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
void printCurrentLevelleft(TreeNode* root, int level,int row,vector<vector<int> > &ans)
{
    if (root == NULL)
        return;
    if (level == 1)
        ans[row].push_back(root->val);
    else if (level > 1) 
    {
        printCurrentLevelleft(root->left, level - 1,row,ans);
        printCurrentLevelleft(root->right, level - 1,row,ans);
    }
}
void printCurrentLevelright(TreeNode* root, int level,int row,vector<vector<int> > &ans)
{
    if (root == NULL)
        return;
    if (level == 1)
        ans[row].push_back(root->val);
    else if (level > 1) 
    {
        printCurrentLevelright(root->right, level - 1,row,ans);
        printCurrentLevelright(root->left, level - 1,row,ans);
    }
}
void printLevelOrder(TreeNode* root,vector<vector<int> > &ans)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        if(i%2 == 0)
            printCurrentLevelright(root, i,i-1,ans);
        else
            printCurrentLevelleft(root,i,i-1,ans);
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        int rows = height(root);
        
        vector<vector<int>> ans(rows);
        printLevelOrder(root,ans);
        
        return ans;
    }
};
