#ifndef _BOOLENTRY_
#define _BOOLENTRY_

#include <iostream>
#include <list>
#include <string>
#include <exception>

#define Error

// #define Error_fun

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
                  :theName(name), theAddress(address), theImage(initImage(imageFileName)), theAudioClip(initAudioClip(audioClipFileName))
                  {
                    try 
                    {
                        // if(imageFileName != "")
                        //     this->theImage = new Image(imageFileName);
                        // if(audioClipFileName != "")
                        //     this->theAudioClip = new AudioClip(audioClipFileName);
#ifdef Error
                        throw "123";
#endif
                    }
                    catch (...)
                    {
                        this->cleanup();
                        throw ;
                    }
                };
        ~BookEntry()
        {
            this->cleanup();
        }
    private:
        std::string theName;
        std::string theAddress;
        std::list<PhoneNumber> thePhones;
        Image *theImage;
        AudioClip *theAudioClip;

        Image* const initImage(const std::string& str)
        {
            if(str != "")
                return new Image(str);
            else
                return  0;
        }

        AudioClip * const initAudioClip(const std::string& str)
        {
            try 
            {
                if(str != "")
                    return new AudioClip(str);
                else
                {
#ifdef Error_fun
                    throw "456";
#endif
                    return 0;
                }
            }
            catch(...)
            {
                delete this->theImage;
                throw;
            }
        }

        void cleanup()
        {
            delete this->theImage;
            delete this->theAudioClip;
        }
};


#endif