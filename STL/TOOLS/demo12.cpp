#include"headers.h"

struct person {
    std::string name;
    size_t age;
    person(std::string n, size_t a)
    : name{std::move(n)}, age{a}
    { std::cout << "CTOR " << name << '\n'; }
    ~person() { std::cout << "DTOR " << name << '\n'; }
};

int main12()
{

    std::shared_ptr<std::string> shared_name;
    std::shared_ptr<size_t> shared_age;

    {
        auto sperson (std::make_shared<person>("John Doe", 30));
        std::cout << sperson.use_count()<<'\n';
        shared_name = std::shared_ptr<std::string>(sperson, &sperson->name);
        std::cout << sperson.use_count()<<'\n';
        shared_age = std::shared_ptr<size_t>(sperson, &sperson->age);
        std::cout << sperson.use_count()<<'\n';
    }
    std::cout << shared_age.use_count()<<'\n';
    std::cout << "name: " << *shared_name
        << "\nage: " << *shared_age << '\n';


    return 0;
}