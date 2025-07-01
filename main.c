#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ll long long int
#define tds typedef struct 

// ** By St4rB0y {Jayesh Krishan Puri - 24155058} ** //

tds date{  // !! Structure !! //
    int year;
    int month;
    int day;
    int minutes;
    int hours;
    int sec;
}propertyDate;

void printLineStart(void);  // !! function prototype !! //

void printLineBreak(void);  // !! function prototype !! //

void printIntro(void);  // !! function prototype !! //

void askQuery(char abc[]);    // !! function prototype !! //

void printDate(propertyDate);    // !! function prototype !! //

void result(ll);  // !! function prototype !! //

ll findEpoch(propertyDate c);  // !! function prototype !! //

ll compareProperty(int, int);   // !! function prototype !! //

ll giveRes(propertyDate, propertyDate); // !! function prototype !! //


int main(){

    // ?? The Code starts here  ?? //

    // Two structures for the required query //
    propertyDate date_1;
    propertyDate date_2;

    printLineStart(); // function to print lines //

    printIntro(); // prints statement //
    askQuery("first"); // prints statement //
    scanf("%d:%d:%d:%d:%d:%d", &date_1.sec, &date_1.minutes, &date_1.hours, &date_1.day, &date_1.month, &date_1.year);
    // prints statement //
    printDate(date_1); // ^^ function to print the date ^^ //

    askQuery("second"); // prints statement //
    scanf("%d:%d:%d:%d:%d:%d", &date_2.sec, &date_2.minutes, &date_2.hours, &date_2.day, &date_2.month, &date_2.year);
    // prints statement //
    printDate(date_2); // ^^ function to print the date ^^ // 

    ll differenceCompared = giveRes(date_1, date_2); // ** function to calculate the difference b/w the two points in seconds ** // 

    result(differenceCompared);

    return 0;
}
   
// ^^ All of the functions used ^^ //

void printLineStart(void){  // prints statement //
    printf("\nThe code to calculate the difference between two given point on the axis of time\n\n<---------------------------------start---------------------------------------->\n\n");
    return;
}

void printLineBreak(void){  // prints statement //
    printf("\n<---------------------------------break---------------------------------------->\n");
    return;
}

void printIntro(void){  // prints statement //
    printf("Enter the Date in secs:min:hours:dd:mm:yyyy format (After 00:00:00:00:00:0000),\n");
    return;
}

void askQuery(char abc[]){  // prints statement with desired string //
    printf("Enter the %s date with time: ", abc);
    return;
}

void printDate(propertyDate date_0){ // prints the date give by struct form user //
    printf("Your date is %d seconds, %d minutes, %d hours & %d:%d:%d\n", date_0.sec, date_0.minutes, date_0.hours, date_0.day, date_0.month, date_0.year);
    return;
}

void result(ll differenceCompared){
    
    ll date =  (differenceCompared)/(60*24*60);
    ll time_sec = differenceCompared - date*60*24*60;
    ll time_min = time_sec/60;
    time_sec -= time_min*60;
    ll time_hour = time_min/60;
    time_min -= time_hour*60;

    printLineBreak();  // prints statement //

    printf("\nThe difference between the dates is %lld days and %lld hours, %lld minutes, %lld seconds\n", date, time_hour, time_min, time_sec);
    
    printLineBreak(); // prints statement //

    return;
}

ll giveRes(propertyDate d1, propertyDate d2){ // function to find difference from epoch time //
    ll dist1 = findEpoch(d1);
    ll dist2 = findEpoch(d2);

    return compareProperty(dist1, dist2);
}

ll compareProperty(int c1, int c2){   // function to make the output positive and give the difference between the two points //
    ll tellDiff = c1 - c2;
    if(tellDiff < 0){
        tellDiff *= -1;
    }
    return tellDiff;
}

ll findEpoch(propertyDate c){ // epoch function //
    
    propertyDate epochTime = {0};

    propertyDate finalResult;

    finalResult.year = c.year - epochTime.year - 1;
    switch (c.month -1)
    {
    case 0:
        finalResult.month = 0;
        break;
    case 1:
        finalResult.month = 31;
        break;
    case 2:
        finalResult.month = 59;
        break;
    case 3:
        finalResult.month = 90;
        break;
    case 4:
        finalResult.month = 120;
        break;
    case 5:
        finalResult.month = 151;
        break;
    case 6:
        finalResult.month = 181;
        break;
    case 7:
        finalResult.month = 212;
        break;
    case 8:
        finalResult.month = 243;
        break;
    case 9:
        finalResult.month = 273;
        break;
    case 10:
        finalResult.month = 304;
        break;
    case 11:
        finalResult.month = 334;
        break;
    case 12:
        finalResult.month = 365;
        break;
    }

    finalResult.day = c.day - epochTime.day;

    ll k = finalResult.year*365 + finalResult.month + finalResult.day;

    if(c.year % 4 ==0 && c.year%100 !=0 && c.month > 2){
        k++;
    }

    int j = (c.year - 1)/4;

    k += j;

    finalResult.sec = c.sec - epochTime.sec;
    finalResult.minutes = c.minutes - epochTime.minutes;
    finalResult.hours = c.hours - epochTime.hours;

    return k*(24*60*60) + ((finalResult.minutes + finalResult.hours*60)*60 + finalResult.sec);
}
