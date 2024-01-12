#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; //priority_queue 在 template 第3個型別可指定比較用的 function object，不過為了填第3個型別，就必須先填上第2個型別。
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop(); //一路刪到頂部是第k大的數
            }
        }
        return pq.top();
    }
};