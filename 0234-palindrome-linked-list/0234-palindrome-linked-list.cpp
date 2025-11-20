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
    ListNode *reverse(ListNode *head) {
        ListNode *p=head;
        ListNode *q=NULL;
        while(p ) {
            ListNode *r=p->next;
            p->next=q;
            q=p;
            p=r;
        }return q;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }ListNode *mid=reverse(slow);
        fast=head;
        while(mid) {
            if(mid->val!=fast->val) return false;
            mid=mid->next;
            fast=fast->next;
        }return true;
    }
};