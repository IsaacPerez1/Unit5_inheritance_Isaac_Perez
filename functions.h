#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip> // setw()
//#include "color.h"
//#include <stdlib.h> 
using namespace std;



class Cost
{
protected:
double  books= 100.00, food = 150.00, travel = 90.0, boarding = 400.00, rate= 59.0;//rate is cost per credit hour
double creditHour = 12;
public:
Cost(){}//default constructor

void setRate( double r) {rate = r;}
double getrate() const { return rate;}
void setCreditHour(double cr) {creditHour = cr ;}
double getCreditHour() const {return creditHour;}
void setBooks(double b) {books =b;}
double getBooks() const {return books;}
void setBoarding(double bo) {boarding = bo;}
double getBoarding()const {return boarding;}
void setFood(double f) {food =f;}
double getFood()const {return food;}
void setTravel(double t){travel =t;}
double getTravel()const{return travel;}

};

class semester: public Cost
{
  private: 
  int hoursPerClass = 3, monthsInSemester = 4;
  int semestersInAYear = 3;
  double hoursInADegree = 60.0;

public:
  semester(): Cost(){}

double tuition()
{return (creditHour * rate);}

double booksCost()
{return ( (books * creditHour ) / hoursPerClass);}

double boardingCost()
{return (boarding * monthsInSemester);}

double travelCost()
{return (travel * monthsInSemester);}

double foodCost()
{return (food * monthsInSemester);}

double semestersInAdegree()
{return ( hoursInADegree/creditHour );}

double costForDegree()
{return (totalCost() * semestersInAdegree());}

double timeInYears()
{return (semestersInAdegree() / semestersInAYear); }

double totalCost()
{return ( tuition() + booksCost() + boardingCost() + travelCost() + foodCost() );}

void setMonthsInSemester( int mis) {monthsInSemester = mis;}
int getMonthsInSemester() const { return monthsInSemester;}
void setHoursPerClass( int hpc) {hoursPerClass = hpc;}
int getHoursPerClass() const { return hoursPerClass;}
void setHoursInADegree(double dg){hoursInADegree = dg;}
double getHoursInADegree()const {return hoursInADegree;}
void setSemestersInAYear(int sy) {semestersInAYear =sy;}
int getSemestersInAYear()const{return semestersInAYear;}
};

void graph(semester full, semester part , semester half)
{
  string color= "\x1b[" + std::to_string(32) + ";1m";
  string color2= "\x1b[" + std::to_string(33) + ";1m";
  string color3= "\x1b[" + std::to_string(31) + ";1m";
  string reset = "\x1b[0m";
  
  cout <<"\nFull time cost: ";
  for(int i = 0; i < (full.costForDegree()/1000); i++ )
  {
    cout << color <<"=" << reset;
  }
  cout <<"\nPart time cost: ";
  for( int i =0; i< (part.costForDegree()/1000); i++)
  {
    cout <<color2 <<"=" << reset;
  }
  cout << "\nHalf time cost: ";
  for (int i =0; i < (half.costForDegree()/1000); i++)
  {
    cout << color3 << "=" << reset ;
  }
  

}

void showMenu(semester full, semester part, semester half)//not pass by refrence because no modification. only displaying
{
   string color= "\x1b[" + std::to_string(32) + ";1m";
   string reset = "\x1b[0m";

cout << "FULL TIME COST PER SEMESTER: " << endl;
cout <<"TUITION: $ " << full.tuition() <<(full.getrate() > 83.0 ? setw(51): setw(52)) <<  "Cost per credit hour: $" <<full.getrate() << endl;
cout << "ROOM AND BOARD: $ " << full.boardingCost(); cout << setw(38) << "Hours per class: " << full.getHoursPerClass() <<endl;
cout << "TRAVEL: $ " << full.travelCost(); cout <<setw(52) << "Months in a semester: " << full.getMonthsInSemester()<< endl;
cout << "FOOD: $ " << full.foodCost(); cout << setw(49)  << "Full time hours: " <<full.getCreditHour() << endl;
cout << "BOOKS: $ " << full.booksCost();cout <<setw(47) <<"Part time hours:" << part.getCreditHour()<< endl;
cout << "TOTAL COST: $ " <<full.totalCost() <<(full.getrate() > 586.0 ? setw(41): setw(42))  << "Half time hours: "<<half.getCreditHour() <<endl;
cout << setw(68) << "Book cost per class: $"<< full.getBooks();

cout << "\nPART TIME COST PER SEMESTER:"; cout << setw(50) << "Room and Board cost per month: $" <<full.getBoarding()<< endl;
cout << "TUITION: $" <<part.tuition()<<(full.getrate() > 111.0 ? setw(51): setw(52))  << "Food cost per month: $" <<full.getFood()<< endl;
cout << "ROOM AND BOARD: $ " << part.boardingCost();cout << setw(45) << "Travel cost per month: $" <<full.getTravel()<< endl;
cout << "TRAVEL: $ " << part.travelCost();cout << setw(51)<< "Semesters in a year: " << full.getSemestersInAYear()<< endl;
cout << "FOOD: $ " << part.foodCost();cout <<setw(51)<< "Hours in a degree: " << full.getHoursInADegree()<< endl;
cout << "BOOKS: $ " << part.booksCost() << endl;
cout << "TOTAL COST: $ " <<part.totalCost() <<  setw(51) << "COST AND TIME PER DEGREE: " <<endl;

 cout << setw(55) <<"Time for " << full.getHoursInADegree()<< " hrs @ full time : " << full.semestersInAdegree() << " semesters" ;
cout << "\nHALF TIME COST PER SEMESTER: " <<setw(26) << "Time for " << full.getHoursInADegree()<< " hrs @ part time : " << part.semestersInAdegree() << " semesters" << endl;
cout <<"TUITION: $ " << half.tuition() <<(full.getrate() > 166.0 ? setw(37): setw(38)) << "Time for " << full.getHoursInADegree()<< " hrs @ half time : " << half.semestersInAdegree() << " semesters" << endl;
cout << "ROOM AND BOARD: $ " << half.boardingCost() <<setw(30) << "Cost for " << full.getHoursInADegree() << " hrs @ full time : $"  <<full.costForDegree() <<endl; 
cout << "TRAVEL: $ " << half.travelCost() <<setw(39) << "Cost for " << full.getHoursInADegree() << " hrs @ part time : $"  <<part.costForDegree() << endl; 
cout << "FOOD: $ " << half.foodCost() << setw(41) <<"Cost for " << full.getHoursInADegree() << " hrs @ half time : $"  <<half.costForDegree() << endl;
cout << "BOOKS: $ " << half.booksCost() << setw(40) << "Time for " << full.getHoursInADegree() << " hrs @ full time : " << full.timeInYears()<< " years"<<endl; 
cout << "TOTAL COST: $ " <<half.totalCost() << setw(34)  << "Time for " << full.getHoursInADegree() << " hrs @ part time : " << part.timeInYears()<< " years"<< endl;
cout << setw(55) << "Time for " << full.getHoursInADegree() << " hrs @ half time : " << half.timeInYears()<< " years"<< endl;

graph(full, part, half);//show the graph 

}

