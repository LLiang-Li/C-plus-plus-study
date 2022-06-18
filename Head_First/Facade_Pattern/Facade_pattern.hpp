#pragma once
#include <iostream>
#include <string>

class Tuner;
class DvdPlayer;
class CdPlayer;

class Amplifier {
	std::string description;
	Tuner* tuner;
	DvdPlayer* dvd;
	CdPlayer* cd;
	
    public:
        Amplifier(std::string description) {
            this->description = description;
        }
    
        void on() {
            std::cout << this->description + " on\n";
        }
    
        void off() {
            std::cout << description + " off\n";
        }
    
        void setStereoSound() {
            std::cout << description + " stereo mode on\n";
        }
    
        void setSurroundSound() {
            std::cout << description + " surround sound on (5 speakers, 1 subwoofer)\n";
        }
    
        void setVolume(int level) {
            std::cout << description + " setting volume to " << level << '\n';
        }

        void setTuner(Tuner* tuner) {
            std::cout << description + " setting tuner to " << tuner<< '\n';
            this->tuner = tuner;
        }
    
        void setDvd(DvdPlayer* dvd) {
            std::cout << description + " setting DVD player to " << dvd<< '\n';
            this->dvd = dvd;
        }
    
        void setCd(CdPlayer* cd) {
            std::cout << description + " setting CD player to " << cd<< '\n';
            this->cd = cd;
        }
    
        operator std::string () {
            return description;
        }
};

class CdPlayer {
	std::string description;
	int currentTrack;
	Amplifier* amplifier;
	std::string title;

	public:
        CdPlayer(std::string description, Amplifier* amplifier) {
            this->description = description;
            this->amplifier = amplifier;
        }
    
        void on() {
            std::cout << description + " on"<< '\n';
        }
    
        void off() {
            std::cout << description + " off"<< '\n';
        }

        void eject() {
            title = "";
            std::cout << description + " eject"<< '\n';
        }
    
        void play(std::string title) {
            this->title = title;
            currentTrack = 0;
            std::cout << description + " playing \"" + title + "\""<< '\n';
        }

        void play(int track) {
            if (title == "") {
                std::cout << description + " can't play track " << currentTrack << 
                        ", no cd inserted"<< '\n';
            } else {
                currentTrack = track;
                std::cout << description + " playing track " << currentTrack<< '\n';
            }
        }

        void stop() {
            currentTrack = 0;
            std::cout << description + " stopped"<< '\n';
        }
    
        void pause() {
            std::cout << description + " paused \"" + title + "\""<< '\n';
        }
    
        operator std::string() {
            return description;
        }
};


class DvdPlayer {
	std::string description;
	int currentTrack;
	Amplifier* amplifier;
	std::string movie;

	public:
        DvdPlayer(std::string description, Amplifier* amplifier) {
            this->description = description;
            this->amplifier = amplifier;
        }
    
        void on() {
            std::cout << description + " on"<< '\n';
        }
    
        void off() {
            std::cout << description + " off"<< '\n';
        }

        void eject() {
            movie = "";
            std::cout << description + " eject"<< '\n';
        }
    
        void play(std::string movie) {
            this->movie = movie;
            currentTrack = 0;
            std::cout << description + " playing \"" + movie + "\""<< '\n';
        }

        void play(int track) {
            if (movie == "") {
                std::cout <<description + " can't play track " << track << " no dvd inserted"<< '\n';
            } else {
                currentTrack = track;
                std::cout <<description + " playing track " << currentTrack << " of \"" + movie + "\""<< '\n';
            }
        }

        void stop() {
            currentTrack = 0;
            std::cout <<description + " stopped \"" + movie + "\""<< '\n';
        }
    
        void pause() {
            std::cout <<description + " paused \"" + movie + "\""<< '\n';
        }

        void setTwoChannelAudio() {
            std::cout <<description + " set two channel audio"<< '\n';
        }
    
        void setSurroundAudio() {
            std::cout <<description + " set surround audio"<< '\n';
        }
    
        operator std::string () {
            return description;
        }
};

class PopcornPopper {
	std::string description;

	public:
        PopcornPopper(std::string description) {
            this->description = description;
        }
    
        void on() {
            std::cout << description + " on"<< '\n';
        }
    
        void off() {
            std::cout << description + " off"<< '\n';
        }

        void pop() {
            std::cout << description + " popping popcorn!"<< '\n';
        }
    
    
        operator std::string() {
                return description;
        }
};

class Projector {
	std::string description;
	DvdPlayer* dvdPlayer;
	
    public:
        Projector(std::string description, DvdPlayer* dvdPlayer) {
            this->description = description;
            this->dvdPlayer = dvdPlayer;
        }
    
