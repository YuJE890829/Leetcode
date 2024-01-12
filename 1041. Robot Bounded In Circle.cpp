#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int current_degrees = 0;
        int current_x = 0;
        int current_y = 0;
        for (int i = 0; i < instructions.length(); i++){
            if (instructions[i] == 'G'){
                if (current_degrees == 0)
                    current_y++;
                else if (current_degrees == 90 || current_degrees == -270)
                    current_x++;
                else if (current_degrees == 180 || current_degrees == -180)
                    current_y--;
                else if (current_degrees == 270 || current_degrees == -90)
                    current_x--; 
            }
            else {
                if (instructions[i] == 'L')
                    current_degrees = current_degrees + 90;
                else if (instructions[i] == 'R')
                    current_degrees = current_degrees - 90;
                current_degrees = current_degrees % 360;
            }
        }
        if (current_degrees == 0){
            if (current_x != 0 || current_y != 0)
                return false;
            else
                return true;
        }
        else
            return true;
    }
};