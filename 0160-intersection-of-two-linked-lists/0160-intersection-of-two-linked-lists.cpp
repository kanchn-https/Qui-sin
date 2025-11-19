/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *p=headA;
        map<ListNode*,int> mpp;
        int i=0;
        while(p) {
            mpp[p]++;
            p=p->next;
        }ListNode *q=headB;
        while(q) {
            if(mpp[q]>0) return q;
            q=q->next;
        }return NULL;
    }
};