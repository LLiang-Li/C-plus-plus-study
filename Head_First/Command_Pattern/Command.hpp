#pragma once

#include <iostream>
#include <string>
#include <vector>

class Command
{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual ~Command(){};
};

class Light
{
    public:
        Light(std::string name):Name(name) {}
        void On()
        {
            std::cout << this->Name <<": On\n";
        }
        void Off()
        {
            std::cout << this->Name <<": Off\n";
        }
        //~Light(){std::cout << "~Light\n";}
    private:
        std::string Name;
};

class LightOnCommand: public Command
{
    public:
        LightOnCommand(Light* L):light(L) {}

        void execute()
        {
            this->light->On();
        }

        void undo()
        {
            this->light->Off();
        }
        ~LightOnCommand()
        {
            if (this->light)
                delete this->light;
        }

    private:
        Light* light;
};

class LightOffCommand: public Command
{
    public:
        LightOffCommand(Light* L):light(L) {}

        void execute()
        {
            this->light->Off();
        }

        void undo()
        {
            this->light->On();
        }

        // ~LightOffCommand()
        // {
        //     if (this->light)
        //         delete this->light;
        // }

    private:
        Light* light;
};

class Stereo
{
    public:
        Stereo(const std::string &str):name(str) {}
        void on()
        {
            std::cout << this->name<<": On\n";
        }

        void off()
        {
            std::cout << this->name<<": Off\n";
        }
    private:
        std::string name;
};

class StereON: public Command
{
    public:
        StereON(Stereo* l):s(l) {}
        void execute()
        {
            if (this->s)
                s->on();
        }
        void undo()
        {
            if (this->s)
                s->off();
        }

        ~StereON()
        {
            if (this->s)
                delete s;
        }
    private:
        Stereo * s;
};

class StereOFF: public Command
{
    public:
        StereOFF(Stereo* l):s(l) {}
        void execute()
        {
            if (this->s)
                s->off();
        }
        void undo()
        {
            if (this->s)
                s->on();
        }
        // ~StereOFF()
        // {
        //     if (this->s)
        //         delete s;
        // }
    private:
        Stereo * s;
};

class remoteControl
{
    public:
        remoteControl():op(0){}
        void setCommand(Command* o, Command* f)
        {
            this->On.push_back(o);
            this->Off.push_back(f);
        }
        void comon(int index)
        {   
            if (index < On.size())
            {
                On[index]->execute();
                op = On[index];
            } 
        }

        void comoff(int index)
        {
            if (index < Off.size())
            {
                Off[index]->execute();
                op = Off[index];
            }
               
        }

        void comun()
        {
            if (op)
                op->undo();
        }

        ~remoteControl()
        {
            for(auto index : On)
                delete index;
            for(auto index : Off)
                delete index;
        }
    private:
        std::vector<Command*> On;
        std::vector<Command*> Off;
        Command * op;
};