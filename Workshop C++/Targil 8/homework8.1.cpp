/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 1
This program will read in an expression, convert it 
to calculatable form, and then calculate the result*/

#include <iostream>
#include <string>
using namespace std;
#include "StackList.h"

string infixToPostfix(string exp);
//function to convert an infix number/operations expression to its postfix form
//receives string parameter
//returns the newly converted string
int calcPostfix(string exp);
//function to calculate a mathematical expression is postfix form
//receives string parameter
//returns int result of equation

int main() {
	string exp;
	cout << "enter an infix expression as a string" << endl;
	try { //any problems with List functions utilized by stack
		cin >> exp;
		string postfix = infixToPostfix(exp);
		cout << postfix << endl;
		cout << calcPostfix(postfix) << endl;
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	return 0;
}

string infixToPostfix(string exp) {
	/*ascii reference:
		( = 40		) = 41		* = 42		/ = 47		+ = 43		- = 45 */
	StackList stk;
	string str;

	int length = exp.length(), top;
	char ch, pop;

	for (int i = 0; i < length; i++) { //iterating through contents of string
		
		ch = exp[i];
		int ich = (int)ch; //will need this if going to add to stack, gets ascii value of char

		switch (ch) { //dealing with cases where ch is not a digit
		case '(': 
			stk.push(ich); //pushing ( to stack
			break;                                   

		case ')':
			pop = stk.pop(); //popping top value in stack, ascii representation of a char, and casting it to be char
			while (pop != '(') { 
				str.push_back(pop);
				str.push_back(' '); //insesrting space after appended char to string
				pop = stk.pop(); 
			}
			break;

		case '*': case '/': case '+': case '-': //when user enters operator
			if (!stk.isEmpty()) { //if stack is empty no need to check what's there
				top = stk.top(); //want to check if top item in stack is also operator, then will check precedence
				if (top == 40) { //40 is (, and only other type of element in stack besides operators
					stk.push(ich); //pushing the int value of operator to the stack
				}
				else { //it's an operator, now need to check precedence  if */ then just add to stack, +-, check if top is */
					while (top != 40) { //could be a few operators in a row, so keep going until either reach ( or pushed to stack
						if ((ch == '*') || (ch == '/')) { //mult and div come before add and sub so it doesn't matter what operator is currently at top
							stk.push(ich); //pushing the int value of operator to the stack
							break;
						}
						else { //ch is + or -
							if ((top == 43) || (top == 45)) { //43=+, 45=-, same like above case, same level precedence so just push to stack
								stk.push(ich); //pushing the int value of operator to the stack
								break;
							}
							else { //top value in stack is * or /
								pop = stk.pop(); //popping top value in stack, ascii representation of a char, and casting it to be char
								str.push_back(pop);
								str.push_back(' '); //insesrting space after appended char to string
								top = stk.top();
							}
						}
					}
				}
			}
			else { //stack is empty, nothing to check, just push 
				stk.push(ich); //pushing the int value of operator to the stack
			}
			break;

		default:
			break;  
		} //end switch

		if ((ch > 47) && (ch < 58)) { //if current char is a digit, 0-9 (ascii values 48-57)
			str.push_back(ch); //appending digit to string

			//as long as not at end of exp string and next char in string is not a digit
			if ((i != length - 1) && (exp[i + 1] < 48 || exp[i + 1] > 57)) {
				str.push_back(' '); //insert a space at end of string
			}
		}
	} //end for

	//taking any leftover elements in the stack and appending them to the string
	while (!stk.isEmpty()) {
		ch = stk.pop(); //popping top value in stack, ascii representation of a char, and casting it to be char
		str.push_back(ch); 
		str.push_back(' ');
	}
	return str;
}


int calcPostfix(string exp) {
	StackList stk; 
	int length = exp.length(), var, num1, num2;
	string st;

	for (int i = 0; i < length; i++) {  //string will always end with operator because post fix
		st = exp[i];

		if (st == " ") continue; //ignoring the spaces

		if (st != "*" && st != "/" && st != "+" && st != "-") {
			var = stoi(st); //int version of substring
			while (exp[i + 1] != ' ') { //will be space after next last digit of number
				if ((exp[i + 1] > 47) && (exp[i + 1] < 58)) { //accounting for number with multiple digits
					var = (var * 10) + (exp[i + 1] - '0'); //attaching the next 
					i++;
				}
			}
			stk.push(var); //putting the number on the stack to be used later
		}
		//now will go through each operator, perform the operation on the top 2 operands in the stack, and store the result back in the stack
		else if (st == "*") { //multiplication
			num2 = stk.pop(); 
			num1 = stk.pop();
			stk.push((num1 * num2));
		}
		else if (st == "/") { //division
			num2 = stk.pop();
			num1 = stk.pop();
			stk.push((num1 / num2));
		}
		else if (st == "+") { //addition
			num2 = stk.pop();
			num1 = stk.pop();
			stk.push((num1 + num2));
		}
		else if (st == "-") { //subtraction
			num2 = stk.pop();
			num1 = stk.pop();
			stk.push((num1 - num2));
		}
	}

	return stk.pop(); //popping final result in stack to return
}

/*enter an infix expression as a string
(5+3)*((20/10)+(8-6))
5 3 + 20 10 / 8 6 - + *
32

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework8.1\Debug\Homework8.1.exe (process 1968) exited with code 0.
Press any key to close this window . . .
*/
