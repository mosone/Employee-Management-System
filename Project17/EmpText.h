#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class EmpText
{
public:
	ofstream out_file{ "Update.txt" , ios::app };
	void open_file();
	void close_file();
	void clear(string f);

};

