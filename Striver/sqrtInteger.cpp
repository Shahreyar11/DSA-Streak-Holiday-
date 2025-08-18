#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

//SO IN THIS WE WILL FIND OUT SQAURE ROOT OF INTEGER
// SO WE WILL LEARN THE BINARY SEARCH METHOD EHRE

int checkSqaure(int arr[], int n, int sqrt){
    int ans = 1;
    for(int i = 0; i<n; i++){
        if(i*i <= sqrt){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

//  SO FOR THE OPTIMAL SOLUTION
// WE WILL USE BINARY SEARCH AND THE LAST ELEMENT WHICH IS N WILL BE THE SQUARE OF WHAT SQure root we are taking off
// NOW WE WILL RUN THE LOW = 1 AND HIGH AS N AND WE WILL CHECK FOR MID AS SQAURE ROOT IF IT IS GREATER THAN N MEANS LAST ELEMENT 
// WE WILL CHANGE HIGH = MID -1 AND WE WILL CONTINUE DOING THIS

int CheckSquareBS(int sqrt){
    int ans = 1;
    int low = 1, high = sqrt;
    while(low <= high){
        int mid = (low + high)/2;
        if( mid * mid <= sqrt){
            ans = mid;
            low = mid +1; // KEEP ON CHECKING MORE HIGHER NUMBER CAUSE 1 IS ALSO LESSER THAN N WE NEED HIGHESET NUMBER LIKE FOR 25 WE NEED 5 YET 3, 4 IS ALSO THE ANSWER
        }
        else{
            high = mid -1;
        }
    }
    return ans; //or return high
}