#include"librarym.h"
#include"Member.h"
#include"users.h"
#include"dbhandler.h"
int main()
{
	Lib l;
	Members m;
	Users u;
	int n, och = 0, inch;
	cout <<"\t"<<"----------WELCOME TO LIBRARY----------"<<endl;
	while (och != 5)
	{
		cout << "1.Librarian" << "\t" << "2.Members" << "\t" << "3.Users" << "\t" << "4.SignUp" << "\t" << "5.EXIT" << endl;
		std::cin >> och;
		if (och == 1)
		{
			l.login();
			inch = 0;
			while (inch != 6)
			{
				cout << "1.Search_Manage_Member" << endl << "2.My_accounts" << endl << "3.Search_Manage_Books" <<endl<< "4.Search_Manage_User" << endl << "5.Add Previleges" << endl << "6.VIEW"<<endl<<"7.Exit" << endl;
				cout << "Enter your choice" << endl;
				std::cin >> inch;
				switch (inch)
				{
				case 1:
					cout << "1.Search" << endl << "2.Add" << endl << "3.Edit" << endl << "4.Delete" << endl;
					std::cin >> n;
					if (n == 1)
					{
						m.Search_and_Manage_Members();
					}
					else if (n == 2)
						m.add_Member();
					else if (n == 3)
						m.editMember();
					else if (n == 4)
						m.delete_Member();
					break;
				case 2:
					m.editMember();
					break;
				case 3:
					cout << "1.Search" << endl << "2.Add" << endl << "3.Edit" << endl << "4.Remove" << endl << "5.Book_Status" << endl;
					cout << "Enter your choice" << endl;
					std::cin >> n;
					if (n == 1)
					l.Search_and_Manage();
					else if (n == 2)
						l.addBook();
					else if (n == 3)
						l.editBook();
					else if (n == 4)
						l.removeBook();
					else if (n == 5)
						l.book_status();
					break;
				case 4:
					cout << "1.Search" << endl << "2.Add" << endl << "3.Delete" << endl;
					cout << "Enter your choice" << endl;
					std::cin >> n;
					if (n == 1)
						u.Search_and_Manage_Users();
					else if (n == 2)
						u.add_User();
					else if (n == 3)
						u.delete_User();
					break;
				case 5:
					u.privilege();
					break;
				case 6:
					cout << "1.Borrowed_Books" << endl << "2.Reserved_Books" << endl;
					cout << "Enter your choice" << endl;
					std::cin >> n;
					if (n == 1)
					{
						dbhandler d;
						d.selectquery(n);
					}
					else if (n == 2)
					{
						dbhandler d;
						d.selectquery(n);
					}
					break;
				case 7:
					break;
				}
			}
		}
		else if (och == 2)
		{
			inch = 0;
			l.login();
			while (inch != 3)
			{
				cout << "1.My_accounts" << endl << "2.Search_Manage_Books" << endl << "3.Exit" << endl;
				cout << "Enter your choice" << endl;
				std::cin >> inch;
				switch (inch)
				{

				case 1:
					m.editMember();
					break;
				case 2:
					cout << "1.Search" << endl << "2.Book_Status" << endl;
					cout << "Enter your choice" << endl;
					cin >> inch;
					if (inch == 1)
						l.Search_and_Manage();
					else
						l.book_status();
					break;
				case 3:
					break;
				}
			}
		}
		else if (och == 3)
		{
			inch = 0;
			l.login();
			while (inch != 3)
			{
				cout << "1.My accounts" << endl << "2.Search_and_Manage_books" << endl << "3.Exit" << endl;
				cout << "Enter your choice" << endl;
				cin >> inch;
				switch (inch)
				{
				case 1:
					u.add_User();
					break;
				case 2:
					cout << "1.Search" << endl << "2.Book_Status" << endl;
					cout << "Enter your choice" << endl;
					cin >> inch;
					if (inch == 1)
						l.Search_and_Manage();
					else
						l.book_status();
					break;
				}
			}
		}
		else if (och == 4)
		{

			cout << "1.Member" << endl << "2.User" << endl;
			cout << "Enter your choice" << endl;
			cin >> inch;
			switch (inch)
			{
			case 1:
				m.add_Member();
				break;
			case 2:
				u.add_User();
				break;
			}
		}
		else
			och = 5;
	}
 }
