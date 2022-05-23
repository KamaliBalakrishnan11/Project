#include"login.h"

void Lib::Search_and_Manage()
{
   // Lib displayList();
  //  string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    cout << "Enter the ID";
    cin >> sno;
    string sql = "SELECT *FROM books WHERE sno=";
    sql += to_string(sno);
    pqxx::result RE = W.exec(sql);
    for (int i = 0; i < RE.size(); i++)
    {
        cout << "Sno: " << RE[i][0] << "\t" << " Title: " << RE[i][1] << "\t" << " Author: " << RE[i][2] << "\t" << " Subject: " << RE[i][3] << "\t" << "pd" << RE[i][4] << std::endl;
    }
}