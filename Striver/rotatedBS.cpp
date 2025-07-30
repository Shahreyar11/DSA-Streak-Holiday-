#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;


// SEARCH IN ROTATED SORTED ARRAY

// arr = {7, 8, 9, 1, 2, 3, 4, 5, 6}, target = 1
// First Step -> Identify the sorted half, Like you performed Binary Search and
// Now two halves are left so 1 half must be sorted Identify That
// low < 2 = False here as 2 is mid so we identified that right half is sorted

int RotatedSorted(vector<int> &arr, int n, int target){
    // Why can't we just put a line like IF(ARR[LOW] = TARGET || ARR[HIGH] == TARGET ) because sometimes it comes and it would be easy
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        if(arr[low] <= arr[mid]){ // The Sorted Half is Right One
            if(arr[low] <= target && target <=  arr[mid]){
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }
        else { // The Sorted Half is left one
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){ // target is at left half
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{ // target is at right half
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid -1; 
                }
            }
        }
        return -1;
    }
};


// SEARCH ELEMENT IN ROTATED ARRAY PART 2 basically it have duplicates
// arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6} target = 3

// arr[] = {3, 1, 2, 3, 3, 3, 3} target = 1

// SO WHENEVER WE END UP IN THIS SITUATION where you want to find the sorted half and Search for element
// WHERE arr[low] == arr[mid] == arr[high], then shrink the search space , SHRINK THE SEARCH SPACE (low + 1, and high -1 till you find different elements in all three or 2)

bool RotatedDuplicateSearch(vector<int> &arr, int n, int target){
    // Why can't we just put a line like IF(ARR[LOW] = TARGET || ARR[HIGH] == TARGET ) because sometimes it comes and it would be easy
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
            continue;
        }
        if(arr[low] <= arr[mid]){ // The Sorted Half is Right One
            if(arr[low] <= target && target <=  arr[mid]){
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }
        else { // The Sorted Half is left one
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
    }
    return false;
}


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++, high--;
                continue;
            }
            if(nums[low] <= nums[mid]){ // The Sorted Half is Right One
                if(nums[low] <= target && target <=  nums[mid]){
                    high = mid -1 ;
                }
                else{
                    low = mid + 1;
                }
            }
            else { // The Sorted Half is left one
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        return false;
    }
};
