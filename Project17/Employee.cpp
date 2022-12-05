#include "Employee.h"


Employee::Employee()
{

}

Employee::Employee(string name_val, float salary_val, string date_val, string slry_val, string act_val)
{

	name = name_val;
	salary = salary_val;
	hiredate = date_val;
	salary_type = slry_val;
	active = act_val;
}

int Employee::set_number(int k)
{
	Enumber = k;

	return Enumber;
}








