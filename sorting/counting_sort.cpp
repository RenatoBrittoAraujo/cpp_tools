#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(vector<size_t> & origin, size_t k)
{
    vector<size_t> temp(k + 1);
    vector<size_t> target(origin.size());

    for(size_t i = 0; i <= k; i++)
        temp[i] = 0;

    for(size_t j = 0; j < origin.size(); j++)
        temp[origin[j]]++;

    for(size_t i = 1; i <= k; i++)
        temp[i] += temp[i - 1];

    for(size_t j = origin.size() - 1; ; j--)
    {
        target[temp[origin[j]] - 1] = origin[j];
        temp[origin[j]]--;

        if(j == 0)
            break;
    }

    for(size_t i = 0; i < origin.size(); i++)
        origin[i] = target[i];
}

int main(int argc, char ** argv){

	bool print_input = true;

	if(argc > 1 and argv[1][1] == 'v')
		print_input = false;

	size_t n;

	if(print_input)
		cout<<"Array size: ";

	cin>>n;

	vector<size_t> arr(n);

	if(print_input)
		cout<<"Array elements: ";

    size_t max_input = 0;

	for(size_t i = 0; i < n; i++)
	{
        cin>>arr[i];
        max_input = max(arr[i], max_input);
    }

    counting_sort(arr, max_input);

    if(print_input)
        cout<<"Sorted array: ";
    
    for(size_t  i = 0; i < n; i++)
        cout<<arr[i]<<' ';
    
    cout<<endl;

	return 0;
}
