#include "Calendar.hpp"
#include "Screen.hpp"
#include <vector>

int main(void) {

  calendar::Date date;
  calendar::Calendar cal(date);
  
  int control = 0;
  do {
    if(control == 110) {
      date.nextMonth();
    }
    else if(control == 112) {
	date.prevMonth();
    }
     control = Screen::display(date.day, date.firstDay(), cal.monthLength(date.month, date.year), date.monthName, date.year);
     
  }
  while((control != 27) and (control != 113)); //27 ASCII ESC 71 q
  

  
  
}
