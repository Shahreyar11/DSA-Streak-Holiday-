// SEARCH IN SORTED ROTATED ARRAY

// Naive solution
int search(int arr[], int n, int x){
    for(int i = 0; i< n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

// PS --> I didn't udnerstood the optimal solution