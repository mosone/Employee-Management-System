#pragma once
#include <string>


using namespace std;


class Instructions
{
private:


public:
	string Ename;
	string Esal;
	float Esalary;
	string Ehiredate;
	string ESTnum{};
	string Eactive;

	Instructions();

	void run();

	char Do_list();

	char press_1();
	char press_2();
	char press_q();
	
	
	
	


};

