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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *cover = new ListNode, *ptr = cover, *ptr_tail, *ptr_end;
    cover->next = head;
    while (ptr_tail = [](ListNode* ptr, int k) {
      while (ptr && k--) ptr = ptr->next;
      return ptr;
    }(ptr, k)) {
      ptr_end = ptr_tail->next;
      auto [new_head, new_tail] = Reverse(ptr->next, ptr_tail);
      ptr->next = new_head, new_tail->next = ptr_end;
      ptr = new_tail;
    }
    head = cover->next;
    delete cover;
    cover = ptr = ptr_tail = ptr_end = nullptr;
    return head;
  }
  std::pair<ListNode*, ListNode*> Reverse(ListNode* head, ListNode* tail) {
    std::deque<ListNode*> stack;
    ListNode* ptr = head;
    while (ptr != tail) {
      stack.push_back(ptr);
      ptr = ptr->next;
    }
    head = ptr;
    while (!stack.empty()) {
      ptr->next = stack.back();
      stack.pop_back();
      ptr = ptr->next;
    }
    return std::make_pair(head, ptr);
  }
};
