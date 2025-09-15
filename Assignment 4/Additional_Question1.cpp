#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generateBinary(int n) {
    vector<string> result;
    if (n <= 0) return result;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();
        result.push_back(s);
        q.push(s + "0");
        q.push(s + "1");
    }
    return result;
}

void printBinaryNumbers(vector<string>& nums) {
    for (string s : nums)
        cout << s << " ";
    cout << "\n";
}

int main() {
    int n=5;
    
    vector<string> binaries = generateBinary(n);
    printBinaryNumbers(binaries);
    return 0;
}
