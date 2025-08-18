#include<iostream>
#include <utility>  // For std::pair
#include<bits/stdc++.h>

using namespace std;

// MINIMUM NUMBER OF DAYS TO MAKE M BOUQuETS

// bloomDay = [7, 7, 7, 7, 13, 11, 12, 7] m = 2, k=3 here 
// m is the no. of bouquets and k is the adjacent flowers required
// So ARRAY ACTUALLY TELLS ABOUT THE FLOWER WHICH BLOOMS LIKE IF IT IS 7 THE FLOWER BLOOM ON 7TH DAY
// SIMILARLY FOR 13TH AND 12TH AND 11TH 
// SO HERE IN THIS CASE: 13 IS THE MAX DAY ALL FLOWERS WILL BE BLOOMED
// hence we can take the indexes 0, 1, 2 and 5, 6, 7 and we have 2 bouquets of 3 adjacent flowers
