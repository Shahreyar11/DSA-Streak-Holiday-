#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>



using namespace std;

// First and Last Occurence of x
// arr = {2, 4, 6, 8, 8 , 8, 11, 13 }
// x = 8
// give the pair of first and last occuring index => {3,5}
// if element is not present then => {-1, -1} , x = 10
// if only one element is present then same occurence {6, 6}, x= 11

// So for Naive Solution or Brute Force

// T.C. => O(n)
// int findOccurence(int arr[], int n, int x){
    // int first = -1, last = -1;
    // for(i = 0; i< n ){
    //     if(arr[i] == x){
    //         if(first == -1){
    //             first = i;
    //         }
    //         last = i;
    //     }
    // }
// }

int lowerBoundSearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    int ans = n - 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            //maybe an answer
            ans = mid;
            // look for small index on left
            high = mid - 1;
        }
        else{
            low = mid + 1;  // look for right index 
        }
    }
    return ans;

}

int upperBound(int arr[], int n,  int x){
    int ans = n-1;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] <= x){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

std::pair<int, int> firstLastOcc(int arr[], int n, int k) {
    int lb = lowerBoundSearch(arr, n, k);
    if (lb == n || arr[lb] != k) {
        return {-1, -1};
    }
    int ub = upperBound(arr, n, k); 
    return {lb, ub - 1};
}


// OPTIMAL SOLUTION

int firstOccurence(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid -1 ;
        }
    }
    return first;
}

int lastOccurence(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int last = -1;
    while(low<= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid -1 ;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k){
    int first = firstOccurence(arr, n, k);
    if(first == -1) return {-1, -1};
    int last = lastOccurence(arr, n, k);
    return {first, last};
}



// Leetcode 

class Solution {
public:
    int firstOccurence(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid -1 ;
        }
    }
    return first;
}

int lastOccurence(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int last = -1;
    while(low<= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid -1 ;
    }
    return last;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurence(nums, n, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurence(nums, n, target);
        return {first, last};
    }
};


