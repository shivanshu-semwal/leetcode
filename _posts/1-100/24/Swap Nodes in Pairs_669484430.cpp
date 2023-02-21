class Solution {
public:
    ListNode* swapPairs(ListNode*& head) {
        if(head&&head->next){
            ListNode** c=&head;
            ListNode* temp;
            while((*c)&&(*c)->next){
                temp = (*c)->next;
                (*c)->next = temp->next;
                temp->next = *c;
                *c = temp;
                c = &((*c)->next->next);
            }
        }
        return head;
    }
};
