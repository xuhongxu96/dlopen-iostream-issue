#include <iostream>
#include <dlfcn.h>
#include <cassert>

using namespace std;

using fn_t = void(void);

void call_f_in_dll(const char *dll_path)
{
    auto dll = dlmopen(LM_ID_NEWLM, dll_path, RTLD_LAZY);
    assert(dll);
    fn_t *fn = (fn_t *)dlsym(dll, "f");
    assert(fn);
    fn();
    dlclose(dll);
}

int main()
{
    call_f_in_dll("./libmydll.so");

    cout << endl;

    call_f_in_dll("./libmydll2.so");

    return 0;
}