// KOKO EATING BANANAS

#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// RETURN THE MIN INTEGER K SUCH THAT KOKO CAN EAT ALL BANANAS WITHIN H HOURS
// so piles = [3, 6, 7, 11] and h = 8 and You assume 2 bananas/ hour koko eats
// So for 3 -> 2 hours, for 6 -> 3 hours, for 7 -> 4 hours, , for 11 -> 6 hours total 15 hours which exceeds 8 hours so this won't work You have to think for better way
//  IF WE DO 4 BANANAS PER HOUR THEN 1+2+2+3 = 8 EXACTLY MATCHED 

// HERE IF WE TAKE 11 BANANAS PER HOUR IT WILL BE MAXIMUM AS 4 HOURS WILL BE TIME AND IF WE TAKE 10 IT WILL BE MORE THAN 4 HOURS
// AND IF WE TAKE 12 13 14 OR ANY IT WONT MATTER AS IT WILL TAKE SAME AS 11 BANANAS WHICH IS 4 HOURS
// SO MINIMUM IS 4 BANANAS AND MAX IS 11 BANANAS WE HAVE TO TAKE OUT MINIMUM AND MAXIMUM BOTH 

// so my loop will run from 1 to max in the array 

int findMax(vector<int> &v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i = 0; i< n; i++){
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly){
    int totalH = 0;
    int n = v.size();
    for(int i = 0; i<n; i++){
        totalH += ceil(double(v[i])/ hourly);
    }
    return totalH;
}

int minimumRateToEatbananas(vector<int> &nums, int h){
    int low = 1, high = findMax(nums);
    while(low <= high){
        int mid = (low + high)/2;
        int totalH = calculateTotalHours(nums, mid);
        if(totalH <= h){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}


// LEETCODE 
class Solution {
public:
    int findMax(vector<int> &v){
        int maxi = INT_MIN;
        int n = v.size();
        for(int i = 0; i<n; i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    long long calculateTotalHours(vector<int> &v, int hourly){
        long long totalH = 0;
        int n = v.size();
        for(int i = 0; i< n; i++){
            totalH += (v[i] + hourly - 1) / hourly;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high){
            int mid = (low + high)/2;
            long long totalH = calculateTotalHours(piles, mid);
            if(totalH <= h){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};