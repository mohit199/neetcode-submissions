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
    void reorderList(ListNode* head) {
        if(!head) return;

        ListNode* slow = head;
        ListNode* fast = head;
        // find the middle, slow is the middle
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the second half
        ListNode* secondHead = slow->next;
        slow->next= nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = secondHead;
        while(curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        secondHead = prev;

        // merge the two lists
        ListNode* l1 = head;
        ListNode* l2 = secondHead;
        while(l1 && l2)
        {
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next=l2;
            l2->next=temp1;
            l1 = temp1;
            l2 = temp2;

        }
    }
};
