//Leetcode - Reorder List - Medium
//https://leetcode.com/problems/reorder-list/description/

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
        if(head->next == NULL)// Only 1 node Present
        {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;// To find the mid point
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;// Slow will point to the last node of first partition and second points to the first node of second partition
        ListNode *prev = NULL;
        slow->next = NULL;// Bcoz we have to separate the 2 lists
        while(second!=NULL)// Reversing the second list
        {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        ListNode *first = head;
        second = prev;
        while(second!=NULL)// Bcoz the second partition will be smaller
        {
            ListNode *temp1 = first->next;// Joining the 2 lists
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

        
    }
};
