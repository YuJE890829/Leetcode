#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int numsSum = 0;
        for (int i = 0; i < nums.size(); i++)
            numsSum = numsSum + nums[i];
        int player1Score = predict(0, nums.size() - 1, true, nums);
        return player1Score >= (numsSum-player1Score);
    }
    int predict(int start, int end, bool player1, vector<int>& nums){
            if (end - start < 0)
                return 0;
            if (player1)
                return max(nums[start]+predict(start+1,end,false, nums),nums[end]+predict(start, end-1, false, nums));
            else
                return min(predict(start+1,end,true, nums),predict(start,end-1,true, nums));
    }
};