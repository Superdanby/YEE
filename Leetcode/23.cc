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
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(
        cmp);
    for (const auto& head : lists)
      if (head) pq.push(head);
    ListNode* cover = new ListNode;
    ListNode* ptr = cover;
    while (!pq.empty()) {
      auto next = pq.top();
      pq.pop();
      ptr->next = next;
      ptr = ptr->next;
      if (ptr->next) pq.push(ptr->next);
    }
    ptr->next = nullptr;
    ptr = cover->next;
    delete cover;
    cover = nullptr;
    return ptr;
  }
};
