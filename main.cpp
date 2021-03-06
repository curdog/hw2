#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack.hpp"
#include <sstream>
#include <string>

using namespace std;


void evaluateExpression(stringstream&, Stack&, bool& );
void evaluateOpr( Stack&, string& , bool& );
void printResult(Stack& stack, bool isExpOk);

//helper data validation functions.
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
		cout << "The input file does not exist.\n";
		return 1;
	}
	
	//this is the shunting yard algorithm :-)
	//in wikipedia order because notes lost formatting... :-(
	
	while(!input.eof())
	{
		//for scope, s is temporary for line read
		
			string s;
			input >> s;
		  inputsl.clear();
		  inputsl.flush();
			inputsl << s;
			
		
		
		while (!inputsl.eof()) {
			
			inputsl >> a;
			
			validData = true;
			//numbers
			if( isNumber(toString(a))) {
				tempOut << a;
			}
			//operators
			else if( isOperator(toString(a))){
				
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
			else if( a == '(' ){
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
			
			//all case
			else {
				cout << "Incorrect Data format.  Results may be incorrect.\n";
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
		
		cout << "RPN: " << tempOut.str() << endl;
		evaluateExpression(tempOut, stack, validData);
		printResult(stack, validData);
		
		//clear stack
		while (stack.pop() != "");
	}
	input.close();
	
	return 0;
}

void evaluateExpression(stringstream& expression, Stack& stack, bool& isExpOk)
{
	char a;
	while (!expression.eof()) {
		expression >> a;
		if( isNumber( toString( a )) ){
			stack.push( toString(a) );
		}
		else if( isOperator(toString(a)) ){
			string s = toString(a);
			evaluateOpr( stack, s , isExpOk );
			
		} else {
			cout << "Incorrect Data Results may be incorrect\n";
		}
	}
	
}

void evaluateOpr(Stack& stack, string& a, bool& isExpOk)
{
	string op1s, op2s;
	int op1, op2;
	op2s = stack.pop(); 
	if(op2s == "")
	{
		cout << "Error\n";
		isExpOk = false;
	}
	else
	{
		op2 = intFromString(op2s);
		op1s = stack.pop();
		if(op1s == "")
		{
			cout << "Error\n";
			isExpOk = false;
		}
		else
		{
			op1 = intFromString(op1s);
			
			if (a == "+"){ 
				stack.push( toString( op1 + op2 ) );
			}else if (a == "-") {
				stack.push( toString( op1 - op2 ) );
			}else if (a=="*") {
				stack.push( toString(  op1 * op2  ) );
			}else if (a=="/" && op2 != 0 ) {
				stack.push( toString( op1 / op2 ) );
			} else {
				cout << "Not a valid Expression.  Results may be incorrect.\n";
			}
			
		}
	}
}



void printResult(Stack& stack, bool isExpOk)
{
	string answer;
	
	if(isExpOk)
	{
		
		answer = stack.pop();
		
		
		if( answer == "")
			cout << answer << endl;
		else
			cout << "Too many operands." << endl;
	} 
	else
		cout << "Error in expression." << endl;
	
}

bool isOperator( string s ){
	string valid[] = { "+", "-", "/", "*" };
	
	for (int i=0; i < 4; i++) {
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


