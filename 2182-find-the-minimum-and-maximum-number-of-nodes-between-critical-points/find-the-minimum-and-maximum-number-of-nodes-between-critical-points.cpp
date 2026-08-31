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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;

        int first = -1;
        int last = -1;
        int previous = -1;

        int minDistance = INT_MAX;

        while (curr != nullptr && curr->next != nullptr) {

            ListNode* next = curr->next;

            bool critical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (critical) {

                if (first == -1) {
                    // First critical point
                    first = position;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(
                        minDistance,
                        position - previous
                    );
                }

                previous = position;
                last = position;
            }

            prev = curr;
            curr = next;
            position++;
        }

        if (first == -1 || first == last)
            return {-1, -1};

        int maxDistance = last - first;

        return {minDistance, maxDistance};
    }
};