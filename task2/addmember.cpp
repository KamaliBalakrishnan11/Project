#include"Member.h"
void Members::add_Member()
{
	//string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
	pqxx::connection connectionObject(connectionString.c_str());
	pqxx::work W(connectionObject);
	cout << "Enter sno";
	cin >> id;
	cout << "Enter name";
	cin >> name1;
	cout << "Enter password";
	cin >> pass;
	cout << "Enter education";
	cin >> education;
	cout << "Enter Mail";
	cin >> mailid;
	cout << "Enter status";
	cin >> status;
	pqxx::result RE = W.exec("INSERT INTO Members(sno,name,password,education,mail,status) VALUES(" + to_string(id) + ",'" + name1 + "', '" + pass + "','" + education + "','" + mailid + "','" + status + "')");
	W.commit();
	cout << "Added Member Successfully" << endl;
}