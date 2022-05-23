#include"Member.h"
void Members::Search_and_Manage_Members()
{
    cout << "-----------Search And Manage Members----------" << endl;
   // string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Enter the name:";
    cin >> name1;
    string qr = "SELECT *FROM Members WHERE name='" + name1 + "'";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    pqxx::result RE = W.exec(qr);
    for (int i = 0; i < RE.size(); i++)
    {
        std::cout << "Sno: " << RE[i][0] << "\t" << " Name: " << RE[i][1] << "\t" << "Education: " << RE[i][3] << "\t" << " Mail_Id: " << RE[i][4] << "Status" << RE[i][5] << std::endl;
    }
}