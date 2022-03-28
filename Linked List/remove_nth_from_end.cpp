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
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            length += 1;
        }
        ListNode* prev = nullptr;
        temp = head;
        for (int i = 0; i < length - n; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            head = head->next;
        }
        else {
            prev->next = prev->next->next;
        }
        return head;
    }
};