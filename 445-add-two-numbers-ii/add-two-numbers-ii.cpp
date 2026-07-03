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
    ListNode* reverse(ListNode *head){
        ListNode *curr=head,*prev=NULL,*front=NULL;
        while(curr){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int>st1;
       stack<int>st2;
       ListNode *temp1=l1,*temp2=l2;
       while(temp1){
        st1.push(temp1->val);
        temp1=temp1->next;
       }
       while(temp2){
        st2.push(temp2->val);
        temp2=temp2->next;
       }
       int carry=0,sum;
       ListNode *dummyhead=new ListNode(-1);
       ListNode *temp=dummyhead;
       while(!st1.empty() || !st2.empty()){
            sum=carry;
            if(!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum += st2.top();
                st2.pop();
            }
            ListNode *newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=newnode;
            carry=sum/10;
       }
       
       ListNode *head=reverse(dummyhead->next);

       if(carry!=0){
        ListNode *NODE=new ListNode(carry);
        NODE->next=head;
        return NODE;
       }

       return head;
    }
};