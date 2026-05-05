/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    // 20260505
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *a = head, *b = head;
        int n = 1;
        while(a->next)
        {
            a = a->next;
            ++n;
        }
        for(int i=0; i < (n-1-k%n); ++i) b = b->next;
        a->next = head;
        head = b->next;
        b->next = nullptr;
        return head;
    }
};