#include"Observer.hpp"

int main(int, char**) {
     
    // WeatherData* wather = new WeatherData;
    // CurrentConditionsDisplay* cu = new CurrentConditionsDisplay(wather);

    // wather->setMeasurement(1.2,3.4,5.6);
    // wather->setMeasurement(2.2,3.4,5.6);

    // delete wather;
    // delete cu;

    WeatherData w;
    CurrentConditionsDisplay c,c1;
    w.registerObserver(&c);
    w.registerObserver(&c1);
    w.setMeasurement(1.2,3.4,5.6);
    w.setMeasurement(2.2,3.4,5.6);
    w.removeObserver(&c);
    std::cout << "------------------\n";
    w.setMeasurement(1.2,3.4,5.6);
    w.setMeasurement(2.2,3.4,5.6);

}
