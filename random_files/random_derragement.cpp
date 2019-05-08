#include <random>	// random numbers
#include <iostream>	// input and output
#include <fstream>	// files
using namespace std;

int main(){

	cout<<"This program creates a file with a random derrangement\n";

	random_device rd;
	mt19937 mt(rd());

	cout<<"\nDerragement size [1 - N]: ";
	
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

	ofstream File(file_name);

	File << n << ' ';

	vector<size_t> perm(n);

    for(size_t i = 1; i <= n; i++)
        perm[i - 1] = i;

    uniform_int_distribution<int> rand_pos(0, (int)n - 1);

    for(size_t i = 0; i < n; i++)
    {
        size_t new_pos = perm[i];
        
        while(new_pos == perm[i] or perm[new_pos] == i + 1)
            new_pos = rand_pos(mt);

        swap(perm[i], perm[new_pos]);
    }

    for(size_t i = 0; i < n; i++)
        File << perm[i] << ' ';

	File.close();

	cout<<"\nFile '"<<file_name<<"' successfully created\n";

	return 0;
}
