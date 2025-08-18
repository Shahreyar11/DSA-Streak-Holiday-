// IN THIS WE HAVE TO FIND THE NTH ROOT OF M

#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// N = 3 , 1*1*1 , 2*2*2, 3*3*3 so here for 27 it will be 3 for 27
// FOR N = 4 , 1*1*1*1, 2*2*2*2, 3*3*3*3, here for m = 69, 81 for 3 so it exceeded and 2*2*2*2 16 so we can't find 69 so -1


// THIS IS THE BRUTE FORCE SOLUTION
int checkSqrt(int arr[], int n, int m){
    for(int i = 1; i<m; i++){
        if(pow(i, n) == m) return i;
        else{
            break;
        }
    }
    return -1;
}

// NOW WE WILL FIND OPTIMAL SOLUTION
// SAY YOU HAVE GIVEN N = 27 SO DEFINE A RANGE BETWEEN 1 TO 27 

int checkSqare(int n, int m){
    int low = 1, high = m;
    while(low <= high){
        int mid = (low+high)/2;
        if (pow(mid, n) == m) return mid;
        else if(pow(mid, n) > m){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}