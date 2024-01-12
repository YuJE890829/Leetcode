#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> hash_map;
        for (int i = 0; i < strs.size(); i++)
            update_ans(hash_map, strs[i]);
        for(auto i:hash_map)
            ans.push_back(i.second); 
        return ans;
    }
    string sorted(string str){
        sort(str.begin(), str.end());
        return str;
    }
    void update_ans(unordered_map<string,vector<string>> &hash_map, string str){
        string sorted_str = sorted(str);
        hash_map[sorted_str].push_back(str);
    }
};