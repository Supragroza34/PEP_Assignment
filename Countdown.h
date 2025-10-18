#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>


using std::cout;
using std::endl;

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:
// evaluateCountdown FUNCTION
double evaluateCountdown(const std::string &word){
    std::vector<double> rpnStack; //create a stack type structure using a vector
    std::stringstream ss(word); //
    std::string atom; //define a string atom - which will store the current value

    while (ss >> atom){
        if(atom == "+" || atom == "-" || atom == "*" || atom == "/"){

            if(rpnStack.size() <= 1){
                cout << "Not enough numbers for" << atom << endl;
                return 0.0;
            };
            double firstValue = rpnStack.back();
            rpnStack.pop_back();

            double secondValue = rpnStack.back();
            rpnStack.pop_back();

            switch (atom[0]){
                case '+':
                    rpnStack.push_back(secondValue + firstValue);
                    break;
                case '-':
                    rpnStack.push_back(secondValue - firstValue);
                    break;
                case '*':
                    rpnStack.push_back(secondValue * firstValue);
                    break;
                case '/':
                    if(firstValue== 0){
                        cout << "Dividing by 0" << endl;
                        return 0.0;

                    }
                    rpnStack.push_back(secondValue / firstValue);
                    break;
                default:
                    break;

            }
        } else {
            try{
                rpnStack.push_back(std::stod(atom));
            }catch (const std::exception& e){
                cout << "Invalid atom" << endl;
                return 0.0;
            }
        }
    }

    if (rpnStack.size() == 1){
        return rpnStack.back();
    } else {
        cout << "Error finding the atom" << endl;
        return 0.0;
    }

}


// solveCountdownProblem FUNCTION


// Do not edit below this line


#endif
