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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* front = new ListNode();
    ListNode* result = front;
    int carry = 0;
    while (true) {
      front->val = carry;
      if (l1) {
        front->val += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        front->val += l2->val;
        l2 = l2->next;
      }
      carry = front->val / 10;
      front->val %= 10;
      if (carry == 0 && l1 == nullptr && l2 == nullptr) break;
      front->next = new ListNode();
      front = front->next;
    }
    return result;
  }
};
