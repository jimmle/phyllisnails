#include "phyllis.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

Phyllis::Phyllis(){
	string name;
	bool run = true;
	emp_num = 0;

	while(run){
		cout << "Enter employee available[Kim, Fancy, Lynn, Rose, Sandy, Lisa], [done]: " << endl;
		cin >> name;	
		
		if(check_input("clientelle", &name)){
			init_employee(name);
		}
		else run=false;
	 }
};

void Phyllis::init_employee(string name){
	/*ofstream file_write;
	file_write.open("employees.txt");
	file_write.close();*/	
	
	person[emp_num].name = name;

	fstream file;

	file.open("employees.txt");
	string line;
	
	person[emp_num].service[0].name = "full_set";
	person[emp_num].service[1].name = "fill";
	person[emp_num].service[2].name = "manicure";
	person[emp_num].service[3].name = "eyelasher";
	person[emp_num].service[4].name = "pedicure";
	person[emp_num].service[5].name = "off_buff";
	person[emp_num].service[6].name = "repair";
	person[emp_num].service[7].name = "nail_design";
	person[emp_num].service[8].name = "air_brush";
	//person[emp_num].service[9].name = "silk_fiber";
	person[emp_num].service[9].name = "trim";
	person[emp_num].service[10].name = "coat";
	person[emp_num].service[11].name = "polish_change";
	//person[emp_num].service[13].name = "am_man";
	//person[emp_num].service[14].name = "fre_man";
	//person[emp_num].service[15].name = "pink_white";
	person[emp_num].service[12].name = "paraffin";
	//person[emp_num].service[17].name = "clear_gel";
	//person[emp_num].service[18].name = "pink_white_gel";
	person[emp_num].service[13].name = "eu_facial";
	person[emp_num].service[14].name = "eyebrow";
	person[emp_num].service[15].name = "mask";

/*0full_set, 1fill, 2manicure, 3eyelasher(individual75,bun30,strip15), 4pedicure, 5off_buff, 6repair, 7nail_design, 8air_brush, 9trim, 10coat, 11polish_change, 12paraffin, 13eu_facial, 14eyebrow, 15mask;*/

	person[emp_num].multi_service=0;

	for(int i=0;i<EMPLOYEES;i++){
		getline(file,line);
		if(line==name){
			for(int j=0;j<SERVICES;j++){
				getline(file,line);
				person[emp_num].service[j].start_time=0;
				cout << atoi(line.c_str()) << endl;
				person[emp_num].service[j].time=atoi(line.c_str());
			}
		}
		else{
			for(int j=0;j<SERVICES;j++) getline(file,line);
		}
	}

	file.close();

	emp_num++;
};

bool Phyllis::check_input(string input_type, string* input){
	while(true){
		if(input_type=="operation"){
			while(true){
				if(*input=="Exit"||*input=="exit") return false; 
				else if(*input=="Service"||*input=="service") return true;
				else if(*input=="Print"||*input=="print") return true;
				else{ 
					cout << "Error: Wrong input. Please retry." << endl;
					cin >> *input;
				}
			}
		}

		else if(input_type=="clientelle"){
			while(true){
				if(*input=="Exit"||*input=="exit"||*input=="done") return false; 
				else if(*input=="Kim") return true;
				else if(*input=="Fancy") return true;
				else if(*input=="Lynn") return true;
				else if(*input=="Rose") return true;
				else if(*input=="Sandy") return true;
				else if(*input=="Lisa") return true;
				else{
					cout << "Error: Wrong input. Please retry." << endl;
					cin >> *input;
				}
			}
		}

		else if(input_type=="service"){
			while(true){
				if(*input=="Exit"||*input=="exit") return false;
				else if(*input=="full_set"||*input=="fill") return true;
				else if(*input=="manicure"||*input=="eyelasher") return true;
				else if(*input=="off_buff"||*input=="repair") return true;
				else if(*input=="nail_design"||*input=="air_brush") return true;
				else if(*input=="silk_fiber"||*input=="trim") return true;
				else if(*input=="coat"||*input=="polish_change") return true;
				else if(*input=="am_man"||*input=="fre_man") return true;
				else if(*input=="pink_white"||*input=="paraffin") return true;
				else if(*input=="clear_gel"||*input=="pink_white_gel") return true;
				else if(*input=="eu_facial"||*input=="eyebrow") return true;
				else if(*input=="mask"||*input=="done") return true;
				else if(*input=="stop") return true;
				else{
					cout << "Error: Wrong input. Please retry." << endl;
					cin >> *input;
				}
			}
		}

		else if(input_type=="time"){
			while(true){
				if(*input=="Exit"||*input=="exit") return false;
				else if(atoi(input->c_str())) return true;
				else{
					cout << "Error: Wrong input. Please retry." << endl;
					cin >> *input;
				}
			}
		}	

		else{
			cout << "Error: Wrong input. Please retry." << endl;
			cin >> input_type;
		}
	}		
};

void Phyllis::parse_input(string name, string service){
	start_service(&person[person_to_int(name)], service);
};

