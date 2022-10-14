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
    int size(ListNode * head){
        int x=0;
        while(head!=NULL){
            head=head->next;
            x++;
        }
        return x;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        int c=size(head);
        int t=c/2;
        ListNode *prev=NULL;
        ListNode *node=head;
        while(t--){
            prev=node;
            node = node->next;
        }
        prev->next=node->next;
        return head;
    }
};