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
    int siz(ListNode *head){
        int s=0;
        while(head!=NULL){
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(head==NULL){
            return head;
        }
        int l=left,r=right;
        ListNode *temp=head;
        ListNode* leftnode,*leftmost=NULL,*rightnode,*rightmost;
        while(temp!=NULL && left!=1){
            leftmost=temp;
            temp=temp->next;
            left--;
        }
        leftnode=temp;
        temp=head;
        while(temp!=NULL && right!=1){
            temp=temp->next;
            right--;
        }
        rightnode=temp;
        rightmost=rightnode->next;
        //cout<<rightnode->val<< " a"<<leftnode->val<<endl;
        int s=siz(head);
        ListNode *curr=leftnode->next,*prev=leftnode,*next1=leftnode->next;
        prev->next=NULL;
        while(curr!=NULL && next1!=rightmost){
            next1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
        }
        if(l!=1){
            cout<<prev->val<<" ";
            leftmost->next=prev;
        }
        leftnode->next=curr;
        if(l==1 && r==s){
            return prev;
        }
        if(l==1){
            return prev;
        }
        else{
            return head;
        }
    }
};