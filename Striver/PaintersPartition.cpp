#include<iostream>
#include <utility>  
#include<bits/stdc++.h>

using namespace std;

// PAINTER'S PARTITION/ SPLIT ARRAY - LARGEST SUM 
// arr[] = {10, 20, 30, 40} k = 2
// So it tells that the Wall has 10 units to be painted 
// then 20 units then 30 then 40 and you are given 2 Painters
// Each of the Painters should get atleast one job to do
// And it should be Contiguous
// say 1--> {10, 20} & 2 --> {30, 40}
// Or Say 1 --> {10} & 2 --> {20, 30, 40}

// and through this say painter 1 does job in 30 Mins and painter 2 in 70 mins the Summation of Units 
// so max time is 70 as both working together

// and for another case max time is 90

// and if we take {10, 20, 30} for Painter 1 and {40} For Painter 2 --> 60 is the Least

int countPainter(vector<int> &nums, int walls){
    int Painters = 1;
    long long wallUnits = 0;
    for(int i = 0; i<nums.size(); i++){
        if(wallUnits + nums[i] <= walls){
            wallUnits += nums[i];
        }
        else{
            Painters += 1;
            wallUnits = nums[i];
        }
    }
    return Painters;
}

int findMinTime(vector<int> &nums, int k){
    int n = nums.size();
    if(k > n) return -1;
    int low = *max(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while(low <= high){
        int mid = (low + high)/2;
        int Painter = countPainter(nums, mid);
        if(Painter > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}


class Solution {
public:
    int countPainter(vector<int> &nums, int walls){
        int Painters = 1;
        long long wallUnits = 0;
        for(int i = 0; i < nums.size(); i++){
            if(wallUnits + nums[i] <= walls){
                wallUnits += nums[i];
            }
            else{
                Painters ++;
                wallUnits = nums[i];
            }
        }
        return Painters;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low + high)/2;
            int Painter = countPainter(nums, mid);
            if(Painter > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};




class Solution {
public:
    int countPainter(vector<int> &nums, int walls){
        int Painters = 1;
        long long wallUnits = 0;
        for(int i = 0; i < nums.size(); i++){
            if(wallUnits + nums[i] <= walls){
                wallUnits += nums[i];
            }
            else{
                Painters++;
                wallUnits = nums[i];
            }
        }
        return Painters;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low <= high){
            int mid = (low + high)/2;
            int Painter = countPainter(nums, mid);
            
            if(Painter > k){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
