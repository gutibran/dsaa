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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // edge case -> garmanarnarr
        if (!list1 && !list2) {
            return list1;
        } else if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }


        // allocate a new node in the heap
        ListNode* result = new ListNode { 0 };
        ListNode* r = result;
        
        // iterate through both lists
        while (list1 && list2) {
            // check if the nodes
            if (list1->val <= list2->val) {
                cout << list1->val << endl;
                result->next = list1;
                list1 = list1->next; 
            } else if (list2->val <= list1->val) {
                cout << list2->val << endl;
                result->next = list2;
                list2 = list2->next;
            }
            result = result->next;
        }
        
        // add remaining nodes from the longer list
        if (!list2) {
            while (list1) {
                result->next = list1;
                list1 = list1->next;
                result = result->next;
            }
        }
        
        if (!list1) {
            while (list2) {
                result->next = list2;
                list2 = list2->next;
                result = result->next;
            }
        }

        return r->next;
    }
};