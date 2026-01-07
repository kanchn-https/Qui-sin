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
    long long ans=0,sum=0;
public:
    int pro(TreeNode *root) {
        if(!root) return 0;
        int curr=pro(root->left)+pro(root->right)+root->val;
        ans=max(ans,curr*(sum-curr));
        return curr;
    }
    int maxProduct(TreeNode* root) {
       sum=pro(root);
        pro(root);
        return ans%int(1e9+7);
    }
};