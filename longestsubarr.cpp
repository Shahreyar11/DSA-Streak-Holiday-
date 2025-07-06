// arr = [1,2,1,3,4,1,1,1,4,5,6,3] and K = 3
// Longest subarray with sum k 

// here we have 1 and 2 in starting array and sum = k but it is not longest
// similarly we have 3 inside the array it is also = k but it is also not longest
// But 1,1,1 is inside this array with sum = k and it is longest 
#include<iostream>
using namespace std;
int main(){
// int len = 0;  
// int sum = 0;  
//     for(int i = 0; i< n; i++){
//         for(int j = 1; j<n; j++){
//             for(k = i; k<=j; k++){
//                 sum += arr[k];
//             }
//         }
//         if( sum == k && len = max(len, (j-i) + 1) ){
//             cout << len;
//         }
//     }
// THIS ABOVE SOLN HAS TIME COMPLEXITY O(n3)
}

// NOW HERE WE REMOVED THE THIRD LOOP AND BEST BRUTE FORCE HAS O(n2)
// #include<iostream>
// using namespace std;
// int main()

//     int len = 0;  
//     int sum = 0;  
//         for(int i = 0; i< n; i++){
//             for(int j = 1; j<n; j++){
//             sum += arr[j] ;
//             if( sum == k && len = max(len, (j-i) + 1) ){
//                 cout << len;
//             }
//         }
// }
