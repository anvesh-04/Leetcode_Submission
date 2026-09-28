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
    int count=0;
    pair<int, int> f(TreeNode* root){
        if(root==nullptr) return {0, 0};
        pair<int, int> left = f(root->left);
        pair<int, int> right = f(root->right);

        int sum = left.first+right.first+root->val;
        int val = left.second+right.second+1;
        if(sum/val == root->val) count++;

        return {sum, val};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return count;
    }
};