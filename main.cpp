#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack.cpp"
#include "stack.hpp"
#include <sstream>
#include <string>

using namespace std;

void evaluateExpression(ifstream& inFile, ofstream& outFile, Stack& stack, char& a, bool& isExpOk);
void evaluateOpr(ofstream& out, Stack& stack, char& a, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& a);
void printResult(ofstream& outFile, Stack& stack, bool isExpOk);

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
    ofstream output;
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
        output << a;
        
        evaluateExpression(input, output, stack, a, validData);
        printResult(output, stack, validData);
        input >> a;
    }
    
    input.close();
    output.close();
    
    return 0;
}

void evaluateExpression(ifstream& inFile, ofstream& outFile, Stack& stack, char& a, bool& isExpOk)
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
                evaluateOpr(outFile, stack, a, isExpOk);
        }
        if(isExpOk)
        {
            inFile >> a;
            outFile << a;
            
            if(a != '#')
                outFile << " ";
        }
        else
            discardExp(inFile, outFile, a);
    }
}

void evaluateOpr(ofstream& out, Stack& stack, char& a, bool& isExpOk)
{
    int op1, op2;
    
    if(stack.EmptyStack())
    {
        out << "You do not have enough operands.";
        isExpOk = false;
    }
    else
    {
			op2 = intFromString( stack.pop() ); 
        
        if(stack.EmptyStack())
        {
            out << "Not enough operands";
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
                        out << "You cannot divide by 0.";
                        isExpOk = false;
                    }
                    break;
                default:
                    out << "You do not have a valid Operator";
                    isExpOk = false;
            }
        }
    }
}

void discardExp(ifstream& in, ofstream& out, char& a)
{
    while(a != '=')
    {
        in.get(a);
        out << a;
    }
}

void printResult(ofstream& outFile, Stack& stack, bool isExpOk)
{
    int answer;
    
    if(isExpOk)
    {
        if(!stack.EmptyStack())
        {
					answer = intFromString(stack.pop());
            
            if(stack.EmptyStack())
                outFile << answer << endl;
            else
                outFile << "You have too many operands." << endl;
        }
        else
            outFile << "You have an error in the expression." << endl;
    }
    else
        outFile << "You have an error in the expression." << endl;
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