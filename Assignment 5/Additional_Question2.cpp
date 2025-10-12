/*Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining
nodes after multiples of k should be left as it is.*/

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
ListNode* FindKth(ListNode* head, int k) {
        ListNode* temp = head;
        while (k > 1 && temp != NULL) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* Newhead = reverseList(head->next);

        ListNode* front = head->next;

        front->next = head;

        head->next = NULL;

        return Newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        ListNode* prevlast = NULL;

        while (temp != NULL) {
            ListNode* KthNode = FindKth(temp, k);

            if (KthNode == NULL) {
                if (prevlast) {
                    prevlast->next = temp;
                }
                break;
            }
            ListNode* KthNext = KthNode->next;

            KthNode->next = NULL;

            reverseList(temp);

            if (temp == head) {
                head = KthNode;
            } else {
                prevlast->next = KthNode;
            }
            prevlast = temp;
            temp = KthNext;
        }
        return head;
    }

    void displayList(ListNode* head) {
    ListNode* temp = head;
    if (!temp) { cout << "Empty List"; return; }
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << "\n";
}

     int main() {
    
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    //linked list: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;
    cout << "Original List A: ";
    displayList(headA);

   headA = reverseKGroup(headA, 2);

   cout << "Reversed List A: ";
   displayList(headA);

    return 0;
}