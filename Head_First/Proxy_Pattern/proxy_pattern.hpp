#pragma once
#include <iostream>
#include <string>

class PersonBean
{
    public:
        virtual std::string getName() = 0;
        virtual std::string getGender() = 0;
        virtual std::string getInterests() = 0;
        virtual int getHotOrNotRating() = 0;
        virtual void setName(std::string) = 0;
        virtual void setGender(std::string) = 0;
        virtual void setInterests(std::string) = 0;
        virtual void setHotOrNotRating(int rating) = 0;
        virtual operator std::string() = 0;
};

class PersonBeanImpl: public PersonBean
{
    public:
        std::string getName()
        {
            return this->name;
        }
        std::string getGender()
        {
            return this->gender;
        }
        std::string getInterests()
        {
            return this->interests;
        }
        int getHotOrNotRating()
        {
            if(this->ratingCount == 0)
                return 0;
            return (this->rat / this->ratingCount);
        }
        void setName(std::string NAME)
        {
            this->name = NAME;
        }
        void setGender(std::string gen)
        {
            this->gender = gen;
        }
        void setInterests(std::string Instr)
        {
            this->interests = Instr;
        }
        void setHotOrNotRating(int rating){
            this->rat += rating;
            this->ratingCount++;
        }
        operator std::string()
        {
            std::string str = "name: " + name + ", " + "Gendaer: " + gender + ", Interests: " + interests + ", Val: " + std::to_string(this->rat / this->ratingCount) + "\n";
            return str;
        }
    private:
        std::string name;
        std::string gender;
        std::string interests;
        int rat;
        int ratingCount{0};
};

class Proxy_Myself:public PersonBean
{
    public:
        Proxy_Myself(PersonBean* pe):My(pe) {}
        std::string getName()
        {
            return this->My->getName();
        }
        std::string getGender()
        {
            return this->My->getGender();
        }
        std::string getInterests()
        {
            return this->My->getInterests();
        }
        int getHotOrNotRating()
        {
            return this->My->getHotOrNotRating();
        }
        void setName(std::string NAME)
        {
            this->My->setName(NAME);
        }
        void setGender(std::string gen)
        {
            this->My->setGender(gen);
        }
        void setInterests(std::string Instr)
        {
            throw "Can't modified\n";
        }
        void setHotOrNotRating(int rating){
            throw "Can't modified\n";
        }
        operator std::string()
        {
            return "";
        }
    private:
        PersonBean* My;
};

class Proxy_Other: public PersonBean
{
    public:
        Proxy_Other(PersonBean* pe):Other(pe) {}
        std::string getName()
        {
            return this->Other->getName();
        }
        std::string getGender()
        {
            return this->Other->getGender();
        }
        std::string getInterests()
        {
            return this->Other->getInterests();
        }
        int getHotOrNotRating()
        {
            return this->Other->getHotOrNotRating();
        }
        void setName(std::string NAME)
        {
            throw "Can't modified\n";
        }
        void setGender(std::string gen)
        {
            throw "Can't modified\n";
        }
        void setInterests(std::string Instr)
        {
            this->Other->setInterests(Instr);
        }
        void setHotOrNotRating(int rating){
            this->Other->setHotOrNotRating(rating);;
        }
        operator std::string()
        {
            return "";
        }
    private:
        PersonBean* Other;
};
