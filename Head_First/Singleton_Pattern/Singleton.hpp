#pragma once
#include <iostream>

class Singleton
{
    private:
        static Singleton * uniqueInstance;

        Singleton(){};

    public:
        static Singleton* getInstance()
        {
            
            if (!Singleton::uniqueInstance)
            {
                //std::cout << "create\n";
                Singleton::uniqueInstance = new Singleton;
            }
            return Singleton::uniqueInstance;
        }
};

 Singleton * Singleton::uniqueInstance = 0;
