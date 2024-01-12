#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        string x_str = to_string(x);
        if (x_str[0] == '-')
            ::reverse(x_str.begin() + 1, x_str.end());
        else
            ::reverse(x_str.begin(), x_str.end());
        if (!overflow(x_str))
            return stoi(x_str);
        else
            return 0;
    }
    bool overflow(string x_str){
        string negative_edge_str = to_string(INT_MIN);
        string positive_edge_str = to_string(INT_MAX);
        if (x_str[0] == '-'){
            if (x_str.length() > 11)
                return true;
            if (x_str.length() == 11 && x_str > negative_edge_str)
                return true;
        }
        else{
            if (x_str.length() > 10)
                return true;
            if (x_str.length() == 10 && x_str > positive_edge_str)
                return true;
        }
        return false;
                
    }
};