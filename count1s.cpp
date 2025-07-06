// IN THIS QUESTION WE FIND 1'S IN THE SORTED BINARY ARRAY
// WHAT WE DO IS FOLLOW BINARY SEARCH AND WE CHECK FOR 0 AT MID IF NOT FOUND 1 WILL BE FOUND SO WE CHECK WHETHER LEFT SIDE IS 0 OR NOT
// IF NOT WE GO TO LEFT HALF IN ARRAY AS OUR POINT IS
// AS SOON AS WE GET FIRST OCCURENCE OF 1 WE WILL SUBTRACT WHOLE ARRAY LENGTH BY INDEX OF FIRST OCCURENECE AND ANSWER IS THE NO OF 1'S

int CountOns(int arr[], int n){
    int low = 0;
    int high = n - 1;
    while(low < high){
        int mid = (low + high)/2;
        if(arr[mid] == 0){
            low = mid + 1;
        }
        else {
            if(mid == 0 || arr[mid -1] == 0){
                return (n - mid);
            }
            else{
                high = mid -1 ;
            }
        }
    }
    return 0;
}