void showOptions()
{
  cout << "\n-------------------------------------------------------------------------------------------" << endl;
cout << "\nWhat would you like to change? " << endl;
  cout << "A: Cost per credit hour" << endl;
  cout << "B: Hours per class" << endl;
  cout << "C: Months in a semester" << endl;
  cout << "D: Hours a full time student takes" << endl;
  cout << "E: Hours a part time student takes" << endl;
  cout << "F: Hours a half time student takes" << endl;
  cout << "G: Cost per book" << endl;
  cout << "H: Room and Baording cost per month" << endl;
  cout << "I: Food cost per month" << endl;
  cout << "J: Travel cost per month" << endl;
  cout << "K: Hours in a degree" << endl;
  cout << "X: Exit" << endl;
}
void handleOption(semester &full, semester &part, semester &half, char option)//pass by refrence to modify 
{
  double r,h;
  int hours;

  if(option == 'A' || option == 'a')
  {
    cout <<"\nWhat is the new rate: " << endl;
    r = validateDouble(r);
    full.setRate(r);
    part.setRate(r);
    half.setRate(r);
  }

  else if(option == 'b' || option =='B')
  {
    cout << "\nHow many hours per class: " << endl;
    hours = validateInt(hours);
    full.setHoursPerClass(hours);
    part.setHoursPerClass(hours);
    half.setHoursPerClass(hours);
  }
else if(option == 'd' || option == 'D')
  {
    cout << "\nHow many hours does a full time student take: " << endl;
    h=validateDouble(h);
    full.setCreditHour(h);
  }
  else if (option == 'c' || option == 'C')
  {
    cout << "\nHow many months in a semeseter: " << endl;
    h=validateDouble(h);
    full.setMonthsInSemester(h);
    part.setMonthsInSemester(h);
    part.setMonthsInSemester(h);
  }
  else if(option == 'e' || option == 'E')
  {
    cout << "\nHow many hours does a part time student take: " << endl;
    h=validateDouble(h);
    part.setCreditHour(h);

  }
  else if(option == 'f' || option == 'F')
  {
    cout << "\nHow many hours does a half time student take: " << endl;
    h=validateDouble(h);
    half.setCreditHour(h);
  }
  else if(option == 'g' || option== 'G')
  {
    cout << "\nWhat is the new books cost: " << endl;
    h=validateDouble(h);
    full.setBooks(h);
    half.setBooks(h);
    part.setBooks(h);
  }
  else if(option == 'h' || option == 'H')
  {
    cout << "\nWhat is the new room and boarding cost: "<< endl;
    h=validateDouble(h);
    full.setBoarding(h);
    part.setBoarding(h);
    half.setBoarding(h);
  }
  else if(option == 'I' || option == 'i')
  {
    cout <<"\nWhat is the new food cost per month:"<< endl;
   h=validateDouble(h);
    full.setFood(h);
    part.setFood(h);
    half.setFood(h);
  }
  else if(option == 'j' || option == 'J')
  {
    cout <<"\nWhat is the new travel cost per month:"<< endl;
    h=validateDouble(h);
    full.setTravel(h);
    part.setTravel(h);
    half.setTravel(h);
  }
  else if(option == 'k' || option == 'K')
  {
    cout <<"\nHow many hours in a degree" << endl;
    hours = validateInt(hours);
    full.setHoursInADegree(hours);
    part.setHoursInADegree(hours);
    half.setHoursInADegree(hours);
  }
  else  {cout << "\nSomething went wrong" << endl;}

}







#endif
