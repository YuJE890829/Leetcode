#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 2)
            return Area(min(height[0], height[1]), height.size() - 1);
        int max_area;
        int area;
        int left = 0;
        int right = height.size() - 1;
        while (left < right){
            area = Area(min(height[left], height[right]), right - left);
            max_area = max(max_area, area);
            if(height[left] < height[right]) 
                left++;
            else if(height[left] > height[right]) 
                right--;
            else {
                left++;
                right--;
            }
        }
        return max_area;
    }
    int Area(int height, int length){
        return height * length;
    }
};