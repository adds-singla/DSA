#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int CountPairs(vector<int>&arr,int k){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int totPairs=0;

    int i=0, j=0;

    while(j<n){
        if(i==j){
            j++;
            continue;
        }
        if(abs(arr[j]-arr[i])<k){
            j++;
        }

        else if(abs(arr[j]-arr[i])>k){
            i++;
        }

        else{
            int ele1=arr[i], ele2=arr[j];
            int cnt1=0, cnt2=0;

            while(i<n && arr[i]==ele1){
                i++;
                cnt1++;

            }

            while(j<n && arr[j]==ele2){
                j++;
                cnt2++;

            }
           if(ele1 == ele2){
            totPairs += (cnt1 * (cnt1-1))/2;
           }

           else{
            totPairs += cnt1*cnt2;
           }

        }
    }
    return totPairs;
}

int main(){
    vector<int>nums={1,4,6,2,8,4,4,10};
    int total_pairs=CountPairs(nums,2);
    cout<<total_pairs;
    
    
    
    return 0;
}