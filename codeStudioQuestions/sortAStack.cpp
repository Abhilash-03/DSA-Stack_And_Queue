/*
Sort a Stack

Problem Statement
Suggest Edit
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
We can only use the following functions on this stack S.
is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.

Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
Explanation Of Sample Input 1:
9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last. 
Sample Input 2:
1
5
-3 14 18 -5 30
Sample Output 2:
30 18 14 -3 -5
Explanation Of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last. 
*/
#include<bits/stdc++.h>
using namespace std;

void sortedInserted(stack<int>& stack, int num){
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return ;
    }
    
    int n = stack.top();
    stack.pop();

    sortedInserted(stack, num);
    stack.push(n);

}

void sortStack(stack<int> &stack){
       
       if(stack.empty()){
        return ;
       }

       int num = stack.top();
       stack.pop();

       sortStack(stack);

       sortedInserted(stack, num);
}