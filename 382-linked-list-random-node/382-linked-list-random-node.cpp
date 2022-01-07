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
    vector<int>A;
    int n;
public:
    Solution(ListNode* head) {
        n=0;
        while(head)
        {
            A.push_back(head->val);
            head=head->next;
            n++;
        }
    }
    
    int getRandom() {
        int i = rand()%n;
        return A[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */