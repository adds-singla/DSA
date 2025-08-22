#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void SortedArray(vector <int> &dnf){
    int n=dnf.size();
    int low=0, mid=0, high=n-1;

    while(mid<high){
        if(dnf[mid]==0){
            swap(dnf[low],dnf[mid]);
            low++;
            mid++;
        }

        else if(dnf[mid]==1){
            mid++;
        }

        else{
            swap(dnf[mid],dnf[high]);
            high--;
        }
    }
    //Time Complexity: O(N)
    //Space Complexity: O(1)
}

int main(){
    vector<int>dnf={1,0,0,2,1,2,2,2,1,0};
    SortedArray(dnf);
    for(int i=0; i<dnf.size(); i++){
        cout<<dnf[i]<<"\t";
    }
    
    return 0;
}