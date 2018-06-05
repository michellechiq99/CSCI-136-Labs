

/*
Author: Michelle Chiquitero
Course: CSCI-136
Instructor: Nick
Assignment: Lab10D

This program uses 2 different stucts each having their
own fields; Movie displays the title genre(using the new enumeration type)
and the duration in minutes;
Timeslot has within it the struct called movie and the start time 
of the movie from the start time and duration we convert start time 
to minutes and add it to duration and convert it back to hours and 
minutes for the end time.



*/
#include <iostream>
using namespace std;
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

struct Time {
    int h;
    int m;
};

struct Movie {
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

struct TimeSlot {
    Movie movie;     // what movie
    Time startTime; 
     // when it starts
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
void printTime(Time time);
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);


int main(){
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"Slumdog Millionare",DRAMA,120};
Movie movie4= { "It's Kind of a Funny Story",DRAMA,101};
//printMovie(movie1);
//printMovie(movie2);
//printMovie(movie3);
//printMovie(movie4);


TimeSlot morning = {movie1, {9, 15}};
scheduleAfter(morning, movie4); 
TimeSlot evening = {movie2, {19, 30}}; 
//printTimeSlot(morning);
//printTimeSlot(daytime);
//printTimeSlot(evening);








    /*int min=0;
    cin>>min;
    Time time4;
    cin>>time4.h;
    cin>>time4.m;
    printTime(addMinutes(time4, min));*/
    
    /*
    int x=0;
    int y=0;
   Time time1;
   cin>>time1.h;
   cin>>time1.m;
   x = minutesSinceMidnight(time1);
   Time time2;
   cin>>time2.h;
   cin>>time2.m;
   Time time3;
   cin>>time3.h;
   cin>>time3.m;
   y=minutesUntil(time2,time3); */
}
int minutesSinceMidnight(Time time){

    int minutestoHour=0;
    int totalminutes=0;
    int intialmin=0;
  
  
   minutestoHour=(time.h * 60);
   totalminutes += minutestoHour + time.m;
   
 
   return totalminutes;
}

 // convert hours to minutes minutesSinceMidnight
 //  Find big little 
 //  big-little
  
int minutesUntil(Time earlier, Time later){
    int earlierMin=0;
    int laterMin=0;
    int totalmin=0;
    earlierMin=minutesSinceMidnight(earlier);
    laterMin=minutesSinceMidnight(later); 
    
    totalmin= laterMin-earlierMin;
    
    return totalmin;
    
}
//minutessinceMidnight(time0)
// z= minutessincemidnight(time0)
//
Time addMinutes(Time time0, int min){
    int z=0;
    int totalminn=0;
    int divide=0;
    int divide2=0;
    int finishTotal=0;
    z= minutesSinceMidnight(time0);
    totalminn= z+min;
    
    divide=totalminn/60;
    divide2=divide*60;
    finishTotal= totalminn - divide2; 
    time0.h=divide;
    time0.m=finishTotal;
    
    return time0;
}
void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
    
void printTimeSlot(TimeSlot ts){
  int EndTime=0;
  int rstartTime=0;
  int hoursc1=0;
  int hoursc2=0;
  int finishing=0;
  int finalEnd=0;
  int y=0;


  y= minutesSinceMidnight(ts.startTime);
  rstartTime=y;


  finishing= rstartTime+ ts.movie.duration;

  hoursc1=finishing/60; //finds hours without remainder
  hoursc2=hoursc1*60; //converts the hours back to minutes to be able to find final hours
  finalEnd= finishing-hoursc2; //this stores the end time

 printMovie(ts.movie);
 cout << "[starts at" << ts.startTime.h<<":"<<ts.startTime.m<<","<< "ends by" << hoursc1 << " : "<<finalEnd<< "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  TimeSlot nextMovie1;
  nextMovie1.movie=nextMovie;
  nextMovie1.startTime=addMinutes(ts.startTime, ts.movie.duration);



  return nextMovie1; // stores end of movietime
}





//midnight variable set to 00:00 

//midnight is 00:00




void printTime(Time time) {   // time is the variable for struct Time
    cout << time.h << ":" << time.m; 
}
