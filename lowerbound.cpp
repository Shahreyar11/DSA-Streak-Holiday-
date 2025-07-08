// SEARCH INDEX OF SMALLEST NUMBER IN THE ARRAY SATISFYING THE CONDITION ( X >= ELEMENT)

// class Solution{
// public:
//     int lowerBound(vector<int> &nums, int x){
//         int n = nums.size();
//         int low = 0;
//         int high = n -1;
//         while(low <= high){
//             int mid = (low + high)/2;
//             if(nums[mid] >= x){
//                 high = mid -1;
//             }
//             else if(nums[mid] < x){
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };

// SEARCH IN AN INFINITE ARRAY
// arr = {10, 20, 30 ,40, 50 70, 100, 200, 240, 300, 500, ........} , X = 100
// Output = 6

// naive solution

int infiniteSearch(int arr[], int x){
    int i = 0;
    while(true){
        if(arr[i] == x) {return i;}
        else if(arr[i] > x){ return -1;}
        i++;
    }
}

// OPTIMAL SOLUTION -> WHAT WE DO IS MOVE THE i WITH MULTIPLICATION OF 2 LIKE FIRST LOOP i THEN i*2 THEN AGAIN i*2
// SO WE REACH A SMALLER ELEMENT AND A BIGGER ELEMENT THAN X THEN WE DO A BINARY SEARCH BETWEEN THEM TO FIND
int BinarySearch(int arr[], int x, int low, int high){
    if(low > high) return -1;
    int mid = (low + high)/ 2;
    if(arr[mid] == x) return mid;
    else if (arr[mid] > x){
        return BinarySearch(arr, low, mid -1 , x);
    }
    else {
        return BinarySearch(arr, mid + 1, high, x);
    }
}

// here is the optimal solution
int searchInfinite(int arr[], int x){
    if (arr[0] == x) {return 0;}
    int i = 1;
    while(arr[i] < x){
        i = i*2;
    }
    if(arr[i] == x) { return i;}
    return BinarySearch(arr, x, (i/2) + 1, i-1);  //  SO HERE WE ARE RETURNING THE BINARY SEARCH BETWEEN SMALLER AND LARGER ELEMENT

}