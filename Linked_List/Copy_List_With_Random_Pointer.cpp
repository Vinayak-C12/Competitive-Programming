//Leetcode - Cpoy list with Random pointer - Medium
//https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> um;// Hashmap to store link between old nodes and copy
        um[NULL] = NULL;
        Node* h = head;
        while(h)
        {
            um[h] = new Node(h->val);// Creating new nodes and storing links in hashmap
            h = h->next;
        }
        h = head;
        while(h)
        {
            Node* copy = um[h];
            copy->next = um[h->next];
            copy->random = um[h->random];
            h = h->next;
        }
        
        return um[head];
        
    }
};
