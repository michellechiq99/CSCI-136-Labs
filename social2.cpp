
/*
Author: Michelle Chiquitero
Course: CSCI-136
Instructor: Nick
Assignment: Lab 13B

This program creates a class of type "Network" and adds a username
to an array that is a private memeber function 
in the class type but will only add it if it's an alphanumeric
if it's not empty using the length and setting that equal to zero 
and if it equals a username of an already placed username in the array 
otherwise it returns false.
*/
#include <iostream>
using namespace std;
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
  final= displayname+"("+"@"+username+")";
  return final;
}
void Profile::setDisplayName(string dspn){
  dspn=displayname;
}
class Network {
private:
    static const int MAX_USERS = 20; 
    int numUsers;                    
    Profile profiles[MAX_USERS];     
    bool following[MAX_USERS][MAX_USERS];    // new 
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // new
    void printDot();                         // new
};

/*
1. iterate through array
2. compare username to element in array.getusername
3. 
*/
int Network::findID(string usrn){
  int found=-1;
  for (int i=0;i<MAX_USERS;i++){
    if(usrn==profiles[i].getUsername()){ //username of string = element in array
        found=i;
    }
  }
  return found;
}

Network::Network(){
  numUsers=0;
  for(int i=0;i<MAX_USERS;i++){
    for(int j=0;j<MAX_USERS;j++){
      following[i][j]=false;
    }
  }
}

bool Network::addUser(string usrn,string dspn){
  string username1;
  if(numUsers>=20){
    return false;
  }
  if(usrn.length()==0){
        return false;
  }
  for(int j=0;j<usrn.length();j++){
    if(!isalnum(usrn[j]))
      return false;
   }
   for(int i=0;i<MAX_USERS;i++){
     username1=profiles[i].getUsername();
        if(username1== " "){
          profiles[i]=Profile(usrn,dspn);
          numUsers++;
          return true;
        }
        if(findID(usrn)>-1)
          return false;
    }
}
bool Network ::follow(string usrn1, string usrn2){
  if(findID(usrn1)==-1 || findID(usrn2)==-1){
    return false;
  }
  int usrnid1=findID(usrn1);
  int usrnid2=findID(usrn2);
  following[id1][id2]=true;
  return true;

}
void Network::printDot(){
  string getusrn;
  string getusrn2;
  cout<<"digraph {"<<endl;
  for(int i=0;i<numUsers;i++){
    getusrn=profiles[i].getUsername();
    cout<<"\t"<< "\""<<"@"<<getusrn<<"\""<<endl;
  }
  cout<<endl;
  for(int i=0;i<MAX_USERS;i++){
    getusrn2=profiles[i].getUsername();
    for(int j=0;j<MAX_USERS;j++){
      if(following[i][j]==true)
        cout<<"\t"<<"\""<<"@"<<getusrn2<<"\""<<"@"<<profiles[j].getUsername()<<"\""<<endl;
    }
  }
  cout<<"}"<<endl;
}
int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}