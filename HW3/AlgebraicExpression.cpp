#include <string>
#include "AlgebraicExpression.h"
#include "Stack.h"
#include <iostream>
#include <ctype.h>
#include "Stack.cpp"
#include <algorithm>

using namespace std;

Stack<char> aStack;
Stack<string> bStack;
Stack<double> cStack;
int precedence(char c)
{
	if (c == '*' || c == '/')
		return 2;
	if (c == '-' || c == '+')
		return 1;
	return 0;
}
bool isOperator(char temp) {

	return ((temp == '+') || (temp == '-') || (temp == '/') || (temp == '*'));
}
//Part 1
string infix2prefix(const string exp){
	string revString = exp;
	reverse(revString.begin(), revString.end());
	string prefixString = "";
	char stackTop;
	//( 12 + 5 ) - 20 * 4
	// -+ 12  5  * 20  4
	for (int i = 0; i < revString.length(); i++)
	{
		aStack.getTop(stackTop);
		if (revString[i] == ' ')
		{
			prefixString = prefixString + revString[i];
		}
		else if (isdigit(revString[i]))
		{
			prefixString = prefixString + revString[i];

		}
		else if (revString[i] == ')') {
			aStack.push(revString[i]);
		}
		else if (revString[i] == '(') {
			while (stackTop != ')') {
				prefixString = prefixString + stackTop;
				aStack.pop();
				aStack.getTop(stackTop);
			}
			aStack.pop(stackTop);
		}
		else {
			while (!aStack.isEmpty() && stackTop != ')' && precedence(revString[i]) <= precedence(stackTop)) {
				prefixString = prefixString + stackTop;
				aStack.pop();
			}
			aStack.push(revString[i]); // save new operator
		}
	}
	while (!aStack.isEmpty()) {
		aStack.getTop(stackTop);
		prefixString = prefixString + stackTop;
		aStack.pop();
	}
	reverse(prefixString.begin(), prefixString.end());
	return prefixString;
}

//Part 2
string infix2postfix(const string exp) {
	string postfixString = "";
	char stackTop;
	//( 12 + 5 ) - 20 * 4
	// 12  5 +  20  4*-
	//(((100*2)+4)*(12-4))
	for (int i = 0; i < exp.length(); i++)
	{
		aStack.getTop(stackTop);
		if (exp[i] == ' ')
		{
				postfixString = postfixString + exp[i];
		}
		else if (isdigit(exp[i]))
		{
			postfixString = postfixString + exp[i];
		}
		else if (exp[i] == '(') {
			aStack.push(exp[i]);

		}
		else if (exp[i] == ')'){ 
			while (stackTop != '(') {
				postfixString = postfixString + stackTop;
				aStack.pop(stackTop);
				aStack.getTop(stackTop);

			}
			aStack.pop(stackTop);
		}
		else {
			while (!aStack.isEmpty() && stackTop != '(' && precedence(exp[i]) <= precedence(stackTop)) {
				postfixString = postfixString + stackTop;
				aStack.pop();
				

			}
				aStack.push(exp[i]); // save new operator
				aStack.getTop(stackTop);

		}
	}
	while (!aStack.isEmpty()) {
		aStack.getTop(stackTop);
		postfixString = postfixString + stackTop;
		aStack.pop();
	}
	return postfixString;
}
// Part 3
string prefix2infix(const string exp) {
	bool spaceGiven = false;
	string infixString;
	string stackTop;
	char tempVal;
	string multipledigits = "";
	//* + * 100 2 4 - 12 4
	//(((100 * 2) + 4) * (12 - 4))

	for (int i = exp.length() - 1; i >= 0; i--){

		tempVal = exp[i];
		if (isOperator(tempVal))
		{
			spaceGiven = spaceGiven + true;
			bStack.getTop(stackTop);
			string op1 = stackTop;
			bStack.pop();
			bStack.getTop(stackTop);
			string op2 = stackTop;
			bStack.pop();
			string temp = "(" + op1 + " " + tempVal + " " + op2 + ")";
			bStack.push(temp);
		}
		else if (isdigit(tempVal))
		{
			spaceGiven =true;
			multipledigits = multipledigits + tempVal;


		}
		else if(spaceGiven) {
			if (multipledigits.length() > 0) {

				string temp = "";

				for (int j = multipledigits.length() - 1; j >= 0; j--) {
					temp += multipledigits[j];
				}
				multipledigits = "";
				bStack.push(temp);
			}
			spaceGiven = false;


		}
	}
	while (!bStack.isEmpty()) {
	bStack.getTop(stackTop);
	infixString = infixString + stackTop;
	bStack.pop();
	}
	return infixString;
}
//Part 4
string prefix2postfix(const string exp) {
	string pre2post;
	pre2post = prefix2infix(exp);
	pre2post = infix2postfix(pre2post);
	return pre2post;
}

