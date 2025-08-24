#include<iostream>
#include <utility>  
#include<bits/stdc++.h>

using namespace std;
// arr[] = {25, 46, 28, 49 24} & The No of Students = 4
// --> BOOK ALLOCATION SHOULD BE IN CONTIGUOUS((next to each other) MANNER 
// --> Each Student should atleast get one book 
// --> Each Book should be allocated to One Student 

// Give an array "arr" of integer numbers, 
// "arr[i]" represents the number of pages in the i-th book

// SO ITS LIKE YOU GIVE 
// 25 pages to student 1 , 46 to student 2, 28 to student 3 and 49+24 to student 4 So here 73 is Max as 49+24 = 73 
// Similarly if you give 25 to S-1, 46 to S-2, 28+49 = 77 to S-3, and 24 to S-4. here 77 is Max
// So if you keep on checking but in Contiguous Manner you will get 73, 77, 74, and 71 is Minimum of the Maximum So here 71 is answer

int countStudents(vector<int> &arr, int pages){
    int students = 1;
    long long pagesStudent = 0;
    for(int i = 0; i<arr.size(); i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m){
    if(m > n) return -1;
    int low = *max(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high)/ 2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;  // Too many students → capacity too small
        }
        else{
            high = mid - 1;  // Possible allocation, try smaller max
        }
    }
    return low;
}