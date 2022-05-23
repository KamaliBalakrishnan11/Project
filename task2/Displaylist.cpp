#include"login.h"
void Lib::displayList()
{
  //  string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    pqxx::result RE = W.exec("SELECT *FROM books");
    VariadicTable<int, string, string, string, string>vt({ "sno","Title","Author","Subject","Pd" });
    for (int i = 0; i < RE.size(); i++)
    {
        vt.addRow(RE[i][0].as<int>(), RE[i][1].as<string>(), RE[i][2].as<string>(), RE[i][3].as<string>(), RE[i][4].as<string>());
    }
    vt.print(cout);
}