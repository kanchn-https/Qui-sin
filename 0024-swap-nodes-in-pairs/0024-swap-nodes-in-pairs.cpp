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
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy=new ListNode(-1);
        ListNode *newHead=dummy;
        ListNode *p=dummy;
        ListNode *q=head;
        while(q && q->next) {
            ListNode *r=q->next;
            ListNode *next=r->next;
            p->next=r;
            r->next=q;
            q->next=next;
            p=q;
            q=next;
        }return newHead->next;
    }
};