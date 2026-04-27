/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        // create a map of new nodes
        // link the nodes together from the map

        if (head == null) return null;

        Node dummy = head;
        Node tail = dummy;

        Map<Node, Node> nodeCopies = new HashMap<>();

        while (head != null) {
            nodeCopies.put(head, new Node(head.val));
            head = head.next;
        }

        while (tail != null) {
            Node currentNode = nodeCopies.get(tail);
            currentNode.next = nodeCopies.get(tail.next);
            currentNode.random = nodeCopies.get(tail.random);

            tail = tail.next;
        }

        return nodeCopies.get(dummy);
    }
}
