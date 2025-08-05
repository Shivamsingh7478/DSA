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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;


        while(curr!=NULL)
        {
            ListNode* forw = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }



    vector<int> nextLargerNodes(ListNode* head) {
        head = reverseLL(head);

        stack<int> st;
        
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL)
        {
            int element = temp->val;

            while(!st.empty() && st.top() <= element)
            {
                st.pop();
            }

            if(st.empty())
            {
                ans.push_back(0);
            }
            else{
            ans.push_back(st.top());
            }

            st.push(element);

            temp = temp->next;

        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};