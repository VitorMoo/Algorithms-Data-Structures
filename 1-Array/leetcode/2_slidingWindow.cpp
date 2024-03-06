#include<iostream>
#include<vector>
using namespace std;

//given an array of size n, return hte maximum sum
//of k consecutive elements


vector<int> v={1,4,2,-10,0,20}; //k=3 ->1=n
// output: 10
    
/*
{1,4,2}=7
{4,2,-10}=-4
{2,-10,0}=-8
-{10,0,20}=10

time: O(n*k)
space:O(1)


{1,4,2,-10,0,20} k=3
           ^    ^

currentSum = 1 + 4 + 2 = 7
currentSum = currentSum - 1 + (-10)= -4
currentSum = currentSum - 4 + 0 = -8
currentSum = - 2 + 20 = 10

time:O(n)
space:O(1)
*/
// Given an array of size n, return the maximum sum
// of k consecutive elements

int maxSum(vector<int>& array, int k) {
    int currentSum = 0;
    int maxSum = 0;

    // Calculate sum of first k elements
    for (int i = 0; i < k; i++) {
        currentSum += array[i];
    }

    maxSum = currentSum;

    // Slide window technique to find maximum sum
    for(int i =0,j=k;j<array.size();i++,j++){
        currentSum=currentSum-array[i]+array[j];
        maxSum=max(currentSum,maxSum);
    }
    return maxSum;
    }
    
int main() {
    vector<int> v = {1, 4, 2, -10, 0, 20}; // k=3
    int k = 3;
    int result = maxSum(v, k);
    cout << "Maximum sum of " << k << " consecutive elements: " << result << endl;
    // Output: 10
    return 0;
}
