/*String Split Challenge
You are given a string consisting of lowercase English alphabets. Your task is to determine
if it's possible to split this string into three non-empty parts (substrings) where one of
these parts is a substring of both remaining parts*/

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


    return false;
    //Time Complexity: O(N)
    //Space Complexity: O(26);
}


int main(){
    
    string s="ababa";
    cout<<(canSplit(s) ? "Yes" : "No");
    
    return 0;
}
