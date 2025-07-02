// BINARY SEARCH

#include<iostream>
#include<vector>
using namespace std;


int  BinarySearch(int arr[], int size, int x){
    int low = 0;
    int high = size - 1 ;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if (arr[mid] > x ){
            high = mid -1 ;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;

}
int main(){

}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1; // not found
    }
};

// RECURSIVE BINARY SEARCH 

int RecursiveBsearch(int arr[], int low, int high, int x){
    if(low > high) return -1;
    int mid = (low + high)/ 2;
    if(arr[mid] == x) return mid;
    else if (arr[mid] > x){
        return RecursiveBsearch(arr, low, mid -1 , x);
    }
    else {
        return RecursiveBsearch(arr, mid + 1, high, x);
    }
}


