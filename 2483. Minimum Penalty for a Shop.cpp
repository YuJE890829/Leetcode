#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = customers.length();
        int always_open = total_penalty(customers, customers.length());
        //cout << always_open << endl;
        int min_penalty = always_open;
        int close_penalty = min_penalty;
        for (int i = customers.length() - 1; i >= 0; i--){
            if (penalty(customers[i], true) == 1)
                close_penalty = close_penalty + 1;
            else
                close_penalty = close_penalty - 1;
            //cout << close_penalty << " ";
            if (close_penalty <= min_penalty){
                ans = i;
                min_penalty = close_penalty;
            }
        }
        return ans;
    }
    int penalty(char hour, bool close){
        if (hour == 'Y' && close)
            return 1;
        if (hour == 'N' && !close)
            return 1;
        return 0;
    }
    int total_penalty(string customers, int close_hour){
        int total = 0;
        for (int i = 0; i < customers.length(); i++){
            total = total + penalty(customers[i], i >= close_hour);
        }
        return total;
    }
};