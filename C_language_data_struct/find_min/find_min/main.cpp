#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

vector<int> bool_value;

int main()
{
	string str;
	while (getline(cin, str))
	{
		bool_value.clear();
		int data;
		cin >> data;
		stringstream ss(str);
		int temp;
		string te;

		while (ss >> temp)
		{
			if (temp < data)
			{
				bool_value.push_back(1);
			}
			else
			{
				bool_value.push_back(0);
			}
		}

		if (1)
		{
			for (int i = 0; i < bool_value.size(); i++)
				cout << bool_value[i]<< i<<endl;
		}

	}
	

	return 0;
}