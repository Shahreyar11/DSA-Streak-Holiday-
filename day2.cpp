// INDEX OF FIRST OCCURENCE
// WE HAVE TO FIND THE FIRST OCCURENCE OF THE ELEMENT IN THE GIVEN ARRAY
// {1, 10, 10, 10, 20, 20 , 40}
// IF X = 20 , THE FIRST OCCURENCE IS 4

// FIRST NAIVE SOLUTION 

int FirstOcc(int arr[], int n, int x){
    for(int i =0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

// OPTIMUM SOLUTION

int firstOccur(int arr[], int low, int high, int x){
    if(low > high) return -1;

    int mid = (low + high)/ 2;
    if(x > arr[mid]){
        return firstOccur(arr, mid + 1, high, x);
    }
    else if (x < arr[mid]){
        return firstOccur(arr, low, mid - 1, x);
    }
    else{
        if(mid == 0 || arr[mid - 1] != arr[mid]){
            return mid;
        }
        else{
            return firstOccur(arr, low, mid-1, x);   //"I found x at index mid, but maybe there's an earlier one. So check the left side!"
            //Then it means there's another occurrence before mid, and we need to keep searching left.
            // So we call the function again, but only on the left half:
        }
    }
}

// So In this optimal code 
// Every recursive call reduces the problem size by half.

// Therefore, the number of calls will be log₂(n)
// (Because you can divide n by 2 about log₂(n) times.)

// AND SPACE COMPLEXITY 
// 🔥 What happens?
// Each time we call firstOccur(), it adds one function call on the call stack.

// Since we cut problem size by half each time, the maximum depth of recursion is also log n.

// 📌 So:
// Space Complexity = O(log n)
// (due to recursion stack)


// INDEX OF LAST OCCURENCE 

int lastOcc(int arr[], int low, int high, int x, int n){
    if(low > high) return -1;

    int mid = (low + high)/ 2;
    if(x > arr[mid]){
        return lastOcc(arr, mid + 1, high,x, n);
    }
    else if (x < arr[mid]){
        return lastOcc(arr, low, mid - 1,x, n);
    }
    else{
        if(mid == n-1 || arr[mid] != arr[mid + 1]){
            return mid;
        }
        // NOW THIS PARTICULAR LINE EXPLAINS IF MID IS 
        // LAST ELEMENT OR MID + 1 & MID IS NOT SAME, THEN IT IS THE LAST
        // OCCURENCE OTHERWISE THERE IS MORE CODE
        else{
            return lastOcc(arr, mid + 1, high,x, n);
        }
        // IF WE DON'T FIND THEN BY THIS ELSE LINE OF CODE JUST ABOVE WE GO TO RIGHT HALF TO FIND LAST OCCURENCE
    }
}

// BUT FOR THIS ITERATIVE METHOD IS MORE BETTER THAN THIS RECURSIVE METHOD AS IT TAKES LESS AUXILLARY SPACE

int lastOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
        else
        {
            if (mid == n - 1 || arr[mid] != arr[mid + 1])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}