int Phyllis::service_to_int(string service){
	int num=-1;
	if(service=="full_set") num=0;
	if(service=="fill") num=1;
	if(service=="manicure") num=2;
	if(service=="eyelasher") num=3;
	if(service=="pedicure") num=4;
	if(service=="off_buff") num=5;
	if(service=="repair") num=6;
	if(service=="nail_design") num=7;
	if(service=="air_brush") num=8;
	if(service=="trim") num=9;
	if(service=="coat") num=10;
	if(service=="polish_change") num=11;
	if(service=="paraffin") num=12;
	if(service=="eu_facial") num=13;
	if(service=="eyebrow") num=14;
	if(service=="mask") num=15;

/*0full_set, 1fill, 2manicure, 3eyelasher(individual75,bun30,strip15), 4pedicure, 5off_buff, 6repair, 7nail_design, 8air_brush, 9trim, 10coat, 11polish_change, 12paraffin, 13eu_facial, 14eyebrow, 15mask;*/

	if(service=="done") num=16;
	if(service=="stop") num=17;

	return num;
};

void Phyllis::start_service(struct employee* person, string service){
	switch(service_to_int(service)){
		case 0:
			person->service[0].start_time = time(NULL);
			cout << "start_service.time=" << time(NULL) << endl;
			person->multi_service++;
			break;
		case 1:
			person->service[1].start_time = time(NULL);
			person->multi_service++;
			break;
		case 2:
			person->service[2].start_time = time(NULL);
			person->multi_service++;
			break;
		case 3:
			person->service[3].start_time = time(NULL);
			person->multi_service++;
			break;
		case 4:
			person->service[4].start_time = time(NULL);
			person->multi_service++;
			break;
		case 5:
			person->service[5].start_time = time(NULL);
			person->multi_service++;
			break;
		case 6:
			person->service[6].start_time = time(NULL);
			person->multi_service++;
			break;
		case 7:
			person->service[7].start_time = time(NULL);
			person->multi_service++;
			break;
		case 8:
			person->service[8].start_time = time(NULL);
			person->multi_service++;
			break;
		case 9:
			person->service[9].start_time = time(NULL);
			person->multi_service++;
			break;
		case 10:
			person->service[10].start_time = time(NULL);
			person->multi_service++;
			break;
		case 11:
			person->service[11].start_time = time(NULL);
			person->multi_service++;
			break;
		case 12:
			person->service[12].start_time = time(NULL);
			person->multi_service++;
			break;
		case 13:
			person->service[13].start_time = time(NULL);
			person->multi_service++;
			break;
		case 14:
			person->service[14].start_time = time(NULL);
			person->multi_service++;
			break;
		case 15:
			person->service[15].start_time = time(NULL);
			person->multi_service++;
			break;
		case 16:
			calc_time(person);
			break;
		case 17:
			stop_service(person);
			break;
	}
/*0full_set, 1fill, 2manicure, 3eyelasher(individual75,bun30,strip15), 4pedicure, 5off_buff, 6repair, 7nail_design, 8air_brush, 9trim, 10coat, 11polish_change, 12paraffin, 13eu_facial, 14eyebrow, 15mask;*/
};

int Phyllis::person_to_int(string person){
	int num=-1;

	for(int i=0;i<emp_num;i++){
		if(person==Phyllis::person[i].name){
			num=i;
			break;
		}
	}

	return num;
};

void Phyllis::calc_time(struct employee* person){
	if(person->multi_service>1){
		stop_service(person);
	}
	else{
		for(int i=0;i<SERVICES;i++){
			if(person->service[i].start_time){
				person->service[i].time = ((time(NULL) + person->service[i].start_time)/2);
			}
		}
	stop_service(person);
	}
};

void Phyllis::stop_service(struct employee* person){
	person->multi_service=0;
	for(int i=0;i<SERVICES;i++) person->service[i].start_time=0;
};

void Phyllis::print_all(){
	cout << "print all start_time: ";	
	for(int i=0;i<SERVICES;i++){
		cout << person[0].service[i].start_time << endl;
	}
	///\debug
	for(int i=0;i<emp_num;i++){
		cout << person[i].name << endl;
		for(int j=0;j<SERVICES;j++){
			if(person[i].service[j].start_time){
				cout << '\t' << person[i].service[j].name << ": ";
				cout << '\t' << '\t' << "Time elapsed(";
				if(person[i].service[j].time==0) cout << "TBA): ";
				else{ 
					cout << person[i].service[j].time/60 << ":";
					mod_to_sec(person[i].service[j].time%60);
					cout << "): ";
				}
				cout << (time(NULL)-person[i].service[j].start_time)/60 << ":";
				mod_to_sec((time(NULL)-person[i].service[j].start_time)%60);
				cout << endl;
			}
		}
	}
	cout << endl;
};

void Phyllis::mod_to_sec(int num){
	bool run=true;
	int tens = 0, ones = 0;	
	int m_secs = num;
	int secs = 0;
	
	while(run){
		m_secs = m_secs - 10;
		if(m_secs){
			tens++;
		}
		if(m_secs<10&&m_secs){
			run=false;
		}
		if(m_secs==0){
			run=false;
			tens++;
		}
		if(m_secs<0){ 
			run=false;
			m_secs = m_secs + 10; 
			tens--;
			if(tens<0) tens=0;
		}
	}
	
	run=true;
	
	while(run){
		m_secs = m_secs - 1;
		if(m_secs) ones++;
		if(m_secs<1&&m_secs) run=false;
		if(m_secs==0){
			run=false;
			ones++;
		}
		if(m_secs<0){ 
			run=false;
			m_secs = m_secs + 1; 
			ones--;
			if(ones<0) ones=0;
		}
	}
	while(ones){
		ones--;
		secs++;
	}

	while(tens){
		tens--;
		secs=secs+10;
	}
	
	if(secs<10) cout << "0" << secs;
	else cout << secs;
	
};
