#include"login.h"
void Lib::removeBook()
{
    int sn1 = 0;
   // string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Remove A Book" << endl;
    cout << "Enter the sno to be deleted" << endl;
    cin >> sn1;
    string sql = " DELETE FROM books WHERE sno= ";
    sql += to_string(sn1);
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work W(connectionObject);

    pqxx::result RE = W.exec(sql);
    W.commit();
    cout << "Deleted an entry" << endl;
}