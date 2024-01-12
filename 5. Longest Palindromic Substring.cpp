#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        string max_string = "";
        int start, end;
        for (start = 0; start < s.length(); start++){
            for (end = s.length() - 1; end >= start; end--){
                if (s[end] == s[start] && end - start + 1 > max_string.length() && is_palindromic(s.substr(start, end - start + 1)))
                    max_string = s.substr(start, end - start + 1);
            }
        }
        return max_string;
    }
    bool is_palindromic(string s){
        int start = 0;
        int end = s.length() - 1;
        while (end >= start){
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};