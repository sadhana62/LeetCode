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
        priority_queue<int,vector<int>, greater<int>> pq;
        for (auto ele : lists) {
            ListNode* temp = ele;
            while(temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if (pq.size() == 0) return nullptr;
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* temp;
        temp =  head;
        while (!pq.empty()) {
          ListNode* newNode = new ListNode(pq.top());
          pq.pop();
          temp->next = newNode;
          temp = temp->next;
        }
        return head;
    }
};