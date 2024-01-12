#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<int, char>> stack;
        for (int i = 0; i < s.length(); i++){
            if (!islower(s[i])){
                if (s[i] == '(')
                    stack.push_back(make_pair(i, s[i]));
                else{
                    if (stack.size() > 0 && stack[stack.size() - 1].second == '(')
                        stack.pop_back();
                    else
                        stack.push_back(make_pair(i, s[i]));
                }
            }
        }
        for (int i = 0; i < stack.size(); i++)
            s.erase(s.begin() + stack[i].first - i);
        return s;
    }
};