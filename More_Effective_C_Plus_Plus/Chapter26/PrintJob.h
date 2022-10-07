#ifndef _PRINTJOB_

#define _NAMESPACE_

#include <iostream>
#include <string>

#ifdef _NAMESPACE_
namespace PrintingStuff{
#endif
class PrintJob;
class Printer
{
    public:
        friend Printer& thePrinter();
        void submitJob(const PrintJob& job);
        void reset()
        {
            std::cout << "Reset Successful!\n";
        }
        void performSelfTest()
        {
            std::cout << "Self Test!\n";
        }
    private:
        Printer(){};
        Printer(const Printer& rhs);
        Printer& operator=(const Printer& rhs);
};

class PrintJob
{
    public:
        PrintJob(const std::string& str): content(str){}
        void disp() const
        {
            std::cout << "Print: \n" << this->content <<'\n'; 
        }
    private:
        std::string content;
};

void Printer::submitJob(const PrintJob& job)
{
    job.disp();
}

Printer& thePrinter()
{
    static Printer p;
    return p;
}

#ifdef _NAMESPACE_
}
#endif
#endif