//tuition calculator, Isaac Perez
//Dr_T 11/20/19
//inheritance
#include "input_validation.h"
#include "functions.h"
#include "color.h"

using namespace std;

int main() 
{
 cout << fixed <<setprecision(2);  
  semester full;
  semester part;
  semester half;

  char option;
  full.setCreditHour(12.0);
  part.setCreditHour(9.0);
  half.setCreditHour(6.0);
  
do{

cout << "\033[2J\033[1;1H";

showMenu(full, part, half);
//graph( full,  part , half);
showOptions();
option = validateChar(option);
handleOption(full, part,half, option );

}while(option != 'x' && option != 'X');
cout << "\033[2J\033[1;1H";
cout << "BYE";

  return 0;
}