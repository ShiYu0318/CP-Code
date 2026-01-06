// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {    
// 20260106 O(n) 二元樹 BFS
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lv = 1, ans = 1, mx = INT_MIN;
        while(!q.empty())
        {
            int sum = 0;
            for(int i=0; i < q.size(); ++i)
            {
                TreeNode* node = q.front(); q.pop();
                sum += node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            if(sum > mx) { mx = sum; ans = lv; }
            ++lv;
        }
        return ans;
    }
};