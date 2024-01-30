//Leetcode - Merge K Sorted Lists - Hard
//https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        priority_queue<int,vector<int>, greater<int>> pq;// Min Heap
        for(int i = 0;i<lists.size();i++) // Inserting all the list elements into the min heap
        {
            ListNode* node = lists[i];
            while(node != NULL)
            {
                pq.push(node->val);
                node = node->next;
            }
        }
        if(pq.empty())
        {
            return NULL;
        }

        ListNode* node = new ListNode(pq.top());// Creating the first node
        pq.pop();
        ListNode* head = node; // Creating a head pointer and pointing it to the fist node
        while(!pq.empty())
        {
            node->next = new ListNode(pq.top());// Taking the next smallest element and creating a node with it and appending it to the list
            pq.pop();
            node = node->next;
        }
        return head;
    }
};

//APPROACH -2 : BY MERGING 2 LISTS AT A TIME AND THEN MERGING ANOTHER 2 LISTS JUST LIKE MERGE SORT
//BETTER RUNTIME  TIME COMPLEXITY - O(NLOGK) LOGK - NUMBER OF MERGES

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = lists.size();
        if(n == 0)
        {
            return NULL;
        }
        while(n>1)
        {
            for(int i = 0;i<n/2;i++)
            {
                lists[i] = merge(lists[i], lists[n-1-i]);
            }
            n = (n+1)/2;
        }
        return lists.front();        
    }
private:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        if(list1 == NULL)
        {
            return list2;
        }
        if(list2 == NULL)
        {
            return list1;
        }
        ListNode* head = NULL;
        if(list1->val<=list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
        ListNode* curr = head;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1 != NULL)
        {
            curr->next = list1;
        }
        else
        {
            curr->next = list2;
        }
        return head;
    }
};
