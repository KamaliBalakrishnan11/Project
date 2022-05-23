#include"login.h"
void Lib::login()
{
    string username, pwd, pwd1;
   // string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    cout << "------------------" << "WELCOME" << "--------------------" << endl;
    cout << "\t\t\t\t\t\t\t" << "Login" << endl;
    cout << "Enter Username:" << endl;
    cin >> username;
    cout << "Enter Password:" << endl;
    cin >> pwd1;
    string sql = "SELECT password FROM members WHERE name='" + username + "'";
    pqxx::work W(connectionObject);
    pqxx::result RE = W.exec(sql);
    for (pqxx::result::const_iterator c = RE.begin(); c != RE.end(); ++c)
    {
        pwd = c[0].as<string>();
    }
    W.commit();
    if (pwd == pwd1)
    {
        cout << "\t\t\t\t\tLogin Successful" << endl;
        return;
    }
    else
    {
        cout << "Invalid Login";
        exit(0);   
    }
    system("Pause");
}