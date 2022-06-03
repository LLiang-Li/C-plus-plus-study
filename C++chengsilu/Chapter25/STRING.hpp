#ifndef _STRING_HPP_
#define _STRING_HPP_
#include<iostream>
#include<cstring>

class String
{
    friend int operator==(const String &, const String &);
    friend std::ostream& operator<<(std::ostream&, const String &);
    friend std::istream& operator>>(std::istream&, String &);
    public:
        String():data(new char[1])
        {
            this->sz = 0;
            *this->data = '\0';
        }

        String(char *p)
        {
            this->sz = strlen(p);
            data = new char[this->sz + 1];
            if (data == 0)
                throw std::bad_alloc();
            else
                strcpy(this->data, p);
        }

        String(const String &s)
        {
            assign(s.data, s.sz+1);
        }

        String & operator=(const String & s)
        {
            if(this != &s)
            {
                delete[] data;
                assign(s.data, s.sz);
            }   
            return *this;
        }

        String& operator+=(const String & rhs)
        {
            std::cout << "ope+=\n";
            char* odata = this->data;
            assign(this->data, this->sz + rhs.sz + 1);
            strcat(this->data, rhs.data);
            delete [] odata;
            return *this;
        }

        ~String()
        {
            if (data)
                delete[] data;
        }

        int length()const{
            return this->sz;
        }

        void make_cstring(char *p, int len )const
        {
            if (this->sz <=len)
                strcpy(p, this->data);
            else
                throw("Not enough!");
        }

        char* make_cstring()const
        {
            return this->data;
        }

        operator const char*()
        {
            return data;
        }
    private:
        int sz;
        char* data;
        void assign(const char * s, unsigned len)
        {
            data = new char[len + 1];
            if (!data)
                throw std::bad_alloc();
            this->sz = len;
            strcpy(this->data, s);
        }
};


String operator+(const String & op1, const String & op2)
{
    std::cout <<"+1\n";
    String ret(op1);
    std::cout <<"+2\n";
    ret+=op2;
    return ret;
}

int operator==(const String &op1, const String &op2)
{
    return(strcmp(op1.data, op2.data)==0);
}

std::ostream& operator<<(std::ostream& os, const String & s)
{
    os << s.data;
    return os;
}

std::istream& operator>>(std::istream& os, String & p)
{
    char* q;
    os >> q;
    p = String(q);
    return os;
}

#endif