#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) { //由於每個區段不會因為remove的動作被合併，因此只須計算區段內總共能remove的數量來比較誰能remove更多即可判斷贏家
        int Alice = 0, Bob = 0;
        if (colors.length() < 3)
            return false;
        for (int i = 1; i < colors.length() - 1; i++){
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]){
                if (colors[i] == 'A')
                    Alice++;
                else
                    Bob++;
            }
        }
        return Alice > Bob;
    }
};