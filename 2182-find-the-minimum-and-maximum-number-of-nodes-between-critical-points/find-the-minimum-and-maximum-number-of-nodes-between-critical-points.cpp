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

        vector<int> critical;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;

        while (curr != nullptr && curr->next != nullptr) {

            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                critical.push_back(position);
            }

            prev = curr;
            curr = next;
            position++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int minDistance = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            minDistance = min(minDistance,
                              critical[i] - critical[i - 1]);
        }

        int maxDistance = critical.back() - critical.front();

        return {minDistance, maxDistance};
    }
};