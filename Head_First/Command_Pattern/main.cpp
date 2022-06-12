#include "Command.hpp"


int main(int, char**) {
    
    remoteControl* r = new remoteControl;
    // Light a("lige");
    // Light* lige = &a;
    Light* lige = new Light("lige");
    Light* lijin = new Light("lijin");
    Stereo* li = new Stereo("li");
    Stereo* liang = new Stereo("liang");

    Command * lige_on = new LightOnCommand(lige);
    Command * lige_off = new LightOffCommand(lige);
    Command * lijin_on = new LightOnCommand(lijin);
    Command * lijin_off = new LightOffCommand(lijin);

    Command* li_on = new StereON(li);
    Command* li_off = new StereOFF(li);
    Command* liang_on = new StereON(liang);
    Command* liang_off = new StereOFF(liang);

    r->setCommand(lige_on, lige_off);
    r->setCommand(lijin_on, lijin_off);
    r->setCommand(li_on, li_off);
    r->setCommand(liang_on, liang_off);

    r->comon(0);
    r->comon(1);
    r->comon(2);
    r->comon(3);
    r->comoff(3);
    r->comun();

    delete r;

   
    
}
