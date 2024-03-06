#include<iostream>

using namespace srt;

   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;            //three pointers starting at the end of m,n and m+n
        int end = m+n-1;        //[1,2,2,3,5,6]    [2,5,6]
                                //   ^ ^          ^
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[end]=nums1[i];
                i--;    
            }else{
                nums1[end]=nums2[j];
                j--;
            }
            end--;
        }

        while(j>=0){
            nums1[end]=nums2[j];
            end--;
            j--;
        }
    }


