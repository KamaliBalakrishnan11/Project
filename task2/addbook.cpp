#include"login.h"
void Lib::addBook()
{
   // string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    cout << "ADD BOOK" << endl;
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
    pqxx::result response = W.exec("INSERT INTO books (sno,title,author,subject,pd) VALUES(" + to_string(sno) + ",'" + title + "','" + author + "','" + subject + "','" + pd + "')");
    W.commit();
    cout << "Added Book Successfully" << endl;
}