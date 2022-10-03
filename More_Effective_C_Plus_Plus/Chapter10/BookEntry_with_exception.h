#ifndef _BOOLENTRY_
#define _BOOLENTRY_

#include <iostream>
#include <list>
#include <string>
#include <exception>

#define Error

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
                  :theName(name), theAddress(address), theImage(0), theAudioClip(0)
                  {
                    try 
                    {
                        if(imageFileName != "")
                            this->theImage = new Image(imageFileName);
                        if(audioClipFileName != "")
                            this->theAudioClip = new AudioClip(audioClipFileName);
#ifdef Error
                        throw "123";
#endif
                    }
                    catch (...)
                    {
                        delete this->theImage;
                        delete this->theAudioClip;
                        throw ;
                    }
                };
        ~BookEntry()
        {
            delete this->theImage;
            delete this->theAudioClip;
        }
    private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    Image *theImage;
    AudioClip *theAudioClip;
};


#endif