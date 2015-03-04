#include <string>
#include <cstdio>
#include <time.h>
#define SERVICES 16
#define EMPLOYEES 6

using namespace std;

struct employee{
	string name;
	int multi_service;
	struct service{
		string name;
		int time;
		time_t start_time;
	} service[SERVICES];
/*0full_set, 1fill, 2manicure, 3eyelasher(individual75,bun30,strip15), 4pedicure, 5off_buff, 6repair, 7nail_design, 8air_brush, 9trim, 10coat, 11polish_change, 12paraffin, 13eu_facial, 14eyebrow, 15mask;*/
};



class Phyllis{
	public:
		Phyllis();
		void parse_input(string name, string service);	
		void print_all();
		bool check_input(string input_type, string* input);
	private:
		struct employee person[10];
		int emp_num;

		void init_employee(string name);
		void calc_time(struct employee* person);
		void start_service(struct employee* person, string service);
		void stop_service(struct employee* person);
		int service_to_int(string service);
		int person_to_int(string person);		
		void mod_to_sec(int num);
};
