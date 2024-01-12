#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        bool done = false;
        int i = 0;
        while (!done){
            if (i < intervals.size() - 1){
                if (intervals[i][1] >= intervals[i + 1][0]){
                    if (intervals[i][1] > intervals[i + 1][1])
                        intervals[i + 1][1] = intervals[i][1];
                    if (intervals[i][0] < intervals[i + 1][0])
                        intervals[i + 1][0] = intervals[i][0];
                    intervals.erase(intervals.begin() + i);
                }
                else
                    i++;
            }
            else
                done = true;
        }
        return intervals;
    }
};