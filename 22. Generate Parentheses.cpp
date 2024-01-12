#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dp(n - 1, "", ans, 0, 0);
        return ans;
    }
    void dp(int n, string parentheses, vector<string> &ans, int left, int right){
        if (parentheses.length() < 2 * n){
            if (left < n)
                dp(n, parentheses + '(', ans, left + 1, right);
            if (right < n)
                dp(n, parentheses + ')', ans, left, right + 1);
        }
        else{
            parentheses = '(' + parentheses + ')';
            if (well_formed(parentheses))
                ans.push_back(parentheses);
        }
    }
    bool well_formed(string parentheses){
        int left = 0, right = 0;
        char flag = '(';
        for (int i = 0; i < parentheses.length(); i++){
            if (parentheses[i] == '(')
                left++;
            else
                right++;
            if (right > left)
                return false;
        }
        return true;
    }
};