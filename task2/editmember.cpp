#include"Member.h"
void Members::editMember()
{
    int chid;
   // string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    cout << "Enter the id to be changed:";
    cin >> chid;
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
    string qr = "UPDATE Members SET sno = " + to_string(id) + ", name = '" + name1 + "', password = '" + pass + "', education = '" + education + "', mail = '" + mailid + "' ,status='" + status + "' WHERE sno = " + to_string(chid) + "";
    pqxx::result RE = W.exec(qr);
    W.commit();
    cout << "Edited Successfully" << endl;
}