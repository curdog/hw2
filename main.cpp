#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack.cpp"
#include "stack.hpp"
#include <sstream>

using namespace std;

void evaluateExpression(ifstream& inFile, Stack& stack, char& a, bool& isExpOk);
void evaluateOprStack& stack, char& a, bool& isExpOk);
void discardExp(ifstream& in, char& a);
void printResult(Stack& stack, bool isExpOk);

template <class T>
string toString( T );

int main() 
{

  Stack data; //creates an object type Stack

    bool validData;
    char a;
    Stack stack;
    ifstream input;
    bool expressionOk;

    input.open("input.txt");
    
    if(!input)
    {
        cout << "The input file does not exist." << endl;
        return 1;
    }
    
    cout = 
    
    //output << fixed << showpoint;
    //output << setprecision(2);
    
    input >> a;
    while(input)
    {
      //stack.initializeStack();
        expressionOk = true;
        cout << a;
        
        evaluateExpression(input, stack, a, validData);
        printResult(stack, validData);
        input >> a;
    }
    
    input.close();
    
    return 0;
}

void evaluateExpression(ifstream& inFile, Stack& stack, char& a, bool& isExpOk)
{
    int num;
    
    while(a != '=')
    {
        switch(a)
        {
            case '#':
                inFile >> num;
                cout << num << " ";
                if(!stack.FullStack())
                    stack.push( to_string( num ) );
                else
                {
                    cout << "Error: Full" << endl;
                }
                break;
            default:
                evaluateOpr(stack, a, isExpOk);
        }
        if(isExpOk)
        {
            inFile >> a;
            cout << a;
            
            if(a != '#')
                cout << " ";
        }
        else
            discardExp(inFile, a);
    }
}

void evaluateOpr(Stack& stack, char& a, bool& isExpOk)
{
    int op1, op2;
    
    if(stack.EmptyStack())
    {
        cout << "Error";
        isExpOk = false;
    }
    else
    {
        op2 = stack.top();
        stack.pop();
        
        if(stack.EmptyStack())
        {
            cout << "Error";
            isExpOk = false;
        }
        else
        {
            op1 = stack.top();
            stack.pop();
            
            switch (a)
            {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0)
                        stack.push(op1 / op2);
                    else
                    {
                        cout << "Not divisible by 0";
                        isExpOk = false;
                    }
                    break;
                default:
                    cout << "Invalid Operator";
                    isExpOk = false;
            }
        }
    }
}

void discardExp(ifstream& in, char& a)
{
    while(a != '=')
    {
        in.get(a);
        cout << a;
    }
}

void printResult(Stack& stack, bool isExpOk)
{
    int answer;
    
    if(isExpOk)
    {
        if(!stack.EmptyStack())
        {
            answer = stack.pop();
            
            if(stack.EmptyStack())
                cout << answer << endl;
            else
                cout << "Too many operands." << endl;
        }
        else
            cout << "Error in expression." << endl;
    }
    else
        cout << "Error in expression." << endl;
}

template <class T >
string toString( T thing ){
  stringstream temp;
	temp << thing;
	return temp.str();
}
