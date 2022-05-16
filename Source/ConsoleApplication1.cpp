#include<string.h>
#include <iostream>
#include <pqxx/pqxx>
#include <exception>
using namespace std;
class book
{
    public:
        int sno;
   string title,author, subject,pd;
    void login();
    void Search_and_Manage();
    void add();
    void edit();
    void remove();
    void display();
}b;
void book::display()
{
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        pqxx::result response = student.exec("SELECT * FROM books");
        for (int i = 0; i < response.size(); i++)
        {
            cout << "Sno: " << response[i][0] << "\t" << " Title: " << response[i][1] << "\t" << " Author " << response[i][2] << "\t" << "Subject" << response[i][3] << "\t" << "Pd" << response[i][4] << "\t" << std::endl;
        }
}
void book::login()
{
    
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work student(connectionObject);
    string username;
    string pwd;
    cout << "\t" << "\t" << "Login"<<endl;
    cout << "Enter Username ";
    cin >> username;
    cout << "Enter Password";
    cin >> pwd;
    string sql = "SELECT password FROM login WHERE username='" +username+"'";
    pqxx::result response = student.exec(sql);
    for (int i = 0; i < response.size(); i++)
    {
            cout << "Login Successful"<<endl;
            return;
        }
    }
void book::Search_and_Manage()
{
    cout <<"Search And Manage Books"<< endl;
   string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
   pqxx::connection connectionObject(connectionString.c_str());
   pqxx::work student(connectionObject);
   int ch;
   cout << "Search by 1.sno" << endl << "2.Title" << endl << "3.Author" <<endl<< "4.Subject"<<endl << "5.pd" << endl;
   cout << "Enter you choice"; 
   cin >> ch;
   if (ch == 1)
   {
       cout << "Enter the sno of the book you want to search";
       cin >> sno;
       string sql = "SELECT *FROM books WHERE sno=";
       sql += to_string(sno);
       
       pqxx::result response = student.exec(sql);
       for (int i = 0; i < response.size(); i++)
       {
           cout << "Sno: " << response[i][0] << "\t" << " Title: " << response[i][1] << "\t" << " Author: " << response[i][2] << "\t" << " Subject: " << response[i][3] << "\t" << "pd" << response[i][4] << std::endl;
       }
   }
   else if (ch == 2)
   {
     
       cout << "Enter the Title";
       cin >> title;
       string sql = "SELECT *FROM books WHERE title='"+title+"'";
       pqxx::result response = student.exec(sql);
       for (int i = 0; i < response.size(); i++)
       {
          cout << "Sno: " << response[i][0] << "\t" << " Title: " << response[i][1] << "\t" << " Author: " << response[i][2] << "\t" << " Subject: " << response[i][3] << "\t" << "pd" << response[i][4] << std::endl;
       }
   }
  else if (ch == 3)
   {
       cout << "Enter the Author";
       cin >> author;
       string sql = "SELECT *FROM books WHERE author='" + author + "'";
       pqxx::result response = student.exec(sql);
       for (int i = 0; i < response.size(); i++)
       {
           std::cout << "Sno: " << response[i][0] << "\t" << " Title: " << response[i][1] << "\t" << " Author: " << response[i][2] << "\t" << " Subject: " << response[i][3] << "\t" << "pd" << response[i][4] << std::endl;
       }
   }
  else if (ch == 4)
   {
       cout << "Enter the Subject";
       cin >> subject;
       string sql = "SELECT *FROM books WHERE subject='" + subject + "'";
       pqxx::result response = student.exec(sql);
       for (int i = 0; i < response.size(); i++)
       {
           std::cout << "Sno: " << response[i][0] << "\t" << " Title: " << response[i][1] << "\t" << " Author: " << response[i][2] << "\t" << " Subject: " << response[i][3] << "\t" << "pd" << response[i][4] << std::endl;
       }
   }
  else
   {
       cout << "Enter the Publication date";
       cin >> pd;
       string sql = "SELECT *FROM books WHERE pd='"+pd+"'";
       pqxx::result response = student.exec(sql);
       for (int i = 0; i < response.size(); i++)
       {
           cout << "Sno: " << response[i][0] << "\t" << " Title: " << response[i][1] << "\t" << " Author: " << response[i][2] << "\t" << " Subject: " << response[i][3] << "\t" << "pd" << response[i][4] << std::endl;
       }
   }
}
void book::add()
{
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work student(connectionObject);
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
    pqxx::result response = student.exec("INSERT INTO books (sno,title,author,subject,pd) VALUES("+to_string(sno)+",'"+title+"','" + author+ "','"+subject+"','"+pd+"')");
    student.commit();
    cout << "Added Successfully";
}
void book::edit()
{
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work student(connectionObject);
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
    pqxx::result response = student.exec(sql);
    student.commit();
}
void book::remove()
{
    sno = 0;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Remove A Book";
    cout << "Enter the sno to be deleted";
    cin >> sno;
    string sql = " DELETE FROM books WHERE sno= ";
    sql +=to_string(sno);
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work student(connectionObject);

    pqxx::result response = student.exec(sql);
    student.commit();
    cout << "Deleted an entry"<<endl;
}
int main()
{
    int n;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    try
    {
        pqxx::connection connectionObject(connectionString.c_str());

        pqxx::work student(connectionObject);
        std::cout << "\t" << "\t" << "----------WELCOME----------" << std::endl;
        b.login();
        cout << "1.Search" << endl << "2.Add" << endl << "3.Edit" << endl << "4.Remove" << "5.Display" << endl<<"6.EXIT"<<endl;        cout << "Enter your choice" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            b.display();
            b.Search_and_Manage();
            break;
        case 2:
            b.add();
            break;
        case 3:
            b.edit();
            break;
        case 4:
            b.remove();
            break;
        case 5:
            b.display();
            break;
        case 6:
            b.login();
            break;
        }
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;

        system("pause");
    }
