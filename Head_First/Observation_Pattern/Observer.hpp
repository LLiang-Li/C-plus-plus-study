#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_

#include <iostream>
#include <vector>

class Observer
{
    public:
        virtual void update(float, float, float) = 0;
};

class DisplayElement
{
    public:
        virtual void display() = 0;
};

class Subject
{
    public:
        virtual void registerObserver(Observer*) = 0;
        virtual void removeObserver(Observer*) = 0;
        virtual void notifyObserver() = 0;
};

class WeatherData: public Subject
{
    public:
        WeatherData(){this->observers.clear();}

        void registerObserver(Observer* o)
        {
            observers.push_back(o);
        }

        void removeObserver(Observer* o) 
        {
            for (int i = 0; i < this->observers.size(); i++)
                if(o == observers[i])
                    observers.erase(observers.begin() + i);
        }

        void notifyObserver()
        {
            for(auto i : this->observers)
                i->update(temperature, hunidity, pressure);
        }

        void measurementsChanged()
        {
            this->notifyObserver();
        }

        void setMeasurement(float t, float h, float p)
        {
            this->temperature = t;
            this->hunidity = h;
            this->pressure;
            this->measurementsChanged();
        }

    private:
        std::vector<Observer*> observers;
        float temperature, hunidity, pressure;
};

class CurrentConditionsDisplay: public Observer, DisplayElement
{
    public:
        CurrentConditionsDisplay():weatherdata(0){}

        CurrentConditionsDisplay(Subject* Watherdata):weatherdata(Watherdata)
        {
            this->weatherdata->registerObserver(this);
        }

        void update(float t, float h, float p)
        {
            this->temperature = t;
            this->humidity = h;
            this->display();
        }
        void display()
        {
            std::cout << "tempeture:" <<this->temperature << " F degree and "<< this->humidity << " % humdity\n";
        }
    private:
        float temperature;
        float humidity;
        Subject* weatherdata;
};

#endif