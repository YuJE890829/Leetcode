#include<string>
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* walkl1 = l1;
        ListNode* walkl2 = l2;
        ListNode* answer = new ListNode;
        ListNode* walkAns = answer;
        bool done = false;
        string sum_string = "";
        bool carry = false;
        while (!done){
            if (walkl1 != NULL && walkl2 != NULL)
                walkAns -> val = walkl1 -> val + walkl2 -> val;
            else if (walkl1 != NULL && walkl2 == NULL)
                walkAns -> val = walkl1 -> val;
            else if (walkl1 == NULL && walkl2 != NULL)
                walkAns -> val = walkl2 -> val;
            if (carry){
                walkAns -> val++;
                carry = false;
            }
            if (walkAns -> val > 9){
                carry = true;
                walkAns -> val = walkAns -> val - 10;
            }
            if (walkl1 != NULL)
                walkl1 = walkl1 -> next;
            if (walkl2 != NULL)
                walkl2 = walkl2 -> next;
            if (walkl1 != NULL || walkl2 != NULL || carry){
                walkAns -> next = new ListNode;
                walkAns = walkAns -> next;
            }
            else
                done = true;
                
        }
        return answer;
    }
};