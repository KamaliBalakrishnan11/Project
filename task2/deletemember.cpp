#include"Member.h"
void Members::delete_Member()
{
    int id1 = 0;
    //string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Remove A Member";
    cout << "Enter the id to be deleted";
    cin >> id1;
    string qr = " DELETE FROM Members WHERE sno= ";
    qr += to_string(id1);
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work W(connectionObject);

    pqxx::result RE = W.exec(qr);
    W.commit();
    cout << "Deleted a Memeber" << endl;
}