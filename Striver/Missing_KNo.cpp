#include<iostream>
#include <utility>  
#include<bits/stdc++.h>

using namespace std;

// FIND KTH THE MISSING NUMBER 
// arr[] = {2, 3, 4, 7, 11} k = 5
// so say rest of the numbers are {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11} and for this array 5th Missing Number is 
// Missing numbers = {1, 5, 6, 8, 9, 10} so 5th is 
// On the Basis of K we can determine How many numbers are Missing as 11 - 5 = 6 and here 6 nos are missing so max element in array - k is the Total Numbers missing

// LEARN THIS AGAIN YOU DIDN'T UNDERSTAND
int missingK(vector<int> vec, int n, int k){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/ 2;
        int missing = vec[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return k + high + 1;
}

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/ 2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};