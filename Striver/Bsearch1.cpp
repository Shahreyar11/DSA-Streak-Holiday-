// LOWER BOUND AND UPPER BOUND
// LOWER BOUND FOR A GIVEN NUMBER X WILL BE ARR[Index] >= X
// ARR[] = {3, 5, 8, 15, 19} AND X = 8
// SO LB = 2 AS ARR[2] == 8 AND 8 >= X
// Find the first index where the element is greater than or equal to x.


// TC --> O(logn)
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


// UPPER BOUND QUESTION
// Find the first index where the element is strictly greater than x.

// smallest index such that arr[index] > x


// class Solution{
// public:
//     int upperBound(vector<int> &nums, int x){
//         int n = nums.size();
//         int ans = n-1;
//         int low = 0, high = n-1;
//         while(low <= high){
//             int mid = (low+high)/2;
//             if(nums[mid] <= x){
//                 low = mid + 1;
//             }
//             else{
//                 ans = mid;
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }
// };


//SEARCH INSERT POSITION
// You are given a sorted array 'arr'of distinct values and a target value 'm'. You
// need to search for the index of the target value in the array.

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low = 0, high = n-1;
//         int ans = n;
//         while(low <= high){
//             int mid = (low+high)/2;
//             if(nums[mid] >= target){
//                 //maybe an answer
//                 ans = mid;
//                 // look for small index on left
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;  // look for right index 
//             }
//         }
//         return ans;
//     }
// };