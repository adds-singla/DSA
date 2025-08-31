/*Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
array in order of their appearance in the array. Note: The Next Greater Element for an element x is
the first greater element on the right side of x in the array. Elements for which no greater element
exist, consider the next greater element as -1.*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> nextLargerElement(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nle(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            nle[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        return nle;
        //Time Complexity: O(N)+O(N)
        //Space Complexity: O(N)
    }

    void Display(const vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<"\t";
        }
    }

     int main(){
        vector<int>arr={2,4,3,1,8,5,9,88};
        
        vector<int>nge=nextLargerElement(arr);

        Display(nge);
        return 0;
    }
