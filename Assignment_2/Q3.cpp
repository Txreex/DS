#include<iostream>
#include<vector>
using namespace std;

int missing_lin(vector<int> &nums){
    int n = nums.size();
    int N = n+1;
    int sum = (N*(N+1))/2;

    for(int i = 0 ; i < n ; i++){
        sum -= nums[i];
    }

    return sum;
}

int missing_bin(vector<int> &nums){
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low + 1; 
}




int main(){
    vector<int> nums = {1,2,3,5};
    // cout<<missing_lin(nums)<<endl;
    cout<<missing_bin(nums)<<endl;
    return 0;
}