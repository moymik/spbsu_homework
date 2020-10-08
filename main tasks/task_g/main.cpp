#include <iostream>
#include <map>
#include <vector>
#include <string.h>

#define MAX_LEN 1000

using namespace std;

bool isVariable(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

bool getSolution(bool curValue, map < char, vector <char> > &variables, map < char, bool> &solution, char cur)
{
    if (solution.find(cur) != solution.end()) {
        if (solution[cur] != curValue)
            return false;
        else return true;
    }

    bool isPossible = true;
    solution[cur] = curValue;
    for (int i = 0; i < variables[cur].size() && isPossible; ++i) {

        isPossible = isPossible && getSolution(!curValue, variables, solution, variables[cur][i]);
    }
    return isPossible;
}

int main() {
    map < char, vector <char> > variables;
    map < char, bool> solution;
    char expression[MAX_LEN];
    printf("Input expression (format example (x || y) && (y || z)):\n");
    scanf("%s", expression);
    int expressionLen = strlen(expression);

    //initialize variables subjection
    for (int i = 0; i < expressionLen; ++i) {
        if (isVariable(expression[i])) {
            char firstVar = expression[i];
            ++i;
            while (i < expressionLen && !isVariable(expression[i])) {
                ++i;
            }
            char secondVar = expression[i];
            variables[firstVar].push_back(secondVar);
            variables[secondVar].push_back(firstVar);
        }
    }

    if (getSolution(true, variables, solution, variables.begin()->first)) {
        for (auto it : solution) {
            cout << it.first + 0 << ' ' << it.second << endl;
        }
    } else if (getSolution(false, variables, solution, variables.begin()->first)) {
        for (auto it : solution) {
            cout << it.first + 0 << ' ' << it.second << endl;
        }
    } else {
        cout << "There is no solution";
    }
}
