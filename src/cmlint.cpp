/*  C++ Macro Language
    Copyright (C) 2026 Rocco Himel
*/

#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::cin;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#define inpint(text, var) cout << text; cin >> var;
#define inpstr(text, var) cout << text; std::getline(cin, var);

int print(const std::string& inp)
{
    cout << inp;
    return 0;
}