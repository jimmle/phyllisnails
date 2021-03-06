#include "phyllis.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	Phyllis shop;

	string operation;
	string name, service, time;
	int n_time; bool run=true;

	while(run){
		cout << "Enter operation [Service, Print, Exit]: " << endl;
		cin >> operation;
		if(!shop.check_input("operation", &operation)){
			run=false;
			break;
		}
	 
		if(operation=="Service"||operation=="service"){
			cout << "Please enter a clientelle [Kim, Fancy, Lynn, Rose, Sandy, Lisa],[exit]: " << endl;
			cin >> name;	
			if(!shop.check_input("clientelle", &name)){
				run=false;
				break;
			}

			cout << "Please enter a service [full_set, fill, manicure, eyelasher, pedicure, off_buff, repair, nail_design, air_brush, silk_fiber, trim, coat, polish_change, am_man, fre_man, pink_white, paraffin, clear_gel, pink_white_gel, eu_facial, eyebrow, mask],[done],[stop],[exit]: " << endl;
			cin >> service;
			cout << endl;
			if(!shop.check_input("service", &service)){
				run=false;
				break;
			}
		
			/*
			cout << "Please enter time completed [in minutes],[exit]: " << endl;
			cin >> time;	
			if(!shop.check_input("time", &time)) return 0;
			n_time=atoi(time.c_str());
			*/

			shop.parse_input(name, service);
		}
		else if(operation=="Print"||operation=="print") shop.print_all();
		else if(operation=="Exit"||operation=="exit") run=false;
	}
	cout << endl;
	return 0;
}
