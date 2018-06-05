/*
Author: Michelle Chiquitero
Course: CSCI-136
Instructor: Nick 
Assignment: Lab 12F

This program takes in an array of 
any size and then with one function finds the sum of 
each element in the array by calling another function and 
then it checks if the sum is an odd # if it is it returns false
if not it returns the value in another func that checks if 
there is another possible =sum that can be created with the other elements
and using recursion once the sum=0 that means there is no longer
enough elements that can be distributed because all the elements 
parted equally returning true 
else it returns false and finally it checks 
if sum and be calc with last element or not
*/
#include<iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
int sumArrayInRange(int *arr, int left, int right);
bool isAlphanumeric(string s);
bool nestedParens(string s);
bool divisible(int *prices, int size);
bool checksubset(int *prices, int x, int sum);


void printRange(int left, int right){
	int x=left; //not needed but easier to understand 
	int y=right;
	if(x<y){
		cout<<x; //prints first number first
		cout<<" ";
		printRange(x+1,y);// prints the following left numbers by going back to func
		cout<<" ";
	}
	else if (x>y){
    cout<< " ";
	}
	else{
	    cout<<y;
	}
}
int sumRange(int left, int right){
	int x=0;
 	if(left<=right){ //base case
		x=left+sumRange(left+1,right);
 	}
 	else if (left>right){
 		return 0;
 	}
 	return x;
 }
int sumArrayInRange(int *arr, int left, int right){
 	int sum=0;
 	int total=0;
 	int i=0;
 	if(left<=right){
 	    sum+=arr[left];
 		sum+=sumArrayInRange(arr,left+1,right);
 	}
 	else if (right>left){
 		return 0;
 	}
    return sum;

}
int sumArray(int *arr, int size){
 	int sum2=0;
 	sum2+=sumArrayInRange(arr,0,size-1);
 	return sum2;
}
bool isAlphanumeric(string s){
//str.substr(3,5) 3 is the pos 5 is the len

    int i=0;
    int z=0;
    z=s.length()-1;
    string x;

    
     if( s.length()==0){
     
        return true;
    }
    else if (isalpha(s[i]) || isdigit(s[i])){
            x=s.substr(1,z); 
        return isAlphanumeric(x);
    }
    else{
        return false;
    }
}
bool nestedParens(string s){
	int i=0;
	int y=0;
	y=s.length();
	string x;
	int state=0;
	int state2=0;

	if(s.length()==0){
		return true;
	}
	else if(s[0]=='(' && s[y-1]==')'){
		x=s.substr(1,y-2);
		return nestedParens(x);
	}
	else{
		return false;
	}

}
bool checksubset(int *prices, int x, int sum){ //checks if there is another sum in the subset equal to original sum  
	if(sum==0){   //base case #1
		return true;
	}
	if(x==0 && sum!=0){ //base case #2
		return false;
	}
	if(prices[x-1]>sum){ //only if last element is > sum
		return checksubset(prices,x-1,sum);
	}
return checksubset(prices, x-1, sum) ||     //check if sum2 works if the last element isincluded
        checksubset(prices, x-1, sum-prices[x-1]); //or not including the last element
}

bool divisible(int *prices, int size){
	int sum1=0;

	sum1+=sumArray(prices,size); //gets sum of array first
	if(sum1%2 !=0) //makes sure the sum is not odd bc odd sums = no 2 subsets
		return false;
	return checksubset(prices,size,sum1/2);
}
int main(){
	int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
}