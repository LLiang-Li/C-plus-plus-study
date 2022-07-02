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
    private:
        std::string name;
        std::string gender;
        std::string interests;
        int rat;
        int ratingCount{0};
};