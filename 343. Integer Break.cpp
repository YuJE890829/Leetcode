#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        int max = 0;
        int product;
        for (int i = 1; n / i > 0; i++){
            if (n / i == 1)
                product = i * (n % i);
            else{
                product = pow(i, (n / i) - 1) * (i + (n % i));
                if (product > max)
                    max = product;
                product = pow(i, (n / i)) * ((n % i));
            }
            if (product > max)
                max = product;
        }
        return max;
    }
};