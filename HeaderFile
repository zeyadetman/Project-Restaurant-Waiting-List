/*	
	Project Resturant Waiting List using C++
*/



#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class customer                 
{
public:
	string name;
	int gsize;
	int status;
	customer* next;

	customer();
	customer(string,int,int);

}; // Node Customer

class waitinglist    
{
public:
	int tables;        //number of occupied tables
	int chairnum;      // number of chairs
	int totalcustomers;  // number of all customers
	customer*head,*tail;
	waitinglist();          //default
	waitinglist(int);        
	void newcustomer();     //new customer
	void diplaycustomer();   //display customer information based on name
	void displayall();        //display all customers
	void change () ;            // change status from 2 to 1
	void checktables();         //check available tables
	void diplayonstatus();        //display list based on status and total customers on this list
	void whobefore();          //display who before ? based on name
	void removecustomer(string);      //remove customer based on name
		
}; //LinkedList
