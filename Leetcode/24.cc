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
  ListNode* swapPairs(ListNode* head) {
    ListNode *cover = new ListNode, *ptr, *temp;
    cover->next = head;
    ptr = cover;
    while (ptr->next) ptr = ptr->next;
    ptr = cover;
    while (ptr->next && ptr->next->next) {
      temp = ptr->next;
      ptr->next = ptr->next->next;
      temp->next = temp->next->next;
      ptr->next->next = temp;
      ptr = ptr->next->next;
    }
    ptr = cover->next;
    delete cover;
    cover = nullptr;
    return ptr;
  }
};
