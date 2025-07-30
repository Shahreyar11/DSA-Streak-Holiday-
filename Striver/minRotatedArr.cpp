#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// So We have to find Minimum in Rotated Sorted Array

// arr[] = {4, 5, 6, 7, 0, 1, 2}

int MinSorted(vector<int> &arr, int n){
    int low = 0, high = n-1, ans = INT_MAX;
    while(low <= high){
        int mid = (low + high)/ 2;
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid -1 ;
        }
    }
    return ans;
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/ 2;
            // if (nums[low] <= nums[high]) {
            //     ans = min(ans, nums[low]);
            //     break;  
            // }
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid -1 ;
            }
        }
        return ans;  
    }
};


// if arr[low] <= arr[mid] && arr[mid] <= arr[high] means both halfs are sorted (Happens Mostly after Finding the Point of Rotation)

// NOW LETS FIND OUT HOW MANY TIMES THE ARRAY HAS BEEN ROTATED

// arr[] = {3, 4, 5, 1, 2}  ans = 3

// if you know how to find Minimum in Rotated Sorted Array , that answer is equal to the number of times array is rotated

int CountRotated(vector<int> &arr, int n){
    int low = 0, high = n-1, ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low + high)/ 2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }
        else if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else{
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid -1 ;
        }
    }
    return index;
}


class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        int index = -1;
        while(low <= high){
            int mid = (low + high)/ 2;
            if(nums[low] <= nums[high]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                break;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else{
                if(nums[mid] < ans){
                    index = mid;
                    ans = nums[mid];
                }
                high = mid -1 ;
            }
        }
        return index;
    }
};