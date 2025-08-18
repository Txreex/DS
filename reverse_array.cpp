#include<iostream>
using namespace std;

void swap(int &a , int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void rev(int arr[] , int n){
    int i = 0 ; 
    int j = n-1 ; 

    while(i < j){
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

int main(){
    int nums[] = {1,2,3,4,5};
    int n = sizeof(nums)/sizeof(nums[0]);
    rev(nums , n);
    
    for(int i = 0 ; i < n ; i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}