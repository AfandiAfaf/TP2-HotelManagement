#include <iostream>

#ifndef DATE_H
#define DATE_H
using namespace std;

   class Date {
   public:
      Date(int year=2021, int month=1, int day=1);//la date est initié à 2021 1 1

      int getYear() const;
      int getMonth() const;
      int getDay() const;

      void updateYear(int year);
      void updateMonth(int month);
      void updateDay(int day);

      void next();
      void back();

   private:
      int _year;
      int _month;
      int _day;

   };

   bool isDate(int year, int month, int day);
   int getDaysInMonth(int year, int month);
   int dayOfYear(Date d);
   std::string toString(Date d);
 // date

#endif // DATE_H