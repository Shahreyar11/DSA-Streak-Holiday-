// WE NEED TO GIVE SQAURE ROOT OF INTEGER AND WE HAVE TO GIVE WITHOUT DECIMAL

int squareFloot(int n){
    int i = 1;
    while(i*i <= n){
        i++;
    }
    return (i -1);  // we did i-1 as we have to take out floor values 

}

int sqrtFloor(int x){
    int low = 1, high = x, ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        int msq = mid * mid;
        if(msq == x){return mid;}
        else if(msq > x) { high = mid - 1;}
        else{
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}