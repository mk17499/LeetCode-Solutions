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
    int i = 0;
    int *p = &i;
    int arr[100002];
    int brr[100002];
    void inorder(TreeNode *root,int *x,int arr[])
    {
        if(root!=NULL)
        {
            inorder(root->left,x,arr);
            arr[*x] = root->val;
            (*x)++;
            inorder(root->right,x,arr);
        }
    }
    int countNodes(TreeNode *root)
    {
       if(root == NULL)
          return 0;
       else
        {
            return 1 + countNodes(root->left) + countNodes(root->right); 
        }
    }
    bool isValidBST(TreeNode* root) {
        inorder(root,p,arr);
        int N = *p;
        for(int i = 0;i<N;i++)
            brr[i] = arr[i];
        
        sort(brr,brr+N);
        
        int flag = 1;
        for(int i = 0;i<N;i++)
        {
            if(arr[i] != brr[i])
            {
                flag = 0;
                break;
            }
        }
        for(int i = 0;i<N-1;i++)
            if(arr[i] == arr[i+1])
                flag = 0;
        
        return flag;
        
        
    }
};

// using the property that inorder traversal of BST results in output of nodes in ascending order
