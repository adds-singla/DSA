/*Given two polynomial numbers represented by two linked lists. The task is
to add these lists (meaning the coefficients with the same variable powers will be
added).*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() { val = 0; next = NULL; }
    ListNode(int data1) { val = data1; next = NULL; }
    ListNode(int data1, ListNode *next1) { val = data1; next = next1; }
};

// Function to add two polynomials represented by linked lists
ListNode* addPolynomials(ListNode* poly1, ListNode* poly2) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (poly1 && poly2) {
        tail->next = new ListNode(poly1->val + poly2->val);
        tail = tail->next;
        poly1 = poly1->next;
        poly2 = poly2->next;
    }

    while (poly1) {
        tail->next = new ListNode(poly1->val);
        tail = tail->next;
        poly1 = poly1->next;
    }

    while (poly2) {
        tail->next = new ListNode(poly2->val);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return dummy->next;
}

// Helper to print polynomial
void printPoly(ListNode* head) {
    int power = 0;
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << "x^" << power;
        if (temp->next) cout << " + ";
        temp = temp->next;
        power++;
    }
    cout << endl;
}

int main() {
    // Polynomial 1: 2 + 4x + 5x^2
    ListNode* poly1 = new ListNode(2);
    poly1->next = new ListNode(4);
    poly1->next->next = new ListNode(5);

    // Polynomial 2: 5 + 5x + 0x^2
    ListNode* poly2 = new ListNode(5);
    poly2->next = new ListNode(5);
    poly2->next->next = new ListNode(0);

    ListNode* sum = addPolynomials(poly1, poly2);

    cout << "Sum of polynomials: ";
    printPoly(sum);

    return 0;
}
