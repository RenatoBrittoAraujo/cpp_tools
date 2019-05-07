#include <random>	// random numbers
#include <iostream>	// input and output
#include <fstream>	// files
using namespace std;

int main(){

	cout<<"This program creates a file with random elements\n";

	random_device rd;
	mt19937 mt(rd());

	cout<<"\nNumber of elements: ";
	
	size_t n;
	cin>>n;

	cout<<"\nFile name: ";
	string file_name;
	cin.ignore();
	getline(cin, file_name);

	ifstream test(file_name);

	if(test.good())
	{
		cout<<"\nFile already exists\n";
		return 0;
	}

	test.close();

	cout<<"\nNow select the type of element:\n";
	cout<<"1. String\n";
	cout<<"2. Floting Point\n";
	cout<<"3. Integer\n";
	cout<<"4. Character\n\n";
	cout<<"Selection: ";

	size_t type;

	cin>>type;

	if(type < 1 or type > 4)
	{
		cout<<"\nWrong type selection\n";
		return 0;
	}

	ofstream File(file_name);

	File << n << ' ';

	if(type == 3)
	{
		cout<<"\nLower bound for random numbers: ";
		int lower;
		int upper;
		cin>>lower;
		cout<<"Upper bound for random numbers: ";
		cin>>upper;

		uniform_int_distribution<int> int_dist(lower, upper);
	
		for(size_t i = 0; i < n; i++)
			File << int_dist(mt) << ' ';
	}

	if(type == 2)
	{
		double lower;
		double upper;
		cout<<"\nLower bound for floating point (double precision): ";
		cin>>lower;
		cout<<"Upper bound for floating point (double precision): ";
		cin>>upper;

		uniform_real_distribution<double> double_dist(lower, upper);

		for(size_t i = 0; i < n; i++)
			File << double_dist(mt) << ' ';
	}

	if(type == 1)
	{
		size_t string_upper_size;
		cout<<"String upper lenght: ";
		cin>>string_upper_size;

		uniform_int_distribution<int> char_number('a', 'z');
		uniform_int_distribution<int> string_lenght(1, (int)string_upper_size);

		for(size_t i = 0; i < n; i++)
		{
			string to_insert;
			
			for(size_t j = 0; j < (size_t)string_lenght(mt); j++)
				to_insert += char(char_number(mt));

			File << to_insert << ' ';
		}
	}

	if(type == 4)
	{
		uniform_int_distribution<int> char_number('a', 'z');

		for(size_t i = 0; i < n;i++)
			File << char(char_number(mt)) << ' ';
	}

	File.close();

	cout<<"\nFile '"<<file_name<<"' successfully created\n";

	return 0;
}
