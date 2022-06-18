#include "Facade_pattern.hpp"

int main(int, char**) {
    Amplifier* amp = new Amplifier("Top-O-Line Amplifier");
    Tuner* tuner = new Tuner("Top-O-Line AM/FM Tuner", amp);
    DvdPlayer* dvd = new DvdPlayer("Top-O-Line DVD Player", amp);
    CdPlayer* cd = new CdPlayer("Top-O-Line CD Player", amp);
    Projector* projector = new Projector("Top-O-Line Projector", dvd);
    TheaterLights* lights = new TheaterLights("Theater Ceiling Lights");
    Screen* screen = new Screen("Theater Screen");
    PopcornPopper* popper = new PopcornPopper("Popcorn Popper");

    HomeTheaterFacade* homeTheater = 
            new HomeTheaterFacade(amp, tuner, dvd, cd, 
                    projector, screen, lights, popper);

    //homeTheater->watchMovie("Raiders of the Lost Ark");
    //homeTheater->endMovie();
    delete homeTheater;
    // std::cout  << "popper------------------\n";
    // popper->on();
    // std::cout  << "screen------------------\n";
    // screen->down();
    // std::cout  << "lights------------------\n";
    // lights->on();
    // std::cout  << "projector------------------\n";
    // projector->on();
    // std::cout  << "cd------------------\n";
    // cd->on();
    // std::cout  << "dvd------------------\n";
    // dvd->on();
    // std::cout  << "tuner------------------\n";
    // tuner->on();
    // std::cout  << "------------------\n";
    // std::cout  << "tuner------------------\n";
    // tuner->on();

// std::cout << "--------------\n";
// while (1)
// {

//     Amplifier* amp = new Amplifier("Top-O-Line Amplifier");
//     Tuner* tuner = new Tuner("Top-O-Line AM/FM Tuner", amp);
//     DvdPlayer* dvd = new DvdPlayer("Top-O-Line DVD Player", amp);
//     CdPlayer* cd = new CdPlayer("Top-O-Line CD Player", amp);
//     Projector* projector = new Projector("Top-O-Line Projector", dvd);
//     TheaterLights* lights = new TheaterLights("Theater Ceiling Lights");
//     Screen* screen = new Screen("Theater Screen");
//     PopcornPopper* popper = new PopcornPopper("Popcorn Popper");

//     HomeTheaterFacade* homeTheater = 
//             new HomeTheaterFacade(amp, tuner, dvd, cd, 
//                     projector, screen, lights, popper);

//     //homeTheater->watchMovie("Raiders of the Lost Ark");
//     //homeTheater->endMovie();
//     delete homeTheater;
// }


}
