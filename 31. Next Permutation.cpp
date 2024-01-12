#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) { //排列的順序為數字轉成int後後者比前者大
        int leftIndex;

        //find a number higher in the right part of the array
        for (leftIndex = nums.size() - 2; leftIndex >= 0 && nums[leftIndex] >= nums[leftIndex + 1]; leftIndex--);

        //we did not find any number higher in the right part 
        //then it means that we have to reverse the whole array 
        if(leftIndex == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //find closest number bigger in the right part
        int indexHigherThanLeft = 0;
        for(int i = nums.size()-1; i!= 0; i--){
            if(nums[i] > nums[leftIndex]){
                indexHigherThanLeft = i;
                break;
            }
        }
        // swap the left index and closest number bigger than leftIndex
        swap(nums[leftIndex], nums[indexHigherThanLeft]);

        // reverse everythin between leftindex + 1 and end
        reverse(nums.begin() + leftIndex + 1, nums.end());
    }
    // 列出所有排序的方法
    //void perm(std::vector<char> &arr, int idx){
    //    if(idx == arr.size()-1){  // 都選擇完了
    //        for(int i = 0; i < arr.size(); ++i){
    //            std::cout << arr[i];
    //        }
    //        std::cout << "\n";
    //    }else{
    //        for(int i = idx; i < arr.size(); ++i){
    //            std::swap(arr[idx], arr[i]);
    //           perm(arr, idx+1);
    //            std::swap(arr[idx], arr[i]);
    //        }
    //    }
    //}
};