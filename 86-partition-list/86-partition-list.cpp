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
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr=head;
        ListNode *less=NULL,*greater=NULL,*lessStart=NULL,*greatStart=NULL;
        while(curr!=NULL){
            if(curr->val<x){
                if(!less){
                    less=curr;
                    lessStart=curr;
                }
                else{
                    less->next=curr;
                    less=less->next;
                }
            }
            else{
                if(!greater){
                    greater=curr;
                    greatStart=curr;
                }
                else{
                    greater->next=curr;
                    greater=greater->next;
                }
            }
            curr=curr->next;
        }
        if(!less){
            return greatStart;
        }
        else if(!greater){
            return lessStart;
        }
        greater->next=NULL;
        less->next=greatStart;
        return lessStart;
    }
};