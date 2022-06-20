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
    int size = 1;
    ListNode *ptr = head, *cover = new ListNode, *target;
    cover->next = head;
    while (ptr->next != nullptr) ++size, ptr = ptr->next;
    ptr->next = new ListNode;
    size -= n;
    ptr = cover;
    while (size--) ptr = ptr->next;
    target = ptr->next;
    ptr->next = target->next;
    delete target;
    head = cover->next;
    ptr = cover;
    while (ptr->next->next != nullptr) ptr = ptr->next;
    delete ptr->next;
    ptr->next = nullptr;
    delete cover;
    if (ptr == cover) head = nullptr;
    cover = nullptr;
    return head;
  }
};