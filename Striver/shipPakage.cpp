#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;


// LEAST CAPACITY TO SHIP PACKAGES WITHIN D DAYS
// weights = {1, 2, 3, 4, 5, 6, ,7, 8, 9, 10} days = 5
// So If you set the capacity to 100 it will be able to send it in one day But You have to check for the least capacity
// here if you put around capcaity to 15 It will be around 5 days in Total So We have to check for the least capacity that can send these
// products through the Ship in under 5 days

// So Higher point is Decided as it must not be greater than the maximum sum of Arrays as it will be of no Use 
// and the smaller part will be maximum element in the array cause if we take lesser capacity we will not be able to ship that particular product

int findDays(vector<int> &weights, int cap){
    int days = 1, load = 0;
    for(int i = 0; i< weights.size(); i++){
        if(weights[i] + load > cap){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCap(vector<int> &nums, int days){
    int low = *max_element(nums.begin(), nums.end());  // returns an iterator pointing to the largest element in the vector.
    // The * (dereference operator) is used to get the actual value from the iterator.
    int high = accumulate(nums.begin(), nums.end(), 0);  //  adds all the values in the given range, starting from the initial_value
    while(low <= high){
        int mid = (low + high)/2;
        int noOfDays = findDays(nums, mid);
        if(noOfDays <= days){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}


class Solution {
public:
    int findDays(vector<int> &weights, int cap){
        int days = 1, load = 0;
        for(int i = 0; i< weights.size(); i++){
            if(weights[i] + load > cap){
                days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  
        int high = accumulate(weights.begin(), weights.end(), 0);  
        while(low <= high){
            int mid = (low + high)/2;
            int noOfDays = findDays(weights, mid);
            if(noOfDays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }    
};