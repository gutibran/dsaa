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
    size_t count_nodes(ListNode* head) {
        size_t nodes = { 0 };
        for (size_t i = 0; head; head = head->next) {
            nodes++;
        }
        return nodes;
    }
    
    ListNode* middleNode(ListNode* head) {
        size_t middle_index = floor(this->count_nodes(head) / 2);
        size_t i = 0;
        ListNode* result;
        while (head) {
            if (i == middle_index) {
                result = head; 
            }
            head = head->next;
            i++;
        }
        
        cout << result->val;
        return result;
    }
};