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
    vector<vector<TreeNode*>> traversal(TreeNode * node) {
        vector<vector<TreeNode*>> bfs;
        if(!node) return bfs;
        queue<TreeNode*> q;
		q.push(node);
		while(!q.empty()) {
			int size=q.size();
			vector<TreeNode*> arr;
			for(int i=0;i<size;i++) {
				TreeNode * node=q.front();
				q.pop();
				arr.push_back(node);
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			}bfs.insert(bfs.begin(),arr);
		}return bfs;
    }
    bool find(TreeNode* root, int target) {
        if(!root) return false;
        if(root->val==target) return true;
        return find(root->left,target)|| find(root->right,target);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> bfs=traversal(root);
        vector<int> deep;
        for(TreeNode* node: bfs[0]) deep.push_back(node->val);
        for(auto&level: bfs) {
            for(TreeNode *node:level) {
                bool flag=true;
                for(int val: deep) {
                    if(!find(node,val)){
                        flag=false;
                        break;
                    }
                }if(flag) return node;
            }
        }return NULL;
    }
};