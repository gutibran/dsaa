#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            // handle invalid string
            if (s.size() % 2 != 0) {
                return false;
            }

            // create a stack
            vector<int> stack;

            // iterate through the strings characters
            for (size_t i = 0; i < s.size(); i++) {
                // check if the current character is an openning
                // also check for if the current is closing and the top element on the stack is the
                // corresponding closing one and the stack is not empty
                if (s[i] = '(' || s[i] == '{' || s[i] == '[') {
                    // add the opening character to the stack
                    stack.push_back(s[i]);
                } else if (s[i] == ')' && stack.back() == '(' && stack.size() > 0) {
                    stack.pop_back();
                } else if (s[i] == '}' && stack.back() == '{' && stack.size() > 0) {
                    stack.pop_back();
                } else if (s[i] == ']' && stack.back() == '[' && stack.size() > 0) {
                    stack.pop_back();
                } else {
                    // if a closing tag is seen before its correspondig opening one return false
                    return false;
                }
            }

            // return the boolean on the condition of if the stack is empty
            return stack.empty();
        }
};