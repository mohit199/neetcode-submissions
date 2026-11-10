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
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[nullptr]=nullptr;

        Node* cur = head;
        while(cur != nullptr)
        {
            Node* node = new Node(cur->val);
            oldToNew[cur] = node;
            cur = cur->next;
        }

        cur = head;
        while(cur != nullptr)
        {
            Node* node = oldToNew[cur];
            node->next = oldToNew[cur->next];
            node->random = oldToNew[cur->random];
            cur = cur->next;
        }

        return oldToNew[head];
    }
};
