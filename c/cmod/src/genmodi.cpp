#include <iostream>
#include <string>
#include <sstream>
#define SBC break; case
using namespace std;

string mod, name, s, ln;
char c;
void printfn(string n, string s) {
    string ret = s.substr(0, s.find('('));
    string args = s.substr(s.find('('));
    printf("    Cm_I_FUNC(%s, %s, %s)\n", name.c_str(), ret.c_str(), args.c_str());
}
int main() {
    cin >> mod;
    printf("Cm_DECL(%s,\n", mod.c_str());
    getline(cin, ln);

    while (getline(cin, ln)) {
        stringstream ss;
        ss << ln;
        ss >> c >> name;
        getline(ss, s);
        switch (c) {
        SBC 'A': printf("    Cm_I_ARR(%s, %s)\n", name.c_str(), s.c_str());
        SBC 'V': printf("    Cm_I_VAR(%s, %s)\n", name.c_str(), s.c_str());
        SBC 'F': printfn(name, s);
        }
    }
    printf(");");
}
