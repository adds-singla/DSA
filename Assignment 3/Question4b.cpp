/*Write a program to convert an Infix expression into a Prefix expression.*/
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}





string Infix2Prefix(string &s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;
    string ans = "";
    int i = 0;
    int n = s.length();

    while (i < n) {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && 
      (priority(s[i]) < priority(st.top()) || 
      (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
    ans += st.top();
    st.pop();
}

            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;


    //Time Complexity: O(N)+O(N)
    //Space Complexity: O(N)+O(N)
}

int main(){
    string Inf="a+b*c";
    string Pof=Infix2Prefix(Inf);
    cout<<Pof;
    return 0;
}
