#include"login.h"
void Lib::book_status()
{
    int ch1;
    cout << "1.Reserve" << "\t" << "2.Renew" << "\t" << "3.Return" << endl;
    cout << "Enter your choice" << endl;
    cin >> ch1;
    //string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    pqxx::result RE = W.exec("SELECT *FROM books WHERE bookstatus='Available'");
    W.commit();
    for (int i = 0; i < RE.size(); i++)
    {
        cout << "Sno:" << RE[i][0] << "\t" << "Title:" << RE[i][1] << "\t" << "Author:" << RE[i][2] << "\t" << "Subject:" << RE[i][3] << "\t" << "Pd:" << RE[i][4] << "\t" << "Book_Status:" << RE[i][5] << endl;
    }
    if (ch1 == 1)
    {
        cout << "Enter the id of the book to be reserved" << endl;
        cin >> sno;
        string quer = "UPDATE books SET bookstatus='Reserved' WHERE sno = " + to_string(sno) + "";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(quer);
        W.commit();
        cout << "Reserved" << endl;
    }
    else if (ch1 == 2)
    {
        //string date;
        cout << "Enter the id of the book" << endl;
        cin >> sno;
        //cin >> date;
        string quer = "UPDATE books SET tilldate=tilldate+interval '10day' WHERE sno=" + to_string(sno) + "";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(quer);
        W.commit();
        cout << "Renewed" << endl;
    }
    else
    {
        cout << "Enter the id of the book :" << endl;
        cin >> sno;
        string sql = "UPDATE books SET bookstatus='Available' ,fromdate=NULL,tilldate=NULL WHERE sno=" + to_string(sno) + "";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(sql);
        W.commit();
        cout << "Returned Successfully" << endl;
    }

}