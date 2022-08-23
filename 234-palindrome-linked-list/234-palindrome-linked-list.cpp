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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->next ;

        }
        curr=head;
        while(!s.empty())
        {
            if(s.top()->val!=curr->val)
                return false;
            curr=curr->next ;
            s.pop();
        }
        return true ;
    }
};