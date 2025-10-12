/*The school cafeteria offers circular and square sandwiches at lunch break, referred to by
numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
sandwiches are placed in a stack. At each step:
• If the student at the front of the queue prefers the sandwich on the top of the stack, they will take
it and leave the queue.
• Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus
unable to eat*/

#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count0 = 0, count1 = 0;
    for (int s : students) {
        if (s == 0) count0++;
        else count1++;
    }

    for (int s : sandwiches) {
        if (s == 0) {
            if (count0 == 0) return count1;
            count0--;
        } else {
            if (count1 == 0) return count0;
            count1--;
        }
    }
    return 0;
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    cout << countStudents(students, sandwiches) << endl;
    return 0;
}
