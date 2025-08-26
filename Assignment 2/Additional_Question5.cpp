#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Duplicate2s(vector<int> &arr){
    int n=arr.size()-1;

    int possDups=0;
    for(int left=0; left<=n-possDups; left++){
        if (arr[left] == 2){

            if (left==n-possDups){
                arr[n]=2;
                n -= 1;
                break;
            }
            possDups++;
        }
    }
    int high=n-possDups;

    for(int i=high; i>=0; i--){
        if(arr[i]==2){
            arr[i + possDups]=2;
            possDups--;
            arr[i+possDups]=2;
        }

        else{
            arr[i+possDups]=arr[i];
        }
    }
    //Time Copmplexity: O(2N)
}


int main(){
    vector<int> arr={4,3,0,2,9,5,2,2,7,2,8,2};
    Duplicate2s(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}
