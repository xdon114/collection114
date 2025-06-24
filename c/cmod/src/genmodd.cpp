#include <iostream>
#include <string>
#include <sstream>
#define SBC break; case
using namespace std;

string mod, name, s;
char c;
int main() {
    cin >> mod;
    string output = "Cm_DEF(" + mod + ",";
    getline(cin, s);
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;
        ss >> c >> name;
        output += " Cm_D(" + name + "),";
    }
    output.pop_back();
    output += ");";
    cout << output;
}
