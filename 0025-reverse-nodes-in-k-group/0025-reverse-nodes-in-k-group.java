/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) return head;

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode groupPrev = dummy;

        while (true) {
            // find kth node from groupPrev
            ListNode kth = getKth(groupPrev, k);
            if (kth == null) break;  // less than k nodes left

            ListNode groupNext = kth.next;

            // reverse group [groupPrev.next ... kth]
            ListNode prev = groupNext;
            ListNode curr = groupPrev.next;

            while (curr != groupNext) {
                ListNode tmp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = tmp;
            }

            // connect reversed group
            ListNode tmp = groupPrev.next; // this becomes end of group
            groupPrev.next = kth;          // new head of group
            groupPrev = tmp;               // move groupPrev to end
        }

        return dummy.next;
    }

    // returns kth node from node (1-based), or null if not enough nodes
    private ListNode getKth(ListNode node, int k) {
        while (node != null && k > 0) {
            node = node.next;
            k--;
        }
        return node;

    }
}