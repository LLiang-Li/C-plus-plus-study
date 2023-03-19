#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int def_sort(string th, string oth)
{	
	//cout << th->c_str;
		if (th>oth)
			return 0;
		else
			return 1;
}

int main() {
	string str_input;
	vector<string> str;
	gets(str_input);
	//while (cin >> str_input)
	{
		//cout << str_input <<endl;
		//if (str_input =="end")
		//	break;
		cin >> str_input;
		stringstream ss(str_input);
		int  data;
		while (ss >> data)
		{
			ss.get();
			cout << data << endl;
		}
			

		//str.push_back(str_input);
		
	}

	

	/*str.push_back("bbc");
	str.push_back("bcd");
	str.push_back("cde");*/
	/*
	for (vector<string>::iterator i = str.begin(); i < str.end(); i++)
		cout << i->c_str() << endl;
	//cout << str[0];
	sort(str.begin(), str.end(), def_sort);

	for (vector<string>::iterator i = str.begin(); i < str.end(); i++)
		cout << i->c_str() << endl;
	*/
	return 0;
}