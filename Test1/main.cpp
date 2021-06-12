#include <iostream>
#include <string>
#include <vector>
struct Date
{
     int day{};
     int month{};
     int year{};
};

bool fileTheStruct(int u_day, int u_month, int u_year, Date &d)
{

     d.day = u_day;
     d.month = u_month;
     d.year = u_year;
     // if ok return true
     return true;
     //else false
}

bool checkForLeapYear(int year)
{
     if ((year % 4) == 0) // 1
     {
          if ((year % 100) == 0) // 2
          {
               if ((year % 400) == 0) // 3
               {                      // 4

                    //  std::cout << "Year " << year << " is leap year (it has 366 days)." << std::endl;
                    return true;
               }
               else // 5
               {
                    // std::cout << "Year " << year << " is not a leap year (it has 365 days)." << std::endl;
                    return false;
               }
          }
          else // 4
          {
               //std::cout << "Year " << year << " is leap year (it has 366 days)." << std::endl;
               return true;
          }
     }
     else // 5
     {
          //std::cout << "Year " << year << " is not a leap year (it has 365 days)." << std::endl;
          return false;
     }
     return 0;
}

void getFromString(std::string &buffer, int &year, int &month, int &day)
{
}

bool state(std::string &buffer) // for wrong input ab/23/20
{
     for (auto &ch : buffer)
     {
          if (isdigit(ch) || ch == '/')
          {
          }

          else
               return false;
     }
     return true;
}
int main()
{

     // data to store
     Date date;
     int day{};
     int month{};
     int year{};
     char character{'/'};
     bool format;
     // an test
     std::cout << "Enter: " << std::endl;
     std::string buffer;
     std::getline(std::cin, buffer);
     state(buffer); // use this information to prove that is corect format

     // get data from user
     std::cout
         << "Enter date in this format: format \" dd / mm / yy \" " << std::endl;
     std::cin >> day >> character >> month >> character >> year;

     // ading to the year normal format ex: 14 = 2014 / 20 = 1920

     if (year <= 14)
     {
          year += 2000;
     }
     else
     {
          year += 1900;
     }
     // check if the user provided values are in border:
     //     1950 - 2014 year
     // 0-31 for normal moounth
     // 0-28 for bisect year and only for february
     // 0-12 for months
     //##########

     if (year >= 1950 && year <= 2014)
     {
          if (checkForLeapYear(year))
          { //leap
               if (day >= 0 && day <= 29)
               {
                    if (month >= 0 && month <= 12)
                    {
                         // fill the structure
                         std::cout << "Valid day for leap year day: "
                                   << day << " ,month: "
                                   << month << ", year: "
                                   << year << std::endl;
                    }
                    else
                    {
                         std::cout << "Wrong month " << month << std::endl;
                    }
               }
               else
               {
                    std::cout << "Wrong day, " << day << " is not leap." << std::endl;
               }
          }
          else
          { // not leap
               if (day >= 0 && day <= 30)
               {
                    if (month >= 0 && month <= 12)
                    {
                         // fill the structure
                         std::cout << "Valid day for no leap year day: "
                                   << day << " ,month: "
                                   << month << ", year: "
                                   << year << std::endl;
                    }
                    else
                    {
                         std::cout << "Wrong month " << day << std::endl;
                    }
               }
               else
               {
                    std::cout << "Wrong day " << std::endl;
               }
          }

          //cal function to fill the struct
     }
     else
     {
          std::cout << "Wrong year: "
                    << year << " not in limits 1950 - 2014" << std::endl;
     }

     return 0;
}
