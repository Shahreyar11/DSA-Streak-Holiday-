// TWO POINTER APPROACH IN THIS WE HAVE TO FIND A PAIR EQUAL TO SUM "X" INSIDE THE ARRAY

// SO WE PROCEEDED WITH THE NAIVE APPROACH HERE 
// T.C = O(n2)
#include <iostream>
using namespace std;

bool isPair(int arr[], int n, int x){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == x){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 4, 5, 7, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;

    if (isPair(arr, n, x)) {
        cout << "Pair with sum " << x << " exists." << endl;
    } else {
        cout << "No such pair found." << endl;
    }

    return 0;
}

// SO IN THE OPTIMAL APPROACH WE TRY TO POINT I AS 0 AND J AS LAST ELEMENT
// THEN WE CHECK WITH BOTH SUM IF THEY ARE EQUAL WE PRINT TRUE
// IF THEY ARE GREATER THEN WE SUBTRACT J VALUE BY 1 
// IF THEY ARE SMALLER THEN WE ADD I VALUE BY 1 


// THIS IS OPTIMAL APPROACH
// WITH T.C O(n)
bool isSumPair(int arr[], int x, int n){
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i] + arr[j] == x){return true;}
        else if(arr[i] + arr[j] > x){
            j--;
        }
        else{
            i++;
        }
        return false;
    }
}

