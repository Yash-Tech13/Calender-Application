#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};

typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;

int inputyear(void);
int determinedaycode(int year);
int determineleapyear(int year);
void calendar(int year, int daycode);
int dayofweek(int d, int m, int y);
char *getName(int day);

int main()
{
  Note date;
  Note data[100];
  int i=0, j=0,x;
  char choice;
  int month,year;

  for(int i=0;i<100;i++)
  {
    data[i].day=-1;
    data[i].month=-1;
    data[i].year=-1;    
  }

  do{
    printf("-------------Menu-----------------\n");
    printf("----------------------------------\n");
    printf("1. Find the day\n");
    printf("2. Print calendar of a year\n");
    printf("3. Add Note\n");
    printf("4. View Notes\n");
    printf("5.Check leap year\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("\n%c", &choice);

    switch(choice)
    {
      case '1':
      printf("----------------------------------\n");
      printf("Enter the day, month and year: ");
      scanf("%d %d %d", &date.day, &date.month, &date.year);
      printf("The day is : %s\n", getName(dayofweek(date.day, date.month, date.year)));
      break;

      case '2':
      printf("----------------------------------\n");
      int year, daycode, leapyear;
	    year = inputyear();
	    daycode = determinedaycode(year);
	    determineleapyear(year);
	    calendar(year, daycode);
	    printf("\n");
      break;

      case '3':
      printf("----------------------------------\n");
      printf("Enter the day, month and year: ");
      scanf("%d %d %d", &data[i].day, &data[i].month, &data[i].year);
      printf("Enter the note: ");
      scanf("%s",data[i].note);
      printf("Note added sucessfully\n");
      i++;
      break;

      case '4':
      printf("----------------------------------\n");
      printf("Enter month and year: ");
      scanf("%d %d",&month,&year);
      j=0;
      while(data[j].month!=-1)
      {
        if(data[j].month == month && data[j].year == year)
        {
          printf("%d/%d/%d: %s\n",data[j].day,data[j].month,data[j].year,data[j].note);
        }
        j++;
      }
      break;
      
      case '5':
      printf("Enter year you want to check:");
      scanf("%d",&year);
      x=determineleapyear(year);
      if(x==1)
        printf("%d is a leap year.\n",year);
      else
        printf("%d is not a leap year.\n",year);
      break;  

      case '6':
      printf("----------------------------------\n");
      printf("Bye!!\n");
      break;

      default:
      printf("Enter valid number.\n");
    }
  }while(choice!='6');

  return 0;
}

int inputyear()
{
	int year;
	
	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if((year% 4 == FALSE && year%100 != FALSE) || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			
			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

int dayofweek(int d, int m, int y)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

char *getName(int day){ //returns the name of the day
   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("Error: Invalid Argument Passed");
   }
}
