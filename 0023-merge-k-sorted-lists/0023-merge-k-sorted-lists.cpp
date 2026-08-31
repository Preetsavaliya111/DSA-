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
struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val; //min heap
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp>pq;

        for(auto node : lists){
            if(node != NULL)
            pq.push(node);
        }

        if(pq.empty()) return nullptr;

        ListNode* head = pq.top();
        ListNode* tail = head;
        pq.pop();

        if(head->next){
            pq.push(head->next);
        }

        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if(smallest->next){
                pq.push(smallest->next);
            }
        }

        return head;
    }


};