#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main ()
{
  time_t current_time;
  struct tm  local_time;

  time ( &current_time );
  localtime_s(&local_time, &current_time);

  int Year   = local_time.tm_year + 1900;
  int Month  = local_time.tm_mon + 1;
  int Day    = local_time.tm_mday;

  int Hour   = local_time.tm_hour;
  int Min    = local_time.tm_min;
  int Sec    = local_time.tm_sec;

  cout << "Hour: " << Hour << ":" << Min << ":" << Sec << endl;
  
  return 0;
}