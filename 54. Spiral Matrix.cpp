#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int right_edge = m - 1;
        int down_edge = n - 1;
        string direct = "right";
        while (matrix.size() > 0){
            if (direct == "right"){
                while (matrix[0].size() > 0){
                    ans.push_back(matrix[0][0]);
                    matrix[0].erase(matrix[0].begin());
                }
                matrix.erase(matrix.begin());
                direct = "down";
                right_edge--;
            }
            else if (direct == "down"){
                for (int i = 0; i < matrix.size(); i++){
                    ans.push_back(matrix[i][down_edge]);
                    matrix[i].erase(matrix[i].begin() + down_edge);
                    if (matrix[i].size() == 0){
                        matrix.erase(matrix.begin() + i);
                        i--;
                    }
                }
                down_edge--;
                direct = "left";
            }
            else if (direct == "left"){
                while (matrix[right_edge].size() > 0){
                    ans.push_back(matrix[right_edge][matrix[right_edge].size() - 1]);
                    matrix[right_edge].pop_back();
                }
                matrix.erase(matrix.end());
                direct = "up";
                right_edge--;
            }
            else if (direct == "up"){
                for (int i = right_edge; i >= 0; i--){
                    ans.push_back(matrix[i][0]);
                    matrix[i].erase(matrix[i].begin());
                    if (matrix[i].size() == 0)
                        matrix.erase(matrix.begin() + i);
                }
                down_edge--;
                direct = "right";
            }
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << ";" << down_edge << " " << right_edge << endl;
        }
        return ans;
        
    }
};