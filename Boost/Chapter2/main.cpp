#include <iostream>
#include <fstream>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
  /*
  boost::timer
  */
  {
    boost::timer t;
    std::cout << "max timespan:" << t.elapsed_max() << '\n';
    std::cout << "min timespan:" << t.elapsed_min() << '\n';
    std::cout << "now time elpase" << t.elapsed() << '\n'; 
  }


  /*
  boost::timer
  */
  {
    // std::ofstream file("a.txt", std::ios_base::out);
    // boost::progress_timer pt(file);
    boost::progress_timer pt;
    for(int i = 0; i < 20; i++)
      std::cout << i << ' ';
    std::cout << '\n';
  }

  /*
  boost::progress_display
  */
  {
    boost::progress_display t(100);
    t += 10;
    t += 20;
    t += 30;
    t += 40;

    std::cout << '\n';
  }

  /*
  boost::gregorian::date
  */
  {
    boost::gregorian::date today(2022,1,20);
    std::cout << today.day();
    std::cout << '\n';
    std::cout << boost::gregorian::to_simple_string(today) << '\n';
    std::cout << boost::gregorian::day_clock::local_day() << '\n';
    tm ToTm = boost::gregorian::to_tm(boost::gregorian::day_clock::local_day());
    std::cout << ToTm.tm_hour;
  }

  /*
  boost::gregorian::date_duration
  */
  {
    boost::gregorian::date_duration dur(1);
    //dur.days();
  }

  /*
  boost::gregorian::date
  */
  {
    boost::gregorian::date_period period(boost::gregorian::date(2022,1,1), boost::gregorian::date(2023,1,1));
  }

  /*
  Hour, Minute, Second, Millisec
  */
  {
    boost::posix_time::hours h(1);
    boost::posix_time::minutes min(1);
    boost::posix_time::seconds sec(1);
    boost::posix_time::millisec msec(1);
  }

  /*
  boost::posix_time::ptime
  */
  {
    boost::posix_time::ptime t;
  }

}