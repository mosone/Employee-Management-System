#include "Instructions.h"
#include "Employee.h"
#include "EmpText.h"
#include <iostream>
#include <string>
#include <iomanip>






Instructions::Instructions()
{

}

void Instructions::run()
{
	vector <Employee> emps;
	char letter{};
	bool pass{ false };
	Employee empl;
	EmpText Ftext;

	do
	{
		letter = Do_list();
		if (letter == '1')
		{
			press_1();
			Employee empl(Ename, Esalary, Ehiredate, ESTnum, Eactive);
			emps.push_back(empl);

			static int count1{ 1 };

			for (int i = 0; i < emps.size(); i++)
			{

				if (i == count1)
				{
					emps[i].set_number(count1);
					count1++;

				}
				else
				{
					emps[i].set_number(count1);
					count1++;
				}

			}
			count1 = 1;
			
				
		}
		else if (letter == '2')
		{
			if (emps.empty())
			{
				cout << "\n There are no employees on the list" << endl;
			}
			else
			{
				press_2();

				for (int i = 0; i < emps.size(); i++)
				{
					cout << "*" << setw(7) << emps[i].get_number() << setw(17) << emps[i].get_name() << setw(7) << emps[i].get_salary()
						<< setw(15) << emps[i].get_hiredate() << setw(13) << emps[i].get_salarytype() << setw(17) << emps[i].get_active() << setw(13) << "*" << endl;
					cout << "*" << setfill(' ') << setw(89) << "*" << endl;
				}
				cout << "*" << setw(89) << setfill('*') << "*" << endl;
			}
		}
		else if (letter == '3')
		{
			if (emps.empty())
			{
				cout << "\n There are no employees on the list" << endl;
			}
			else
			{
				Ftext.open_file();

				for (int i = 0; i < emps.size(); i++)
				{
					Ftext.out_file << setw(10) << emps[i].get_number() << setw(25) << emps[i].get_name() << setw(13) << emps[i].get_salary()
						<< setw(25) << emps[i].get_hiredate() << setw(25) << emps[i].get_salarytype() << setw(25) << emps[i].get_active() << endl;
					Ftext.out_file << setw(95) << "*********************" << endl;
				}

			}
			Ftext.close_file();

		}
		else if (letter == '4')
		{

			string n{};
			cout << "Enter the name of the employee you want to delete: ";
			getline(cin, n);
			int j{};
			int l{ 1 };

			for (int j = 0; j < emps.size(); j++)
			{
				if (n == emps[j].get_name())
				{
					emps.erase(emps.begin() + j);
					cout << endl;
					cout << n << " was deleted from the list" << endl;
				}
				else if (n != emps[j].get_name())
				{
					if (n == "" || isdigit(n[j]))
					{
						j--;
						cerr << "Invalid name" << endl;
						cout << " Please enter the name of the employee you want to delete:  ";
						getline(cin, n);
					}
					else if (l++ == emps.size())
					{
						cerr << "\n The name is not on the list!" << endl;
					}
				}
			}
			for (int i = 0; i < emps.size(); i++)
			{
				static int count2{ 1 };

				for (int i = 0; i < emps.size(); i++)
				{

					if (i == count2)
					{
						emps[i].set_number(count2);
						count2++;

					}
					else
					{
						emps[i].set_number(count2);
						count2++;
					}

				}
				count2 = 1;
			}
			
		}
		else if (letter == 'Q')
		{
			press_q();
		}
		else
		{
			cerr << "invalid cherecter\n";
		}

	}while (letter != 'Q');
			
}


char Instructions::Do_list()
{
	char ot{};

	cout << "\nHello, what would you like to do?" << endl;
	cout << "---------------------------------" << endl;
	cout << "Press 1 to enter employee name,salary,hire date,salary type and employee activation." << endl;
	cout << "Press 2 to display all Employees." << endl;
	cout << "Press 3 to open a text file and display all Employees." << endl;
	cout << "Press 4 to delete a Employee." << endl;
	cout << "Press q to Exit!" << endl;
	cout << "---------------------------------" << endl;
	cout << " Press:";
	cin >> ot;
	ot = toupper(ot);
	cin.ignore();

	return ot;
}

char Instructions::press_1()
{
	cout << " Please enter employee name: ";
	getline(cin, Ename);
	int i = 0;
	for (i = 0; i <= Ename.size(); i++)
	{
		if (Ename == "" || isdigit(Ename[i]))
		{
			i--;
			cerr << "Invalid name" << endl;
			cout << " Please enter employee name: ";
			getline(cin, Ename);
			

		}
	}
	
	cout << " Please enter employee salary: ";
	getline(cin, Esal);

	for (i = 0; i <= Esal.size(); i++)
	{
		if (Esal == "" || isalpha(Esal[i]))
		{
			i--;
			cerr << "Invalid salary" << endl;
			cout << " Please enter employee salary: ";
			getline(cin, Esal);
			
		}	
	}
	if (Esal != "")
	{
		Esalary = stof(Esal);
	}
	
	
	cout << " Please enter employee hire date day/month/year: ";
	getline(cin, Ehiredate);

	for (i = 0; i <= Ehiredate.size(); i++)
	{
		if (Ehiredate == "" || isalpha(Ehiredate[i]))
		{
			i--;
			cerr << "Invalid date" << endl;
			cout << " Please enter employee hire date day/month/year: ";
			getline(cin, Ehiredate);

		}
	}

	cout << " Please enter employee salary type: global or hourly: ";
	getline(cin, ESTnum);

	string s1 = "global";
	string s2 = "hourly";
	bool option{1};
	string temp;


	do 
	{
		for (i = 0; i <= ESTnum.size(); i++)
		{
			if (ESTnum == "")
			{
				i--;
				cerr << "Invalid salary type" << endl;
				cout << " Please enter employee salary type: global or hourly: ";
				getline(cin, ESTnum);
			}
		}

		for (i = 0; i < ESTnum.size(); i++)
		{
			temp += tolower(ESTnum[i]);
		}
		ESTnum = temp;

		if ((temp.compare (s1)) == 0)
		{
			while (option = 0);
			
		}
		else if ((temp.compare(s2)) == 0)
		{
			while (option = 0);
			
		}
		else
		{
			cerr << "Invalid salary type" << endl;
			cout << " Please enter employee salary type: global or hourly: ";
			getline(cin, ESTnum);
			temp.clear();	
		}
	} while (option);


	cout << " Please enter activation type, press 1 for active or press 0 for inactive: ";
	getline(cin, Eactive);


	option = 1;
	do
	{
		if (Eactive == "0" || Eactive == "1" || Eactive != "")
		{
			while (option = 0);
		}
		else
		{
			cerr << "Invalid activation type" << endl;
			cout << " Please enter activation type, press 1 for active or press 0 for inactive: ";
			getline(cin, Eactive);
		}

	}while (option);


	cout << endl;

	return 0;
}

char Instructions::press_2()
{
	cout << endl;
	cout << setw(55) << setfill('*') << " Display employees " << setw(35) << setfill('*') << "*" << endl;
	cout << "*" << setfill(' ') << setw(89) << "*" << endl;
	cout << "*" << setw(10) << "Number" << setw(10) << "Name" << setw(11) << "Salary" << setw(15)
		<< "Hire Date" << setw(17) << "Salary Type" << setw(17) << "Activation" << setw(9) << "*" << endl;
	cout << "*" << setfill(' ') << setw(89) << "*" << endl;

	return 0;
}

char Instructions::press_q()
{
	cout << "\n goodbye :)" << endl;
	exit;
	return 0;
}




