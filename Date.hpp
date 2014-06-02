#include <cstdlib> 
#include <string>

namespace calendar {
class Date {
  public:
    int day;
    int dayOfWeek;
    int month;
    int year;
    std::string dayName;
    std::string monthName;
    
//     Date() {
// 	this->today();
//     }
//     
//     Date(int day, int year, int month) {
//         
//       }
    
    
    Date() {
	std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday"};
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	time_t t = time(NULL);
	struct tm lc = *localtime(&t);
	this->year = lc.tm_year+1900;
	this->month = lc.tm_mon+1;
	this->day = lc.tm_mday;
	/* ------------------- Wzór Zellera na kalendarz wieczny -----------
	 * PACZAJ KOTKU CO JEST W ŚRODKU: http://pl.wikipedia.org/wiki/Kalendarz_wieczny
	 * 
	 */
	int z,c;
	if (this->month < 3) {
	  z = this->year-1;
	  c = 0;
	} else {
	  z = this-> year;
	  c=2;
	}
	

	this->dayOfWeek = ((((23 * this->month)/9)+ this->day + 4 + this->year + (z/4)-(z/100)+(z/400)-c)%7);
	
	// -----------------------------
	this->monthName = months[this->month-1];
	this->dayName = days[this->dayOfWeek];
	
    }
    int firstDay() {
	int z,c;
	if (this->month < 3) {
	  z = this->year-1;
	  c = 0;
	} else {
	  z = this-> year;
	  c=2;
	}
	
	int result  = ((((23 * this->month)/9)+ 1 + 4 + this->year + (z/4)-(z/100)+(z/400)-c)%7);	 
      
	if (result==0) result = 7;
	return result;
    }
    void nextMonth() {
	//NA RAZIE NIE AKTUALIZUJE DNIA TYGODNIA!!! TRZEBA ZROBIĆ PRYWATNĄ METODĘ GENETUJĄCĄ DZIEŃ TYGODNIA!!!
      	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	if(this->month < 12) {
	  this->month = this->month+1;
	} else {
	  this->month = 1;
	  ++this->year;
	}
	this->monthName = months[this->month-1];

    }
    
    
    
     void prevMonth() {
	//NA RAZIE NIE AKTUALIZUJE DNIA TYGODNIA!!! TRZEBA ZROBIĆ PRYWATNĄ METODĘ GENETUJĄCĄ DZIEŃ TYGODNIA!!!
      	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	if(this->month > 1) {
	  this->month = this->month-1;
	} else {
	  this->month = 12;
	  --this->year;
	}
	this->monthName = months[this->month-1];

    }
};

}