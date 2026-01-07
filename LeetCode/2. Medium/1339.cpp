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
// 20260107 二元樹 DFS
public:
    const int M = 1e9+7;
    vector<long long> sum;
    long long DFS(TreeNode* node)
    {
        if(!node) return 0;
        long long sub = node->val + DFS(node->left) + DFS(node->right);
        sum.emplace_back(sub);
        return sub;
    }
    int maxProduct(TreeNode* root) {
        DFS(root);
        long long total = sum.back(), mx = -1; sum.pop_back();
        for(int i : sum) mx = max(mx, i * (total - i));
        return mx % M;
    }
};