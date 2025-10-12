/*Given a linked list, and an integer k, rotate the list to the left by k positions and return
the updated head.*/

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

ListNode* rotateLeft(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    ListNode* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    k = k % n;
    if (k == 0) return head;

    ListNode* newTail = head;
    for (int i = 1; i < k; i++) newTail = newTail->next;

    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printList(head);// Output:  1 2 3 4 5
    int k = 2;
    head = rotateLeft(head, k);

    printList(head); // Output: 3 4 5 1 2

    return 0;
}
