#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool canSplit(string &st){
    int n=st.length();

    if(n<3) return false;

    vector<int>freq(26,0);
    for(char c:st) freq[c-'a']++;
    for(int f : freq){
        if(f>=3) return true;
    }

    char first = st[0], last = st[n - 1];
    if (first == last) {
        for (int i = 1; i < n - 1; i++) {
            if (st[i] == first) return true;
        }
    }


    return false;
    //Time Complexity: O(N)
    //Space Complexity: O(26);
}


int main(){
    
    string s="ababa";
    cout<<(canSplit(s) ? "Yes" : "No");
    
    return 0;
}
