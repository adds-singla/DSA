/*Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
The lists may vary in length and have distinct nodes at the beginning, but from the point of
intersection onward, they share the same sequence of nodes. The task is to identify the first
common node where the two lists converge. If the two linked lists have no intersection at all,
return null.*/

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;

        while (d1 != d2) {
            d1 = d1 == NULL ? headB : d1->next;
            d2 = d2 == NULL ? headA : d2->next;
        }
        return d1;
    }

    int main() {
    
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // First linked list: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    // Second linked list: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

   
    ListNode* inter = getIntersectionNode(headA, headB);

    if (inter)
        cout << "Intersection at node with value: " << inter->val << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}