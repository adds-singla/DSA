/*Given an array of integers temperatures represents the daily temperatures, return an
array answer such that answer[i] is the number of days you have to wait after the ith day to get a
warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> nextWarmerTemp(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nwarmdays(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nwarmdays[i] = st.empty() ? 0 : (st.top()-i);
            st.push(i);
        }

        return nwarmdays;
        //Time Complexity: O(N)+O(N)
        //Space Complexity: O(N)
    }

    void Display(const vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<"\t";
        }
    }

     int main(){
        vector<int>temperature={2,4,3,1,8,5,9,88};
        
        vector<int>nge=nextWarmerTemp(temperature);

        Display(nge);
        return 0;
    }
