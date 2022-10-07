#include "PrintJob.h"

#ifdef _NAMESPACE_
using namespace PrintingStuff;
#endif

int main(int, char**) {
    std::string s{"1234"};
    thePrinter().reset();
    thePrinter().performSelfTest();
    thePrinter().submitJob(s);
    return 0;
}
