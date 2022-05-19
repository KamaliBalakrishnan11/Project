
#include "Header.h"
void Lib::login()
{
    string username, pwd, pwd1;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
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
}
 void Members::Search_and_Manage_Members()
{
    cout <<"-----------Search And Manage Members----------" << endl;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Enter the name:";
        cin >> name1;
        string qr = "SELECT *FROM Members WHERE name='" +name1+"'";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(qr);
        for (int i = 0; i < RE.size(); i++)
        {
            std::cout << "Sno: " << RE[i][0] << "\t" << " Name: " << RE[i][1] << "\t" << "Education: " << RE[i][3] << "\t" << " Mail_Id: " << RE[i][4] <<"Status"<<RE[i][5]<< std::endl;
        }

}
 void Members::add_Member()
{
 string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
 pqxx::connection connectionObject(connectionString.c_str());
 pqxx::work W(connectionObject);
 cout << "Enter sno";
 cin >> id;
 cout << "Enter name";
 cin >> name1;
 cout << "Enter password";
 cin >> pass;
 cout << "Enter education";
 cin >> education;
 cout << "Enter Mail";
 cin >> mailid;
 cout << "Enter status";
 cin >> status;
 pqxx::result RE = W.exec("INSERT INTO Members(sno,name,password,education,mail,status) VALUES(" + to_string(id) + ",'" + name1 + "', '" + pass + "','" + education + "','" + mailid + "','" + status + "')");
 W.commit();
 cout << "Added Member Successfully"<<endl;
}
void Members::editMember()
{
    int chid;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    cout << "Enter the id to be changed:";
        cin >> chid;
    cout << "Enter sno";
    cin >> id;
    cout << "Enter name";
    cin >> name1;
    cout << "Enter password";
    cin >> pass;
    cout << "Enter education";
    cin >> education;
    cout << "Enter Mail";
    cin >> mailid;
    cout << "Enter status";
    cin >> status;
    string qr="UPDATE Members SET sno = " + to_string(id) + ", name = '" + name1+ "', password = '" + pass+ "', education = '" +education+ "', mail = '" + mailid + "' ,status='"+status+"' WHERE sno = " + to_string(chid) + "";
    pqxx::result RE = W.exec(qr);
    W.commit();
    cout << "Edited Successfully"<<endl;
}
 void Members::delete_Member()
{
    int id1 = 0;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Remove A Member";
    cout << "Enter the id to be deleted";
    cin >> id1;
    string qr = " DELETE FROM Members WHERE sno= ";
    qr+= to_string(id1);
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work W(connectionObject);

    pqxx::result RE = W.exec(qr);
    W.commit();
    cout << "Deleted a Memeber" << endl;
}
 void Lib::Search_and_Manage()
{
    l.displayList();
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
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
 void Lib::addBook()
{
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
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
    cout << "Added Book Successfully"<<endl;
}
 void Lib::editBook()
{
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
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
    cout << "Updated Successfully"<<endl;
}
 void Lib::removeBook()
{
    sno = 0;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    cout << "Remove A Book"<<endl;
    cout << "Enter the sno to be deleted"<<endl;
    cin >> sno;
    string sql = " DELETE FROM books WHERE sno= ";
    sql += to_string(sno);
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work W(connectionObject);

    pqxx::result RE = W.exec(sql);
    W.commit();
    cout << "Deleted an entry" << endl;
}
inline void Lib::book_status()
{
    int ch1;
    cout << "1.Reserve" << "\t" << "2.Renew" << "\t" << "3.Return" << endl;
    cout << "Enter your choice" << endl;
    cin >> ch1;
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    pqxx::result RE = W.exec("SELECT *FROM books WHERE bookstatus='Available'");
    W.commit();
    for (int i = 0; i < RE.size(); i++)
    {
        cout << "Sno:" << RE[i][0] << "\t" << "Title:" << RE[i][1] << "\t" << "Author:" << RE[i][2] << "\t" << "Subject:" << RE[i][3] << "\t" << "Pd:" << RE[i][4] <<"\t"<<"Book_Status:"<<RE[i][5]<<endl;
    }
    if (ch1 == 1)
    {
        cout << "Enter the id of the book to be reserved"<<endl;
        cin >> sno;
       string quer = "UPDATE books SET bookstatus='Reserved' WHERE sno = "+to_string(sno)+"";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(quer);
        W.commit();
        cout << "Reserved"<< endl;
    }
    else if (ch1 == 2)
    {
        //string date;
        cout << "Enter the id of the book"<<endl;
        cin >> sno;
        //cin >> date;
        string quer = "UPDATE books SET tilldate=tilldate+interval '10day' WHERE sno=" + to_string(sno) + "";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(quer);
        W.commit();
        cout << "Renewed"<<endl;
    }
    else
    {
        cout << "Enter the id of the book :" << endl;
        cin >> sno;
        string sql="UPDATE books SET bookstatus='Available' ,fromdate=NULL,tilldate=NULL WHERE sno="+to_string(sno)+"";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work W(connectionObject);
        pqxx::result RE = W.exec(sql);
        W.commit();
        cout << "Returned Successfully"<<endl;
    }

}
 void Lib::displayList()
{
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work W(connectionObject);
    pqxx::result RE = W.exec("SELECT *FROM books");
    for (int i = 0; i < RE.size(); i++)
    {
        cout << "Sno:" << RE[i][0] << "\t" << "Title:" << RE[i][1] << "\t" << "Author:" << RE[i][2] << "\t" << "Subject:" << RE[i][3] << "\t" << "Pd:" << RE[i][4] << endl;
    }
}
 int main()
 {
     try
     {
         int n, ch;
         std::string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
         pqxx::connection connectionObject(connectionString.c_str());

         pqxx::work student(connectionObject);
         std::cout << "----------LIBRARY----------" << std::endl << std::endl;
         cout << "1.Librarian" << "\t" << "2.Members" << "\t" << "3.SignUp" << endl;  
         cin >> n;
         if (n == 3)
         {
             m.add_Member();
           //  l.login();
         }
        // cout << "1.Librarian" << "\t" << "2.Members" << "\t" << "3.SignUp" << endl;
        
         if (n == 1)
         {
             int n1;
             l.login();
             cout << "1.Search_Manage_Member" << endl << "2.My_accounts" << endl << "3.Search_Manage_Books" << endl;
             cout << "Enter your choice" << endl;
             cin >> n1;
             switch (n1)
             {
             case 1:
                 cout << "1.Search" << endl << "2.Add" << endl << "3.Edit" << endl << "4.Delete" << endl;
                 cin >> ch;
                 if (ch == 1)
                 {
                     m.Search_and_Manage_Members();
                     break;
                 }
                 else if (ch == 2)
                     m.add_Member();
                 else if (ch == 3)
                     m.editMember();
                 else if (ch == 4)
                     m.delete_Member();
                 break;
             case 2:
                 m.editMember();
                 break;
             case 3:
                 cout << "1.Search" << endl << "2.Add" << endl << "3.Edit" << endl << "4.Remove" << endl << "5.Book_Status" << endl;
                 cout << "Enter your choice" << endl;
                 cin >> ch;
                 if (ch == 1)
                     l.Search_and_Manage();
                 else if (ch == 2)
                     l.addBook();
                 else if (ch == 3)
                     l.editBook();
                 else if (ch == 4)
                     l.removeBook();
                 else if (ch == 5)
                     l.book_status();
                 break;
             }
         }
         else
         {
             l.login();
             cout << "1.My_accounts" << endl << "2.Search_Manage_Books" << endl;
             cout << "Enter your choice" << endl;
             cin >> ch;
             switch (ch)
             {
             case 1:
                 m.editMember();
                 break;
             case 2:
                 cout << "1.Search" << "\t" << "2.Book_Status" << endl;
                 cout << "Enter your choice" << endl;
                 cin >> ch;
                 if (ch == 1)
                     l.Search_and_Manage();
                 else
                     l.book_status();
                 break;
             }
         }

     }
     catch (const std::exception& e)
     {
         std::cout << e.what() << std::endl;
     }
     system("Pause");
 }