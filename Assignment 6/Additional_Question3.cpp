/*
Given a Doubly linked list containing n nodes. Reverse every group of k nodes.
If the number of nodes is not a multiple of k then left-out nodes are reversed as well.

Examples:
Input: 1<->2<->3<->4<->5<->6, k=2  Output: 2<->1<->4<->3<->6<->5
Input: k=4 Output: 4<->3<->2<->1<->6<->5
*/

#include <iostream>
using namespace std;

struct Node { int data; Node* prev; Node* next; Node(int v):data(v),prev(nullptr),next(nullptr){} };

Node* reverseGroup(Node* head, int k) {
    if (!head || k <= 1) return head;
    Node* cur = head;
    Node* newHead = nullptr;
    Node* groupPrevTail = nullptr;

    while (cur) {
        // count k nodes
        int cnt = 0; Node* temp = cur;
        while (temp && cnt < k) { temp = temp->next; cnt++; }
        // reverse cnt nodes starting at cur
        Node* prev = temp; Node* node = cur;
        for (int i=0;i<cnt;i++) {
            Node* nxt = node->next;
            node->next = prev;
            if (prev) prev->prev = node;
            prev = node;
            node = nxt;
        }
        // prev is new head of this reversed group
        if (!newHead) newHead = prev;
        if (groupPrevTail) { groupPrevTail->next = prev; prev->prev = groupPrevTail; }
        groupPrevTail = cur; // cur was group head, now tail
        cur = temp;
    }
    return newHead;
}

int main() {
    // build example 1<->2<->3<->4<->5<->6
    Node* head = new Node(1); Node* t = head;
    for (int i=2;i<=6;i++){ t->next = new Node(i); t->next->prev = t; t = t->next; }
    int k; cout<<"Enter k: "; cin>>k;
    head = reverseGroup(head, k);
    cout<<"Result: ";
    for (Node* p = head; p; p = p->next) cout<<p->data<<" ";
    cout<<"\n";
    return 0;
}
