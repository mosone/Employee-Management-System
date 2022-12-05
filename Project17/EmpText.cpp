#include "EmpText.h"
#include <string>


void EmpText::open_file()
{
	ofstream out_file{ "Update.txt" , ios::app };

	if (out_file)
	{
		cout << "File is open successfully" << endl;
	}
	else
	{
		cerr << "File could not be created";
			exit(1);
	}
	clear("Update.txt");

	out_file << setw(60) << setfill('*') << " Display employees " << setw(40) << setfill('*') << "*" << endl << endl;
	out_file << setfill(' ') << setw(10) << "Number" << setw(15) << "Name" << setw(20) << "Salary" << setw(25)
		<< "Hire Date" << setw(22) << "Salary Type" << setw(22) << "Activation" << endl << endl;

}

void EmpText::close_file()
{
	ofstream out_file{ "Update.txt" , ios::app };
	if (out_file)
	{
		out_file.close();
	}
	

}

void EmpText::clear(string f)
{
	ofstream out_file(f);
	out_file << " ";
}
