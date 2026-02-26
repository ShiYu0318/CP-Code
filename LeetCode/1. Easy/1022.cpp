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
    // 20260226
    // O(N)
public:
    int DFS(TreeNode* node, int sum)
    {
        if(!node) return 0;
        sum = sum * 2 + node->val;
        if(!node->left && !node->right) return sum;
        return DFS(node->left, sum) + DFS(node->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return DFS(root, 0);
    }
};

// class Solution {
//     // 20260226
//     // O(N*H)  H := 樹高
// public:
//     int btd(string s)
//     {
//         int num = 0;
//         for(int i = s.size()-1, k = 0; i >= 0; --i, ++k) num += (s[i] == '1' ? (1 << k) : 0);
//         return num;
//     }

//     int DFS(TreeNode* node, string s)
//     {
//         if(!node) return 0;
//         s += char('0' + node->val);
//         if(!node->left && !node->right) return btd(s);
//         int num = 0;
//         num += DFS(node->left, s) + DFS(node->right, s);
//         return num;
//     }

//     int sumRootToLeaf(TreeNode* root) {
//         return DFS(root, "");
//     }
// };