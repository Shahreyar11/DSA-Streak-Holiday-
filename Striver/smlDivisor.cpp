#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// WE HAVE TO FIND THE SMALLEST DIVISOR GIVEN A THRESHOLD

// arr[] = {1, 2, 5, 9}, threshold = 6
// So you will divide all elements of the array and 
// the divisor which came after every division, You will take the ceil value and add all
// AND THE ANSWER SHOULD NOT BE GREATER THAN THRESHOLD VALUE and you have to find the smallest value

// So divide by 4 each element of this array you will get ceil values as 1, 1 2, 3 so its 7 mroe than 6 so you have to find the smallest

int findMax(vector<int> &v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i = 0; i< n; i++){
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int countDivisor(vector<int> & nums, int div){
    int n = nums.size();
    int Count_div = 0;
    for(int i = 0; i< n; i++){
        Count_div += (nums[i] + div - 1) / div;
    }
    return Count_div;
}

int SmallestDiv(vector<int> &nums, int threshold){
    int low = 1, high = findMax(nums);
    while(low <= high){
        int mid = (low + high)/2;
        if(countDivisor(nums, mid) <= threshold){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}


// So this worked for Leetcode all By Myself
class Solution {
public:
    int findMax(vector<int> &v){
        int maxi = INT_MIN;
        int n = v.size();
        for(int i = 0; i< n; i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int countDivisor(vector<int> & nums, int div){
        int n = nums.size();
        int Count_div = 0;
        for(int i = 0; i< n; i++){
            Count_div += (nums[i] + div - 1) / div;
        }
        return Count_div;
    }

    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = findMax(nums);
        while(low <= high){
            int mid = (low + high)/2;
            if(countDivisor(nums, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
