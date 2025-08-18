// SINGLE ELEMENT IN SORTED ARRAY

//  arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7}
// here single element is 4
#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// so this is the bruteforce solution


int element_Check(int arr[], int n){
    if(n==1) return arr[0];
    for(int i =0; i<n; i++){
        if(i == 0){
            if(arr[i] != arr[i+1]) return arr[i];
        }
        else if (i == n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }
        else{
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1]) return arr[i];
            return arr[i];
        }
    }
}

// OPTIMAL SOLUTION FOR THIS

int checkElemet(int arr[], int n){
    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] != arr[mid-1] || arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        else if((mid % 2 == 1 && arr[mid - 1] == arr[mid]) || ( mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            low = mid+1;  // Means no element is single on left half
        }
        else{
            high = mid -1 ; 
        }
    }
    return -1;
}


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || ( mid % 2 == 0 && nums[mid] == nums[mid + 1])){
                low = mid+1;  // Means no element is single on left half
            }
            else{
                high = mid -1 ; 
            }
        }
        return -1;
        
    }
};