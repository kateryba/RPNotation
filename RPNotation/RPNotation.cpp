// RPNotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
#include <cmath>

using namespace std;

namespace RPN
{

    void skipSpaces(istringstream &inStream)
    {
        
        while (inStream.peek()==' ')
        {
            char dummy;
            inStream.get(dummy);
        }
    }

    int RPNCalculate(string in)
    {
        istringstream inStream(in);
        std::stack<int> inputFormNum;

        while (!inStream.eof())
        {
            char streamChar = inStream.peek();
            
            if (isdigit(streamChar))
            {
                int currentNum;
                inStream >> currentNum;
                inputFormNum.push(currentNum);
            }
             else
            {
                if (streamChar == ' ')
                {
                    skipSpaces(inStream);
                    continue;
                }
               
                if (streamChar == '+')
                {
                    int operandTwo = inputFormNum.top();
                    inputFormNum.pop();

                    int operandOne = inputFormNum.top();
                    inputFormNum.pop();

                    inputFormNum.push(operandOne + operandTwo);
                }
                else if (streamChar == '*')
                {
                    int operandTwo = inputFormNum.top();
                    inputFormNum.pop();

                    int operandOne = inputFormNum.top();
                    inputFormNum.pop();

                    inputFormNum.push(operandOne * operandTwo);
                }
                else if (streamChar == '^')
                {
                    int operandTwo = inputFormNum.top();
                    inputFormNum.pop();

                    int operandOne = inputFormNum.top();
                    inputFormNum.pop();

                    inputFormNum.push((int)pow(operandOne, operandTwo));
                }

                char dummy;
                inStream.get(dummy);
            }
        }

        return inputFormNum.top();
    }
}

int main()
{
    const string inputFormula = "3 15 + 1 7 9 + * 8 4 + + *";
    cout << inputFormula;
    cout << RPN::RPNCalculate(inputFormula);
    cin.get();
    return 0;
}


