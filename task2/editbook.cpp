#include"login.h"
void Lib::editBook()
{
    //string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    cout << "EDIT BOOK";
    cout << "Enter sno";
    cin >> sno;
    cout << "Enter title";
    cin >> title;
    cout << "Enter author";
    cin >> author;
    cout << "Enter subject";
    cin >> subject;
    cout << "Enter pd";
    cin >> pd;
    string sql = "UPDATE books SET sno=" + to_string(sno) + ", title='" + title + "', author='" + author + "', subject='" + subject + "',pd='" + pd + "' WHERE sno=" + to_string(sno) + "";
    pqxx::result RE = W.exec(sql);
    W.commit();
    cout << "Updated Successfully" << endl;
}