/*Given a linked list, remove the loop if it exists.*/

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

void removeLoop(ListNode* head)
{
    if (!head || !head->next) return;
    ListNode* slow = head;
    ListNode* fast = head;
    bool loopFound = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopFound = true;
            break;
        }
    }
    if (loopFound) {
        slow = head;
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}

void printList(ListNode* head)
{
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;
    removeLoop(head);
    printList(head);
    return 0;
}
