#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// peak element means it should be greater than the left element and it should be greater than right element
// Like this  arr[i-1] < arr[i] > arr[i+1] , and this is the Peak Element

// arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1}; here peak element will be 8
// An Array can have multiple peaks 
int checkPeak(int arr[], int n){
    for(int i = 0;i< n; i++){
        if((i == 0 || arr[i-1] < arr[i]) && i == n-1 || arr[i] > arr[i+1]){
            return i;
        }
    }
    return -1;
}

// OPTIMAL SOLUTION
// SO WE WILL SEE A PEAK GRAPH LIKE MID > MID -1 SO THERE MUST BE NO PEAK AT LEFT BECAUSE OF INCREASING GRAPH
// SO WE ASSUME THIS AND MOVE RIGHT AND FIND PEAK AND VICE-VERSA
// WE FIND INCREASING CURVE AND DECREASING CURV LIKE MID > MID -1 IT IS INCREASING CURV, MID < MID-1 IT IS DECREASING CURV

int findPeak(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return nums[0];
    if(nums[n-1] > nums[n-2]) return nums[n-1];
    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            return nums[mid];
        }
        else if(nums[mid] > nums[mid -1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid -1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};