//Part 5
string postfix2infix(const string exp){
	string temp;
	temp = postfix2prefix(exp);
	temp = prefix2infix(temp);
	return temp;
	}

//Part 6
string postfix2prefix(const string exp){ 
	bool spaceGiven = false;
	string infixString;
	string stackTop;
	char tempVal;
	string multipledigits = "";
	//* + * 100 2 4 - 12 4
	//(((100 * 2) + 4) * (12 - 4))

	for (int i = 0; i < exp.length(); i++) {

		tempVal = exp[i];
		if (isOperator(tempVal))
		{
			spaceGiven = spaceGiven + true;
			bStack.getTop(stackTop);
			string op1 = stackTop;
			bStack.pop();
			bStack.getTop(stackTop);
			string op2 = stackTop;
			bStack.pop();
			string temp = " ";
			temp = temp + tempVal;
			temp = op1 + op2;
			bStack.push(temp);
		}
		else if (isdigit(tempVal))
		{
			spaceGiven = true;
			multipledigits = multipledigits + tempVal;


		}
		else if (spaceGiven) {
			spaceGiven = false;

			if (multipledigits.length() > 0) {

				string temp = " ";
				temp = temp + multipledigits;
				multipledigits = "";
				bStack.push(temp);
			}

		}
	}
	while (!bStack.isEmpty()) {
		bStack.getTop(stackTop);
		infixString = infixString + stackTop;
		bStack.pop();
	}
	return infixString;
}

//double evaluateInfix(const string exp) { 
//	string temp;
//	double infixEval = 0;
//	temp = infix2prefix(exp);
//	infixEval = evaluatePrefix(temp);
//	return infixEval;
//}

//double evaluatePrefix(const string exp){ 
//	bool spaceGiven = false;
//	string infixString;
//	bool nextDig;
//	double stackTop;
//	char tempVal;
//	string temp;
//	string multipledigits = "";
//
//	//* + * 100 2 4 - 12 4
//	for (int i = exp.length() - 1; i >= 0 ; i--)
//	{
//		tempVal = exp[i];
//		if (tempVal == ' ')
//		{
//			nextDig = true;
//		}
//		if (isdigit(tempVal))
//		{
//			temp = temp + tempVal;
//			cStack.push(stof(temp));
//		}
//		else {
//			cStack.getTop(stackTop);
//			double operation1 = stackTop;
//			cStack.pop();
//			cStack.getTop(stackTop);
//			double operation2 = stackTop;
//			cStack.pop();
//
//			if (tempVal == '+')
//				cStack.push(operation1 + operation2);
//			else if (tempVal == '-')
//				cStack.push(operation1 - operation2);
//			else if (tempVal == '/')
//				cStack.push(operation1 / operation2);
//			else if (tempVal == '*')
//				cStack.push(operation1 * operation2);
//		}
//		
//	}
//	cStack.getTop(stackTop);
//	return stackTop;
//}

//double evaluatePostfix(const string exp){ 
//	string temp;
//	double infixEval = 0;
//	temp = postfix2prefix(exp);
//	infixEval = evaluatePrefix(temp);
//	return infixEval;
//}