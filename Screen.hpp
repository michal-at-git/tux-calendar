#include <ncurses.h>

class Screen {
public:
  static int display( int day, int dayOfWeek, int monthLength, std::string monthName, int year) { 
    initscr();
    curs_set(0);
    start_color();
    use_default_colors();
    
    /*sunday theme */
    init_pair(1,COLOR_RED, COLOR_BLACK);
    
    printw(" ");
    clear();
    
    noecho();
    int x, y;
    getmaxyx(stdscr, y,x);
    
    attron(A_REVERSE);
      printw("Tux Calendar");
      
   for(int i=x-12; i>0; i--) { 
     addch(' ');
     refresh();
   }

    attroff(A_REVERSE);
    refresh();
    move(y/2,x/2); 
    printw("%s %i\n", monthName.c_str(),year);
    move(((y/2)+1),x/2); 
    refresh();
    attron(A_REVERSE);
    printw("  M   T   W   T   F   S   S \n");
    attroff(A_REVERSE);
    refresh();
    
    //int limit = monthLength+dayOfWeek;
    
    move((y/2+2),(x/2));

    refresh();
    for(int i=1, d=1; d<=monthLength; i++){
      if(d==day) attron(A_REVERSE);
      
      if(i< dayOfWeek) {
	printw("    ");

	refresh();
      } else {
	  if(d<10) {
	    if(i%7 == 0) {
	      attron(COLOR_PAIR(1));
	      printw("  %i \n",d);
	      attroff(COLOR_PAIR(1));
	      move((y/2+(i/7)+2),x/2);
	    refresh();}
	    else {
	    printw("  %i ",d);
	    refresh();
	    }
	  } else {
	    if(i%7 == 0) {
	      attron(COLOR_PAIR(1));
	      printw(" %i \n",d);
	      attroff(COLOR_PAIR(1));
	      move((y/2+(i/7)+2),x/2);

	    refresh();}
	    else {
	    printw(" %i ",d);
	    refresh();
	  }
	}
	 //DAY ITERATION
    }
    if(d==day) attroff(A_REVERSE);
     if(i>= dayOfWeek) d++;
  }
  refresh();
  attron(A_REVERSE);

  move(y-1,0);
  printw("n - next, p - previous, q/esc - quit");
  for(int i=x-36; i>0; i--) { 
     addch(' ');
     refresh();
   }
  attroff(A_REVERSE);
    noecho();
    int control = getch();

    endwin();

    return control;
  }

};