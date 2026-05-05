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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // l1 = [5,4,3] ->    345
        // l2 = [5,6,4,1] -> 1465
        // carry -> 1810
        // l1 = [7] l2 = 8 -> 7 + 8 = 15 => 1 -> 5

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        
        int carry = 0;

        while (l1 != null || l2 != null || carry > 0) {
            int val1 = 0, val2 = 0;
            if (l1 != null) val1 = l1.val;
            if (l2 != null) val2 = l2.val;

            int sum = val1 + val2 + carry;

            int firstDigit = sum / 10;
            int lastDigit = sum % 10;

            carry = firstDigit;

            tail.next = new ListNode(lastDigit);

            // update the pointers
            tail = tail.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }

        return dummy.next;
    }
}
