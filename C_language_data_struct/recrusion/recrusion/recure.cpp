#include<iostream>
#include<vector>
using namespace std;



int find_vector(vector<int> data, int now)
{
	vector<int>::iterator index = data.begin();
	//int s = data.size();
	if (now == (data.size() - 1))
		return 1;
	int init_len = 1;
	for (int i = now +1; i < data.size(); i++)
	{
		int len;
		if (*(index +now) < *(index + i ))
		{
			len = find_vector(data, i) + 1;
			init_len = (len > init_len ? len : init_len);
		}
		
	}
	return init_len;
	
}


int main()
{
	//int a[] = {3, 4, 2, 3, 1, 6};
	//cout << find(a, 0, 6) << endl;

	vector<int> data;
	data.push_back(3);
	data.push_back(4);
	//data.push_back(5);
	//data.push_back(3);
	//data.push_back(1);
	data.push_back(6);
	//data.push_back(8);
	data.push_back(7);
	cout << find_vector(data, 0) << endl;

	return 0;
}