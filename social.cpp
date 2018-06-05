/*
Author: Michelle Chiquitero
Course: CSCI-136
Instructor: Nick
Assignment: Lab 13A

This program creates a class of type "Profile" with private 
properties and a public interface with members that take
the username and display name from the private prpoerties and assign 
them to new variable names to be able to update the display name and 
print it in the format display(@username)
*/
using namespace std;
#include <iostream>

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};
Profile::Profile(string usrn, string dspn){
	username=usrn;
	displayname=dspn;
}
Profile::Profile(){
	username=" ";
	displayname=" ";

}
string Profile::getUsername(){
	return username;
}
string Profile::getFullName(){
	string final;
	final+= displayname+" "+"("+"@"+username+")";
	return final;
}
void Profile::setDisplayName(string dspn){
	displayname=dspn;
}
int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}