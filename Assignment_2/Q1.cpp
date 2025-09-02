#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> &nums , int target){
    int high = nums.size() - 1;
    int low = 0;
    int mid;

    while(high>=low){
        mid = low + (high-low)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            high = mid - 1;
        }else{
            low = mid +1;
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    cout<<binary_search(nums,4);
    return 0;
}