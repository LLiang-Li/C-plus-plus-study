#ifndef _BOOLENTRY_
#define _BOOLENTRY_

#include <iostream>
#include <list>
#include <string>
#include <exception>

#define Error

template<class T>
class my_auto_ptr{
    public:
        my_auto_ptr(T* p = NULL): ptr(p){}
        T* operator->()
        {
            return ptr;
        }
        ~my_auto_ptr()
        {
            if (NULL != this->ptr)
                delete this->ptr;
        }
    private:
        T* ptr;
};

class Image
{
    public:
        Image(const std::string& str): Str(str) {}
    private: 
        std::string Str;
};

class AudioClip
{
    public:
        AudioClip(const std::string& str):Audio(str) {}
    private:
        std::string Audio;
};

class PhoneNumber
{
    public:
        PhoneNumber(const int& num): Number(num) {};
    private:
        int Number;
};


class BookEntry{
    public:
        BookEntry(const std::string& name,
                  const std::string& address = "",
                  const std::string& imageFileName = "",
                  const std::string& audioClipFileName = "")
                  :theName(name), theAddress(address), 
                  theImage(imageFileName == "" ? 0 : new Image(imageFileName)), 
                  theAudioClip(audioClipFileName == "" ? 0 : new AudioClip(audioClipFileName))
                  {
                    try 
                    {
                      
#ifdef Error
                        throw "456";
#endif
                    }
                    catch (...)
                    {  
                        throw ;
                    }
                };
        ~BookEntry(){}
    private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    my_auto_ptr<Image> theImage;
    my_auto_ptr<AudioClip> theAudioClip;
};


#endif