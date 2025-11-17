#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> &nums){
    int n = nums.size();
    
    for(int i = 0 ; i < n ; i++){
        int min = i;
        for(int j = i+1 ; j < n ; j++){
            if(nums[j] < nums[min]){
                min = j;   
            }
        }
        if(min != i){
            swap(nums[i] , nums[min]);
        }
    }
}

void insertion_sort(vector<int> &nums){ 
    int n = nums.size();

    for(int i = 0 ; i < n ; i++){
        int temp = nums[i];
        int j = i - 1;
    
        while(j >= 0 && nums[j] > temp){
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = temp;
    }
}

void bubble_sort(vector<int> &nums){
    int n = nums.size();

    for(int i = 0 ; i < n-1 ; i++){
        int flag = 1;
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j] , nums[j+1]);
                flag = 0;
            }
        }
        if(flag){
            break;
        }
    }
}

void merge(vector<int> &nums , int start , int mid , int end){
    int l1 = mid - start + 1;
    int l2 = end - mid;

    vector<int> nums1(l1);
    vector<int> nums2(l2);

    for(int i = start ; i <= mid ; i++){
        nums1[i - start] = nums[i]; 
    }
    for(int i = mid+1 ; i <= end ; i++){
        nums2[i - mid - 1] = nums[i];
    }

    int p = 0;
    int q = 0;

    int i = start;

    while(p < l1 && q < l2){
        if(nums1[p] <= nums2[q]){
            nums[i] = nums1[p];
            i++;
            p++;
        }else if(nums1[p] > nums2[q]){
            nums[i] = nums2[q];
            i++;
            q++;
        }
    }

    while(p < l1){
        nums[i] = nums1[p];
        i++;
        p++;
    }

    while(q < l2){
        nums[i] = nums2[q];
        i++;
        q++;
    }
}

void merge_sort(vector<int> &nums , int start , int end){
    if(start >= end) return;

    int mid = start + (end - start)/2;

    merge_sort(nums , start , mid);
    merge_sort(nums , mid+1 , end);
    merge(nums , start , mid , end);
}


int pivot(vector<int> &nums , int low , int high){
    int piv = nums[high];

    int i = low-1;
    for(int j = low ; j < high ; j++){
        if(nums[j] < piv){
            i++;
            swap(nums[i] , nums[j]);
        }
    }

    i++;
    swap(nums[i] , nums[high]);

    return i;
}

void quick_sort(vector<int> &nums , int low , int high){
    if(low >= high) return;

    int piv = pivot(nums , low , high);

    quick_sort(nums , low , piv - 1);
    quick_sort(nums , piv + 1 , high);
}



int main(){
    vector<int> nums = {23 , 42 , 1, 0 , -1 , 78};
    quick_sort(nums , 0 , nums.size() -1 );

    for(int el : nums ){
        cout<<el<<" ";
    }

    return 0;
}