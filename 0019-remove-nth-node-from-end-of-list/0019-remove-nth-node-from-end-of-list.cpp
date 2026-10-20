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
    int len(ListNode* head) {
        int c = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int pos = len(head) - n +1;
        // if (pos == 1 && head->next == NULL) return nullptr;
        // if (pos == 1 && head->next != NULL) {
        //     head = head->next;
        //     return head;
      
        // }
        // int c = 0;
        // ListNode* temp = head;
        // while(temp != NULL && temp->next ) {
        //   c++;
        //   if (c == (pos-1)) {
        //      temp->next = temp->next->next;
        //      break;
        //   }
        //   temp = temp->next;
        // }
        // return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* slow = dummyNode;
        ListNode* fast = dummyNode;
        for (int i =0;i<n;i++) {
            fast = fast->next;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return dummyNode->next;
    }
};