#include<iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

template <typename C>
static auto opt_print (const C &container)
{
return [end_it (end(container))] (const auto &item) {
if (item != end_it) {
cout << *item << '\n';
} else {
cout << "<end>\n";
}
};
}

int main5()
{
    
    return 0;
}