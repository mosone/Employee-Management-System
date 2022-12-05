#pragma once
#include "Instructions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Employee
{
private:

	int Enumber{ 1 };
	string name;
	float salary{};
	string hiredate;
	string salary_type{};
	string active;
	

public:

	Employee();
	Employee(string name_val, float salary_val, string date_val,string slry_val, string act_val);

	

	Employee operator + (const int& rhs);
	int set_number(int k);
	int get_number() { return Enumber; }
	string get_name() { return name; }
	float get_salary() { return salary; }
	string get_hiredate() { return hiredate; }
	string get_salarytype() { return salary_type; }
	string get_active() { return active; }
	
	
	


	


};

