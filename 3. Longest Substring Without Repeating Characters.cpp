#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        string ans_string = "";
        int char_position;
        for (int i = 0; i < s.length(); i++){
            char_position = ans_string.find(s[i]);
            if (char_position != ans_string.npos){
                if (ans_string.length() > max_length)
                    max_length = ans_string.length();
                ans_string.erase(0, char_position + 1);
            }
            ans_string = ans_string + s[i];
            
        }
        if (ans_string.length() > max_length)
            return ans_string.length();
        else
            return max_length;
    }
};