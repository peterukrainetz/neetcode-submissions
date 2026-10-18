/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        unordered_map<Node*, Node*> copyOf;

        while (curr)
        {
            Node* newNode = new Node(curr->val);
            copyOf[curr] = newNode;
            curr = curr->next;
        }

        curr = head;

        while (curr)
        {
            copyOf[curr]->next = copyOf[curr->next];
            copyOf[curr]->random = copyOf[curr->random];
            curr = curr->next;
        }

        return copyOf[head];
    }
};
