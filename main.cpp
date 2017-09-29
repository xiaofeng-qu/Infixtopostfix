#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <limits>
#include "ListStack.hpp"
#include "ListStack.cpp"
#include "Constants.hpp"
#include "List.hpp"
#include "List.cpp"
using namespace std;
// Struct to hold operators
struct Operators{
    char op;
    int priority = 0;
};
// Struct to hold any input and its value
struct Inputs{
    char in;
    int value = 0;
    void operator=(Inputs input){
        in = input.in;
        value = input.value;
    }
    bool operator==(Inputs input){
        return in == input.in;
    }
};
ostream& operator<<(ostream& os, Inputs input){
        return os << input.in;
}
// Transform infix expression to postfix expression.
// Input parameter is a boolean.
// If input is true, evaluate the postfix expression.
// If input is false, do not evaluate the postfix expression.
void infixToPostfix(bool);
// Check whether a char is an operator
bool isOperator(char);
// Get the priority of an operator
int getpriority(char);
// Evaluate a postfix expression
int evaluatePostfixExpression(List<Inputs>);
void menu();

int main()
{
    menu();
    return 0;
}

void menu(){
    cout << "(1) Convert Infix to Postfix" << endl;
    cout << "(2) Evaluate Expression" << endl;
    cout << "(3) Exit\n" << endl;
    int menuItem;
    cin >> menuItem;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(menuItem){
        case 1:
                infixToPostfix(false);
                cout << endl;
                menu();
                break;
        case 2:
                infixToPostfix(true);
                cout << endl;
                menu();
                break;
        case 3:
                exit(0);
        default:
                cout << "No such option. Please choose from 1-3.\n" << endl;
                menu();
                break;
    }
}

void infixToPostfix(bool toEvaluate){
    List<Inputs> infixExpression;
    List<Inputs> postfixExpression;
    ListStack<Operators> postfixTransform;
    char x;
    int expressionLength = 0;
    cout << "Input your expression, end with #: " << endl;
    while (cin >> x){
        expressionLength++;
        Inputs in;
        in.in = x;
        infixExpression.append(in);
        Operators op;
        if(x == '('){
            op.op = x;
            postfixTransform.push(op);
        }
        else if(x == ')'){
            while(postfixTransform.topItem().op != '('){
                in.in = postfixTransform.topItem().op;
                postfixExpression.append(in);
                postfixTransform.pop();
            }
            postfixTransform.pop();
        }
        else if(!isOperator(x)){
            postfixExpression.append(in);
        }
        else{
            op.op = x;
            op.priority = getpriority(x);
            while(!postfixTransform.isEmpty()){
                if(postfixTransform.topItem().priority < op.priority) break;
                in.in = postfixTransform.topItem().op;
                postfixExpression.append(in);
                postfixTransform.pop();
            }
            postfixTransform.push(op);
        }
        if(expressionLength > MAX_EXPRESSION_LENGTH || x == '#'){
            while(!postfixTransform.isEmpty()){
                in.in = postfixTransform.topItem().op;
                postfixExpression.append(in);
                postfixTransform.pop();
            }
            break;
        }
    }
    cout << "Infix expression: " << " ";
    infixExpression.printList();
    cout << endl;
    cout << "Postfix expression: " << " ";
    postfixExpression.printList();
    cout << endl;

    if(toEvaluate){
        cout << "The result of the expression is: " << evaluatePostfixExpression(postfixExpression) << "." << endl;
    }
}

int evaluatePostfixExpression(List<Inputs> l){
    ListStack<int> postfixEvaluation;
    Inputs input;
    int value;
    for(int i=0; i<l.length(); i++){
        if(l[i].in=='#') break;
        switch(l[i].in){
            case '+': postfixEvaluation.plusTopTwo();
                      break;
            case '-': postfixEvaluation.minusTopTwo();
                      break;
            case '*': postfixEvaluation.multiplyTopTwo();
                      break;
            case '/':
                      try{
                          postfixEvaluation.divideTopTwo();
                          break;
                      } catch(char const *err){
                          cout << err << endl << endl;
                          menu();
                      }
            default:
                      if(i == l.find(l[i])){
                        cout << "Please input " << l[i].in << "'s value: ";
                        cin >> value;
                        input.in = l[i].in;
                        input.value = value;
                        l[i] = input;
                        postfixEvaluation.push(value);
                      }
                      else{
                        postfixEvaluation.push(l[l.find(l[i])].value);
                      }
        }
    }
    return postfixEvaluation.topItem();
}

bool isOperator(char op){
    switch(op){
        case '+':
        case '-':
        case '*':
        case '/':
        case '#': return true;
        default:  return false;
    }
}

int getpriority(char op){
    switch(op){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default:  return -1;
    }
}
