//Leetcode - Removing Nth Node form the end of the List - Medium
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        if(head == NULL)
        {
            return head;
        }
        ListNode *start = head;
        while(start!=NULL) // Count the number of Nodes
        {
            m++;
            start = start->next;
        }
        if(n>m)
        {
            return head;
        }
        int k = 0;
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *ne = head->next;
        while(k!= m-n)// Nth node form the end is m-n+1 th from the beginning. But since k starts from 0 it is k!=m-n
        {
            prev = cur;
            cur = ne;
            ne = ne->next;
            k++;
        }
        if(prev!=NULL)
        {
        prev->next = ne;
        }
        else
        {
            head = ne;
        }
        delete cur;
        return head;
        
    }
};
