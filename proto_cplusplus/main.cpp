#include "Account.pb.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cerr;

int main(int, char**) {
    // IM::Account account1;
	
	// account1.set_id(123);
	// account1.set_name("windsun");
	// account1.set_password("123456");

	// string serializeToStr;
	// account1.SerializeToString(&serializeToStr);
	// cout << serializeToStr << endl;


	// IM::Account account2;
	// if(!account2.ParseFromString(serializeToStr))
	// {
	// 	cerr << "failed to parse student." << endl;
	// 	return -1;
	// }
	// cout << "fan" << endl;
	// cout << account2.id() << endl;
	// cout << account2.name() << endl;
	// cout << account2.password() << endl;
	
	// google::protobuf::ShutdownProtobufLibrary();
	std::cout << '\a';
	return 0;
}