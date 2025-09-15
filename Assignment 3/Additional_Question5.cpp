#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isStackSortable(vector<int>& A) {
    stack<int> S;
    vector<int> B;
    int n = A.size();
    int i = 0;
    int expected = 1;
    while (i < n || !S.empty()) {
        if (!S.empty() && S.top() == expected) {
            B.push_back(S.top());
            S.pop();
            expected++;
        } else if (i < n) {
            S.push(A[i]);
            i++;
        } else {
            return false;
        }
    }
    for (int j = 1; j < B.size(); j++) {
        if (B[j] < B[j - 1]) return false;
    }
    return true;
}

int main() {
    
    vector<int> A={1,3,4,2};
    
    if (isStackSortable(A)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
