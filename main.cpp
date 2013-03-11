#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack.hpp"
#include <sstream>
#include <string>

using namespace std;

void infixToPostfix( ifstream&, Stack& );
void evaluateExpression(ifstream&, Stack&, bool& );
void evaluateOpr( Stack&, char& , bool& );
void discardExp(ifstream& in, char& a);
void printResult(Stack& stack, bool isExpOk);

//helper data val functions.
bool isNumber( string );
bool isOperator( string );

//conversion functions
template <class T>
string toString( T );
int intFromString( string );

int main() 
{
	
  Stack data; //creates an object type Stack
	
	bool validData = true;
	bool sectionDone = false;
	char a;
	Stack stack;
	stringstream tempOut;
	stringstream inputsl;
	ifstream input;
	
	input.open("input.txt");
	
	if(!input)
	{
		cout << "The input file does not exist." << endl;
		return 1;
	}
	
	//this is the shunting yard algorithm :-)
	//in wikipedia order because notes lost formatting... :-(
	
	while(!input.eof())
	{
		//for scope
		{
			string s;
			input >> s;
			inputsl << s;
			
		}
		cout << inputsl.str();
		while (!sectionDone) {
			
			if( inputsl.eof() ){
				sectionDone = true;
				continue;
			}
			
				
			
			inputsl >> a;
			
			cout << "Read " << a << endl;
			cout << "Sting Stream" << tempOut.str() << endl;
			
			validData = true;
			//numbers
			if( isNumber(toString(a))) {
				tempOut << a;
				cout << tempOut.str();
			}
			//operators
			if( isOperator(toString(a))){
				while( isOperator( stack.peek() ) ){
					//precedence handleing
					
					if( stack.peek() == "-" || stack.peek() == "+" ){
						if( a == '*' || a == '/' ){ 
							//do nothing 
						} else {
							tempOut << stack.pop(); //hit another plus/- pop
						}
						
					}
					
					if( stack.peek() == "*" || stack.peek() == "/" ){
						if( a == '+' || a == '-' )
							tempOut << stack.pop(); //pop
						else {
							//do nothing for other / *
						}
						
					}	
					
				}
				stack.push(toString(a));// push oper onto stack
			}
			
			//parens
			if( a == '(' ){
				stack.push( toString(a) );
			}
			else if ( a == ')' ) {
				string popped;
				do {
					popped = stack.pop();
					if( toString(a) != "(" || toString(a) != ")" ) 
						tempOut << a;
				} while (popped != "(");
				
			}
			
			
			
		}
		//rest of data off of stack
		cout << "Done Transforming\n";
		do {
			if ( stack.peek() == ")" ){
				validData == false;
				break;
			}
			tempOut << stack.pop();
		} while( stack.peek() != "" );
		cout << tempOut;
		evaluateExpression(input, stack, validData);
		printResult(stack, validData);
	}
	input.close();
	
	return 0;
}

void evaluateExpression(ifstream& inFile, Stack& stack, bool& isExpOk)
{
	char num;
	char a;
	while(a != '=')
	{
		switch(a)
		{
			case '#':
				inFile >> num;
				cout << num << " ";
				
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
	string op1s, op2s;
	int op1, op2;
	op2s = stack.pop(); 
	if(op2s == "")
	{
		cout << "Error";
		isExpOk = false;
	}
	else
	{
		op2 = intFromString(op2s);
		op1s = stack.pop();
		if(op1s == "")
		{
			cout << "Error";
			isExpOk = false;
		}
		else
		{
			op1 = intFromString(op1s);
			
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
	string answer;
	
	if(isExpOk)
	{
		
		answer = intFromString(stack.pop());
		
		
		if( answer == "")
			cout << answer << endl;
		else
			cout << "Too many operands." << endl;
	} 
	else
		cout << "Error in expression." << endl;
	
}

bool isOperator( string s ){
	string valid[] = { "+", "-", "/", "*","(", ")" };
	if( s.length() <= 2){ //for null terminated strings
	  return false;
	}
	for (int i=0; i < 6; i++) {
		if( !(s.find(valid[i]) == string::npos ) ){
			return true;
		}
	}
	return false;
}


bool isNumber( string s ){
  string valid[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
  for (int i=0; i < 10; i++) {
		if( !(s.find(valid[i]) == string::npos ) ){
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


