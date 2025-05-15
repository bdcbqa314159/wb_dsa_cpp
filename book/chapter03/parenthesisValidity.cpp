#include <cstring>
#include <iostream>

#include "Stack.hpp"

using namespace std;

bool IsValid(char expression[]) {
  int n = strlen(expression);

  Stack<char> stackChar = Stack<char>();

  for (int i = 0; i < n; ++i) {
    if (expression[i] == '{') {
      stackChar.Push('{');
    } else if (expression[i] == '[') {
      stackChar.Push('[');
    } else if (expression[i] == '(') {
      stackChar.Push('(');
    }

    else if (expression[i] == '}' || expression[i] == ']' ||
             expression[i] == ')') {
      if (expression[i] == '}' &&
          (stackChar.IsEmpty() || stackChar.Top() != '{'))
        return false;
      else if (expression[i] == ']' &&
               (stackChar.IsEmpty() || stackChar.Top() != '['))
        return false;
      else if (expression[i] == ')' &&
               (stackChar.IsEmpty() || stackChar.Top() != '('))
        return false;
      else
        stackChar.Pop();
    }
  }

  if (stackChar.IsEmpty())
    return true;
  else
    return false;
}

int main() {
  char expr[] = "{() [{}]}";
  char expr1[] = "{()[]}[";

  //   cout << "Please type the parenthesis expression ";
  //   cout << "then press ENTER!" << endl;
  //   cin >> expr;

  bool bo = IsValid(expr);

  cout << endl;
  cout << "The " << expr << " expression is ";
  if (bo)
    cout << "valid";
  else
    cout << "invalid";
  cout << endl;

  bo = IsValid(expr1);

  cout << endl;
  cout << "The " << expr1 << " expression is ";
  if (bo)
    cout << "valid";
  else
    cout << "invalid";
  cout << endl;

  return 0;
}