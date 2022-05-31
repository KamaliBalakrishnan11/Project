#include"librarym.h"
#include"Member.h"
#include"dbhandler.h"
#include"Users.h"
void Lib::login()
{
   string username, pwd1,pwd;
    cout << "------------------" << "WELCOME" << "--------------------" << endl;
    cout << "\t\t\t\t\t\t\t" << "Login" << endl;
    cout << "Enter Username:" << endl;
    cin >> username;
    cout << "Enter Password:" << endl;
    cin >> pwd1;
    dbhandler d;
    pwd =d.selectquery(username,1);
    if (pwd == pwd1)
    {
       cout << "\t\t\t\t\tLogin Successful" << endl;
    }
    else
    {
        cout << "Invalid Login";
        exit(0);   
    }
    system("Pause");
}
void Lib::Search_and_Manage()
{
    dbhandler d;
    cout << "-----------Search And Manage Books----------" << endl;
    cout << "Enter the name of the book to be searched" << endl;
    cin >> title;
    d.selectquery(title, 3);
}
void Lib::addBook()
{
    dbhandler d;
    cout << "ADD BOOK" << endl;
    cout << "Enter sno";
    cin >> sno;
    cout << "Enter title";
    cin >> title;
    cout << "Enter author";
  cin>>author;
    cout << "Enter subject";
    cin >> subject;
    cout << "Enter pd";
    cin >> pd;
    cout << "Enter status";
    cin >> status;
   d.insertquery(sno, title, author, subject, pd,status);
    cout << "Added Book Successfully" << endl;
}
void Lib::editBook()
{
    string n;
    dbhandler d1;
    cout<<"EDIT BOOK"<<endl;
    cout << "Enter the book name to be edited" << endl;
    cin >> n;
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
    cout << "Enter status";
    cin >> status;
    d1.updatequery(sno,title,author, subject, pd, status,n);
    cout << "Edited Successfully" << endl;
}
void Lib::removeBook()
{
    dbhandler d;
    int sn1 = 0;
    cout << "Remove A Book" << endl;
    cout << "Enter the sno to be deleted" << endl;
    cin >> sn1;
    d.deletequery(sn1, 1);
}
void Lib::book_status()
{
    int ch1;
    cout << "1.Reserve" << "\t" << "2.Borrow" << "\t" << "3.Return" << endl;
    cout << "Enter your choice" << endl;
    cin >> ch1;
    if (ch1 == 1)
    {
        string name;
        dbhandler d;
        cout << "Enter the id of the book to be reserved" << endl;
        cin >> sno;
        cout << "Enter your name" << endl;
        cin >> name;
        d.updatequery(sno,ch1);
        d.updatequery(sno,1,name);
        d.insert_and_selectquery(sno,2);
        cout << "Reserved" << endl;
    }
    if (ch1 == 2)
    {
        string name;
        dbhandler d;
        cout << "Enter the id of the book to be borrowed" << endl;
        cin >> sno;
        cout << "Enter your name" << endl;
        cin >> name;
        d.updatequery(sno, ch1);
        d.updatequery(sno, 1,name);
        d.insert_and_selectquery(sno,1);
        cout << "Borrowed" << endl;
    }
    if (ch1 == 3)
    {
        dbhandler d;
        cout << "Enter the id of the book :" << endl;
        cin >> sno;
        d.deletequery(sno, 3);
        d.updatequery(sno, ch1);
        cout << "Returned Successfully" << endl;
    }
}
void Members::Search_and_Manage_Members()
{
    dbhandler d;
    cout << "-----------Search And Manage Members----------" << endl;
    cout << "Enter the name of the member" << endl;
    cin >> name1;
    d.selectquery(name1, 2);
}
void Members::add_Member()
{
      dbhandler d;
      cout << "Enter sno";
      std::cin >> id;
      cout << "Enter name";
      std::cin >> name1;
      cout << "Enter password";
      std::cin >> pass;
      cout << "Enter education";
      std::cin >> education;
      cout << "Enter Mail";
      std::cin >> mailid;
      cout << "Enter status";
      std::cin >> status;
    d.insertquery(id, name1, pass, education, mailid, status, 0);
    cout << "Added Member Successfully" << endl;
}
void Members::editMember()
{
    dbhandler d;
    int chid;
    cout << "Enter the id to be changed:";
    cin >> chid;
    cout << "Enter sno";
    std::cin >> id;
    cout << "Enter name";
    std::cin >> name1;
    cout << "Enter password";
    std::cin >> pass;
    cout << "Enter education";
    std::cin >> education;
    cout << "Enter Mail";
    std::cin >> mailid;
    cout << "Enter status";
    std::cin >> status;
    d.updatequery(id, name1,pass, education, mailid, status);
    cout << "Edited Successfully" << endl;
}
void Members::delete_Member()
{
    dbhandler d;
    int id1 = 0;
    cout << "Remove A Member";
    cout << "Enter the id to be deleted"<<endl;
    cin >> id1;
    d.deletequery(id1, 2);
}
void Users::Search_and_Manage_Users()
{
    dbhandler d;
    cout << "-----------Search And Manage  Users----------" << endl;
    cout << "Enter the name of the user" << endl;
    cin >> username;
    d.selectquery(username,4);
}
void Users::add_User()
{
    dbhandler d;
    cout << "Enter sno";
    std::cin >> id;
    cout << "Enter name";
    std::cin >> username;
    cout << "Enter password";
    std::cin >> password1;
    cout << "Enter education";
    std::cin >> education;
    cout << "Enter Mail";
    std::cin >> mailid;
    d.insertquery(id,username,password1,education,mailid,0);
    cout << "Added User Successfully"<<endl;
}
void Users::delete_User()
{
    dbhandler d;
    int sno2 = 0;
    cout << "Enter the id to be deleted"<<endl;
    cin >> sno2;
    d.deletequery(sno2,4);
}
void Users::privilege()
{
    dbhandler d;
    int num;
    cout << "Enter the id"<<endl;
    cin >> num;
    d.insert_and_selectquery(num);
}