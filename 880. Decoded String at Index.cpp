#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
       long long decodedLength = 0;
        for(auto c : s){ //計算total size
            if(isdigit(c)){
                decodedLength = decodedLength * ( c - '0');
            }
            else{
                decodedLength++;
            }
        }

        for(int i = s.length() - 1; i >= 0; i--){ //從最後開始decode直到kth
            char curr = s[i];
            if(isdigit(curr)){
                decodedLength = decodedLength/(curr - '0');
                k = k % decodedLength;
            }
            else{
                if( k == 0 || decodedLength == k){
                    return string(1,curr);
                }
                decodedLength--;
            }
        }

        return "";
    }
    
};