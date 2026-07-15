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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL) return NULL;

        unordered_map<int,ListNode*>mpp;

        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *temp=dummy;
        int prefixsum=0;

        while(temp!=NULL){
            prefixsum += temp->val;
            mpp[prefixsum]=temp;
            temp=temp->next;
        }

        prefixsum=0;
        temp=dummy;
        while(temp!=NULL){
            prefixsum += temp->val;
            temp->next = mpp[prefixsum]->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};