        void on() {
            std::cout << description + " on"<< '\n';
        }
    
        void off() {
            std::cout << description + " off";
        }

        void wideScreenMode() {
            std::cout << description + " in widescreen mode (16x9 aspect ratio)"<< '\n';
        }

        void tvMode() {
            std::cout<< description + " in tv mode (4x3 aspect ratio)"<< '\n';
        }
    
        operator std::string() {
                return description;
        }
};

class Screen {
	std::string description;
	
    public:
        Screen(std::string description) {
            this->description = description;
        }
    
        void up() {
            std::cout << description + " going up"<< '\n';
        }
    
        void down() {
            std::cout << description + " going down"<< '\n';
        }
    
    
        operator std::string() {
            return description;
        }
};

class TheaterLights {
	std::string description;
	
	public:
    TheaterLights(std::string description) {
		this->description = description;
	}
  
	void on() {
		std::cout << description + " on"<< '\n';
	}
  
	void off() {
		std::cout << description + " off"<< '\n';
	}
  
	void dim(int level) {
		std::cout  << description + " dimming to " <<  level  + "%"<< '\n';
	}
   
    operator std::string() {
            return description;
    }
};

class Tuner {
	std::string description;
	Amplifier* amplifier;
	double frequency;
	
	public:
    Tuner(std::string description, Amplifier* amplifier) {
		this->description = description;
	}
 
	void on() {
		std::cout << description + " on"<< '\n';
	}
 
	void off() {
		std::cout << description + " off"<< '\n';
	}
 
	void setFrequency(double frequency) {
		std::cout << description + " setting frequency to " << frequency<< '\n';
		this->frequency = frequency;
	}
 
	void setAm() {
		std::cout << description + " setting AM mode"<< '\n';
	}
 
	void setFm() {
		std::cout << description + " setting FM mode"<< '\n';
	}
  
    operator std::string() {
            return description;
    }
};

class HomeTheaterFacade {
	Amplifier* amp;
	Tuner* tuner;
	DvdPlayer* dvd;
	CdPlayer* cd;
	Projector* projector;
	TheaterLights* lights;
	Screen* screen;
	PopcornPopper* popper;
 
	public :
    HomeTheaterFacade(Amplifier* amp, 
				 Tuner* tuner, 
				 DvdPlayer* dvd, 
				 CdPlayer* cd, 
				 Projector* projector, 
				 Screen* screen,
				 TheaterLights* lights,
				 PopcornPopper* popper) {
 
		this->amp = amp;
		this->tuner = tuner;
		this->dvd = dvd;
		this->cd = cd;
		this->projector = projector;
		this->screen = screen;
		this->lights = lights;
		this->popper = popper;
	}
 
	void watchMovie(std::string movie) {
		std::cout << "Get ready to watch a movie..."<< '\n';
		popper->on();
		popper->pop();
		lights->dim(10);
		screen->down();
		projector->on();
		projector->wideScreenMode();
		amp->on();
		amp->setDvd(dvd);
		amp->setSurroundSound();
		amp->setVolume(5);
		dvd->on();
		dvd->play(movie);
	}
 
 
	void endMovie() {
		std::cout << "Shutting movie theater down..."<< '\n';
		popper->off();
		lights->on();
		screen->up();
		projector->off();
		amp->off();
		dvd->stop();
		dvd->eject();
		dvd->off();
	}

	void listenToCd(std::string cdTitle) {
		std::cout << "Get ready for an audiopile experence..."<< '\n';
		lights->on();
		amp->on();
		amp->setVolume(5);
		amp->setCd(cd);
		amp->setStereoSound();
		cd->on();
		cd->play(cdTitle);
	}

	void endCd() {
		std::cout << "Shutting down CD..."<< '\n';
		amp->off();
		amp->setCd(cd);
		cd->eject();
		cd->off();
	}

	void listenToRadio(double frequency) {
		std::cout << "Tuning in the airwaves..."<< '\n';
		tuner->on();
		tuner->setFrequency(frequency);
		amp->on();
		amp->setVolume(5);
		amp->setTuner(tuner);
	}

	void endRadio() {
		std::cout << "Shutting down the tuner..."<< '\n';
		tuner->off();
		amp->off();
	}
    ~HomeTheaterFacade()
    {
        delete amp;
        std::cout << "~amp\n";
	    delete tuner;
        std::cout << "~tuner\n";
	    delete dvd;
        std::cout << "~dvd\n";
	    delete cd;
        std::cout << "~cd\n";
	    delete projector;
        std::cout << "~projector\n";
	    delete lights;
        std::cout << "~lights\n";
	    delete screen;
        std::cout << "~screen\n";
	    delete popper;
        std::cout << "~popper\n";
    }
};