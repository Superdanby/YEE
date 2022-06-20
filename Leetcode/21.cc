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
    ListNode *merged = new ListNode, *ptr;
    ptr = merged;
    while (list1 != nullptr || list2 != nullptr) {
      if (list1 == nullptr) {
        ptr->next = list2;
        break;
      }
      if (list2 == nullptr) {
        ptr->next = list1;
        break;
      }
      if (list1->val < list2->val) {
        ptr->next = list1;
        while (list1->next != nullptr && list1->next->val <= list2->val)
          list1 = list1->next;
        ptr = list1, list1 = list1->next;
      } else {
        ptr->next = list2;
        while (list2->next != nullptr && list2->next->val <= list1->val)
          list2 = list2->next;
        ptr = list2, list2 = list2->next;
      }
    }
    ptr = merged->next;
    delete merged, merged = nullptr;
    return ptr;
  }
};