/*Design the logic to remove the duplicate elements from an Array and after the
deletion the array should containtheunique elements.*/

#include<iostream>
using namespace std;

void Display(int* arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
}

int Delete(int* arr, int n, int pos){
	int ind=pos-1;
	for(int i=ind; i<n-1; i++){
		arr[i]=arr[i+1];
		
	}
	
	return n-1;
} 


int main(){
    int arr[5]={1,2,1,5,2};
    int size=5;
    
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                size=Delete(arr,size,j+1);
                
            }
        }
    }
    
    
    Display(arr,size);
    return 0;
}
