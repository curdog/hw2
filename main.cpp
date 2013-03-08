#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack.cpp"
#include "stack.hpp"
#include <sstream>
#include <string>

using namespace std;

void evaluateExpression(ifstream& inFile, Stack& stack, char& a, bool& isExpOk);
void evaluateOprStack& stack, char& a, bool& isExpOk);
void discardExp(ifstream& in, char& a);
void printResult(Stack& stack, bool isExpOk);

bool isNumber( string );
bool isOperator( string );

template <class T>
string toString( T );


int intFromString( string );

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
    
    input >> a;
    while(input)
    {
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
                outFile << num << " ";
                
		stack.push( toString( num ) );
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
			op2 = intFromString( stack.pop() ); 
        
        if(stack.EmptyStack())
        {
            cout << "Error";
            isExpOk = false;
        }
        else
        {
            op1 = intFromString( stack.pop() );
            
            switch (a)
            {
                case '+':
                    stack.push( toString( op1 + op2 ) );
                    break;
                case '-':
                    stack.push( toString( op1 - op2 ) );
                    break;
                case '*':
                    stack.push( toString(  op1 * op2  ) );
                    break;
                case '/':
                    if (op2 != 0)
                        stack.push( toString( op1 / op2 ) );
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
					answer = intFromString(stack.pop());
            
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
		 
bool isOperator( string s ){
	string valid[] = { "+", "-", "/", "*","(", ")" };
	for (int i; i < 6; i++) {
		if( s.find(valid[i])){
			return true;
		}
	}
	return false;
}

template <class T>
string toString( T thing ){
  stringstream temp;
	temp << thing;
	string retMe = temp.str();
	return (string)retMe.c_str();
}


int intFromString( string s ){
	int conv;
	stringstream(s) >> conv;
	return conv;
}


