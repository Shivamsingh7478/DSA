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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(-1); // dummy head
        ListNode tail = dummy;             // tail of merged list

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;   // attach list1 node
                list1 = list1.next;  // move list1 ahead
            } else {
                tail.next = list2;   // attach list2 node
                list2 = list2.next;  // move list2 ahead
            }
            tail = tail.next;        // move tail
        }

        // Attach remaining nodes
        if (list1 != null) {
            tail.next = list1;
        } else {
            tail.next = list2;
        }

        return dummy.next; // skip dummy
    }
}