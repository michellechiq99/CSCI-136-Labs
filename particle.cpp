/*
Author: Michelle Chiquitero
Course: CSCI-136
Instructor: Nick
Assignment: Lab 11F

This program creates a struct called particle and 
a different struct calld Coor3D that contains the 3
different coordinates for each variable position and 
velocity. 
It then uses and creates new pointers to dynamically
allocate memory and updating the velocity while moving
it's position continuously and having the final 
coordinantes displayed.  
*/

#include<iostream>
#include<cmath>
using namespace std;

struct Coord3D {
    double x;
    double y;
    double z;
};

struct Particle{
    Coord3D position;
    Coord3D velocity;
};

Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz);
void setVelocity(Particle *p, double vx, double vy, double vz);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);
   
    
Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz){
    Particle *newobject= new Particle;
    newobject->position = {x,y,z};
    newobject->velocity={vx,vy,vz};
                             
    return newobject;
}
void setVelocity(Particle *p, double vx, double vy, double vz){
    p->velocity={vx,vy,vz};
}
Coord3D getPosition(Particle *p){
    Coord3D newobject2;
    newobject2 = p-> position;
    return newobject2; 
}
void move(Particle *p, double dt){
    Coord3D pos = p->position;
    Coord3D vel= p->velocity;
	double x=0;
	double y=0;
	double z=0;
	double xvel=0;
	double yvel=0;
	double zvel=0;
	double resultsx=0;
	double resultsy=0;
	double resultsz=0;

	x=(pos).x;
	y=(pos).y;
	z=(pos).z;

	xvel=(vel).x;
	yvel=(vel).y;
	zvel=(vel).z;



	resultsx+= x+(xvel*dt);
	resultsy+=y+(yvel*dt);
	resultsz+=z+(zvel*dt);
	(pos).x= resultsx;
	(pos).y= resultsy;
	(pos).z= resultsz;
    p->position=pos;
    p->velocity=vel;
}
void deleteParticle(Particle *p){
    delete p;
}
int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
} 