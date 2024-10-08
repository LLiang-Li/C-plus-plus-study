#include <iostream>
#include <stdint.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "ota.hpp"

#if 0
int main(int, char**){
#if 0
    {
        std::string ss{":020000021000EC"};
        std::vector<std::vector<unsigned int>>* res =  ota::OtaToCan::instance()->start_decode(ss);
        std::cout << "----------------------------Hex Test----------------------------------\n";
        std::cout << ss << std::endl;
        std::cout << "-----" << ss.length() << "------------\n";
        for(auto& i : *res){
            for(auto& j : i){
                std::cout << std::hex << j << " ";
            }
            std::cout << '\n';
        }
        std::string ss1{":10015000002384F8C430FFF77FFD84F8B600FFF772"};
        res =  ota::OtaToCan::instance()->start_decode(ss1);

        std::cout << ss1 << std::endl;
        std::cout << "-----" << ss.length() << "------------\n";
        for(auto& i : *res){
            for(auto& j : i){
                std::cout << std::hex << j << " ";
            }
            std::cout << '\n';
        }

        std::cout << "----------------------------Hex Test----------------------------------\n";
    }
#endif
    {
        std::string ss{"S10F9F2030000000F8B500BFF8B500BF29"};
        std::vector<std::vector<unsigned int>>* res =  ota::OtaToCan::instance()->start_decode(ss);
        std::cout << "----------------------------Srec Test----------------------------------\n";
        std::cout << ss << std::endl;
        std::cout << "-----" << ss.length() << "------------\n";
        for(auto& i : *res){
            for(auto& j : i){
                std::cout << std::hex << j << " ";
            }
            std::cout << '\n';
        }
        std::string ss1{"S1139F2C4101020000420102000029010000002A44"};
        res =  ota::OtaToCan::instance()->start_decode(ss1);

        std::cout << ss1 << std::endl;
        std::cout << "-----" << ss.length() << "------------\n";
        for(auto& i : *res){
            for(auto& j : i){
                std::cout << std::hex << j << " ";
            }
            std::cout << '\n';
        }

        std::cout << "----------------------------Srec Test----------------------------------\n";
    }

    return 0;
}
#else
#include <fstream>
int main(int argc, char** argv){
    std::fstream file("ENNPBmu.hex");
    std::string content;
    std::vector<std::vector<unsigned int>>* res;
#if 0
    if(!file.is_open()){
        std::cout << "open failure!\n";
        return 1;
    }
    while (std::getline(file, content))
    {
        std::cout << content << ", " << std::dec << content.length() << '\n';
        res = ota::OtaToCan::instance()->start_decode(content);
        if(res == NULL){
            std::cout << "decode failure\n";
        }
        for(auto& i : *res){
            for(auto& j : i){
                std::cout << std::hex << j << " ";
            }
            std::cout << '\n';
        }
    }
#endif
    file.close();

    file.open("test.srec");
    if(!file.is_open()){
        std::cout << "open failure!\n";
        return 2;
    }

    while (std::getline(file, content))
    {
        std::cout << "len"<<std::dec << content.length()<<"len\n";
        std::cout << content << ", " << std::dec << content.length() << '\n';
        res = ota::OtaToCan::instance()->start_decode(content);
        if(res == NULL){
            std::cout << "decode failure\n";
        }
        for(auto& i : *res){
            for(auto& j : i){
                std::cout << std::hex << j << " ";
            }
            std::cout << '\n';
        }
    }
}
#endif