#include<iostream>
#include<vector>
using namespace std;

void imp_selection_sort(vector<int> &nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low < high){
        int mini = low;
        int maxi = high;

        for(int j = low ; j <= high ; j++){
            if(nums[j] < nums[mini]){
                mini = j;
            }
            if(nums[j] > nums[maxi]){
                maxi = j;
            }
        }

        if(mini != low){
            swap(nums[mini] , nums[low]);
        }

        if(maxi == low){
            maxi = mini;
        }

        if(maxi != high){
            swap(nums[maxi] , nums[high]);
        }

        low++;
        high--;
    }
}

int main(){
    vector<int> nums = {23 , 42 , 1, 0 , -1 , 1, 1, 1, 1 ,78};
    imp_selection_sort(nums);

    for(int el : nums ){
        cout<<el<<" ";
    }

    return 0;
}