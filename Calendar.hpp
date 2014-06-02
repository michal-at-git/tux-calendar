#include <map>
#include "Date.hpp"

namespace calendar {
 class Calendar {
   private:
     std::string dayOfWeek[7];
     calendar::Date date;
     
   public:
    Calendar(calendar::Date date) {     
      this->date = date;
    }
    
    int monthLength(int month, int year) {
      std::map<const int, int> monthList;
      monthList[1] = 31;
      
      if((year) % 4 && (year) % 400)
	monthList[2] = 29; //mies przestępny 28 lub 29
      else
	monthList[2] = 28;	
      
      monthList[3] = 31;
      monthList[4] = 30;
      monthList[5] = 31;
      monthList[6] = 30;
      monthList[7] = 31;
      monthList[8] = 31;
      monthList[9] = 30;
      monthList[10] = 31;
      monthList[11] = 30;
      monthList[12] = 31;
      
      return monthList[month];
    }
    
    
    int monthLength() {
      std::map<const int, int> monthList;
      monthList[1] = 31;
      
      if((this->date.year) % 4 && (this->date.year) % 400)
	monthList[2] = 29; //mies przestępny 28 lub 29
      else
	monthList[2] = 28;	
      
      monthList[3] = 31;
      monthList[4] = 30;
      monthList[5] = 31;
      monthList[6] = 30;
      monthList[7] = 31;
      monthList[8] = 31;
      monthList[9] = 30;
      monthList[10] = 31;
      monthList[11] = 30;
      monthList[12] = 31;
      
      return monthList[this->date.month];
    }
  };
  
}