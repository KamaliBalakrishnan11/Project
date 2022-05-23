#include "Login.h"
#include"Member.h"

int main()
{
    Lib l;
    Members m;
    int n,ch;
    cout << "----------LIBRARY----------" << endl;
    cout << "1.Librarian" << "\t" << "2.Members" << "\t" << "3.SignUp" <<"\t"<<"4.EXIT"<<endl;
    cin >> n;
        if (n == 3)
        {
            m.add_Member();
            l.login();
        }
        else if (n==1)
        {
            int n1=1;
            l.login();
            while (n1 != 4)
            {
                cout << "1.Search_Manage_Member" << endl << "2.My_accounts" << endl << "3.Search_Manage_Books" << endl<<"4.Exit" << endl;
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
                    if (ch == 2)
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
                    {
                        l.displayList();
                        l.Search_and_Manage();
                    }
                    else if (ch == 2)
                        l.addBook();
                    else if (ch == 3)
                        l.editBook();
                    else if (ch == 4)
                        l.removeBook();
                    else if (ch == 5)
                        l.book_status();
                    break;
                case 4:
                    break;
                }
            }
        }
        else
        {
            int ch1=1;
            l.login();
            while (ch != 3)
            {
                cout << "1.My_accounts" << endl << "2.Search_Manage_Books" << endl << "3.Exit" << endl;
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
                case 3:
                    break;
                }
            }
        }
        system("Pause");
}