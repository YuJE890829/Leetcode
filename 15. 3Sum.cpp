#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans_set;
        sort(nums.begin(), nums.end());
        int j, k, sum;
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++){
            j = i + 1;
            k =  nums.size() - 1;
            while (j < k){
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0){
                    ans_set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>> ans;
        for (vector<int> i : ans_set)
            ans.push_back(i);
        return ans;
    }
};