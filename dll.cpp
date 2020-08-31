#include <iostream>

using namespace std;

extern "C" void f()
{
    cout << "hi" << 1 << endl;

    bool is_eof = cout.eof();
    bool is_fail = cout.fail();
    bool is_bad = cout.bad();

    cout.clear();

    cout << endl;
    cout << "eof: " << to_string(is_eof) << endl;
    cout << "fail: " << to_string(is_fail) << endl;
    cout << "bad: " << to_string(is_bad) << endl;
}