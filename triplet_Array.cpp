// TRIPLET IN A SORTED ARRAY
// WE HAVE TO FIND OUT WETHER THE SUM IS EQUAL TO THE TRIPLET IN THE SORTED ARRAY OR NOT 

// NAIVE SOLUTION

bool isTriplet(int arr[], int n, int x){
    for(int i = 0; i< n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == x){
                    return true;
                }
            }
        }
    }
    return false;
}