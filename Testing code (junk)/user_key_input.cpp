#include <stdio.h>
#include <iostream>
#include <cconio>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

using namespace std;


int main()
{
   int KB_code=0;

   while(KB_code != KB_ESCAPE )
   {
     if (kbhit())
      {
            KB_code = getch();
            printf("KB_code = %i \n",KB_code);

            switch (KB_code)
            {
                case KB_LEFT:
                           //Do something
		cout << "Go Left" << endl;
                break;

                case KB_RIGHT:
                           //Do something
		cout << "Go Right" << endl;
                break;

                case KB_UP:
                           //Do something
		cout << "Go Up" << endl;
                break;

                case KB_DOWN:
                           //Do something
		cout << "Go Down" << endl;
                break;

            }

      }
  }

  return 0;
}
