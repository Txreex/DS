#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int> &nums){
    int n = nums.size();

    for(int i = 0 ; i < n-1 ; i++){
        int sorted = true;
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(nums[j] > nums[j+1]){
                std::swap(nums[j] , nums[j+1]);
                sorted = false;
            }
        }
        if(sorted){
            return;
        }
    }
}

int main(){
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    bubble_sort(nums);
    for(int i = 0 ; i < nums.size() ; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}