#include"Member.h"
#include"librarym.h"
#include"dbhandler.h"
using namespace std;
string dbhandler::selectquery(string username, int ch)
{
	try
	{
		if (ch == 1)
		{
			string pwd;
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			string sql = "SELECT password FROM members WHERE name='" + username + "'";
			pqxx::result RE = W.exec(sql);
			for (pqxx::result::const_iterator c = RE.begin(); c != RE.end(); ++c)
			{
				pwd = c[0].as<string>();
			}
			W.commit();
			return pwd;
		}
		if (ch == 2)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			string sql = "SELECT * FROM Members WHERE name ='" + username + "'";
			pqxx::result RE = W.exec(sql);
			VariadicTable<int, string, string, string, string, int>vt({ "sno","Name","Education","mailid","status","book_id" });
			for (int i = 0; i < RE.size(); i++)
			{
				vt.addRow(RE[i][0].as<int>(), RE[i][1].as<string>(), RE[i][3].as<string>(), RE[i][4].as<string>(), RE[i][5].as<string>(), RE[i][6].as<int>());
			}
			vt.print(cout);
		}
		if (ch == 3)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			string sql = "SELECT *FROM books WHERE title ='" + username + "'";
			pqxx::result RE = W.exec(sql);
			VariadicTable< string, string, string, string, string, int>vt({ "title","author","subject","pd","status","sno" });
			for (int i = 0; i < RE.size(); i++)
			{
				vt.addRow(RE[i][0].as<string>(), RE[i][1].as<string>(), RE[i][2].as<string>(), RE[i][3].as<string>(), RE[i][4].as<string>(), RE[i][5].as<int>());
			}
			vt.print(cout);
		}
		if (ch == 4)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			string sql = "SELECT *FROM users WHERE username='" + username + "'";
			pqxx::result RE = W.exec(sql);
			VariadicTable<int, string, string, string, int>vt({ "user_id","username","education","mailid","book_id" });
			for (int i = 0; i < RE.size(); i++)
			{
				vt.addRow(RE[i][0].as<int>(), RE[i][1].as<string>(), RE[i][3].as<string>(), RE[i][4].as<string>(), RE[i][5].as<int>());
			}
			vt.print(cout);
		}
	}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
}
void dbhandler::selectquery(int ch)
{
	try
	{
		if (ch == 1)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec("SELECT *FROM loan");
			VariadicTable<int, int, string, string, int, string, string>vt({ "book_id","member_id","loan_date","returned_date","membername","username" });
			for (int i = 0; i < RE.size(); i++)
			{
				vt.addRow(RE[i][0].as<int>(), RE[i][1].as<int>(), RE[i][2].as<string>(), RE[i][3].as<string>(), RE[i][4].as<int>(), RE[i][5].as<string>(), RE[i][6].as<string>());
			}
			vt.print(cout);
		}
		if (ch == 2)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec("SELECT *FROM reserved_books");
			VariadicTable<int, int, string>vt({ "booksid","member_id","member_name" });
			for (int i = 0; i < RE.size(); i++)
			{
				vt.addRow(RE[i][0].as<int>(), RE[i][1].as<int>(), RE[i][2].as<string>());
			}
			vt.print(cout);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void dbhandler::insertquery(int sno, string title, string author, string subject, string pd, string status)
{
	try
	{
		pqxx::connection connectionObject(connectionString.c_str());
		pqxx::work W(connectionObject);
		pqxx::result RE = W.exec("INSERT INTO books (title,author,subject,pd,bookstatus,sno) VALUES('" + title + "','" + author + "','" + subject + "','" + pd + "','" + status + "'," + to_string(sno) + ")");
		W.commit();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void dbhandler::insertquery(int sno, string name, string pass, string education, string mail, string status, int id1)
{
	try
	{
		pqxx::connection connectionObject(connectionString.c_str());
		pqxx::work W(connectionObject);
		pqxx::result RE = W.exec("INSERT INTO members(sno,name,password,education,mail,status,book_id) VALUES(" + to_string(sno) + ",'" + name + "', '" + pass + "','" + education + "','" + mail + "','" + status + "'," + to_string(id1) + ")");
		W.commit();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void dbhandler::insertquery(int id, string username, string password1, string education, string mailid, int book_id1)
{
	try
	{
	pqxx::connection connectionObject(connectionString.c_str());
	pqxx::work W(connectionObject);
	pqxx::result RE = W.exec("INSERT INTO Users(user_id,username,password,education,mailid,book_id1) VALUES(" + to_string(id) + ",'" + username + "','" + password1 + "','" + education + "','" + mailid + "'," + to_string(book_id1) + ")");
	W.commit();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void dbhandler::deletequery(int sno1, int ch)
{
	try
	{
		if (ch == 1)
		{
			string sql = " DELETE FROM books WHERE sno= ";
			sql += to_string(sno1);
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(sql);
			W.commit();
		}
		if (ch == 2)
		{
			string qr = " DELETE FROM Members WHERE sno= ";
			qr += to_string(sno1);
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(qr);
			W.commit();
		}
		if (ch == 3)
		{
			string qr = " DELETE FROM loan WHERE book_id=";
			qr += to_string(sno1);
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(qr);
			W.commit();
		}
		if (ch == 4)
		{
			string qr = " DELETE FROM users WHERE user_id = ";
			qr += to_string(sno1);
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(qr);
			W.commit();
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
	void dbhandler::updatequery(int sno,string title,string author,string subject,string pd,string status,string n)
	{
		try
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			string sql = "UPDATE books SET sno=" + to_string(sno) + ", title='" + title + "', author='" + author + "', subject='" + subject + "',pd='"+pd+"',bookstatus='" + status + "' WHERE title = '" + n + "'";
			pqxx::result RE = W.exec(sql);
			W.commit();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	void dbhandler::updatequery( int sno, string name,string pass, string education, string mailid, string status)
	{
		try
		{
			pqxx::connection connectionObject(connectionString.c_str());
			pqxx::work W(connectionObject);
			string qr = "UPDATE Members SET sno = " + to_string(sno) + ", name = '" + name + "',password='" + pass + "', education = '" + education + "', mail = '" + mailid + "', status = '" + status + "' WHERE sno = " + to_string(sno) + "";
			pqxx::result RE = W.exec(qr);
			W.commit();
		}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	void dbhandler::updatequery(int sno1, int ch)
	{
		try
		{
			if (ch == 1)
			{
				pqxx::connection connectionObject(connectionString.c_str());
				string quer = "UPDATE books SET bookstatus='Reserved' WHERE sno = " + to_string(sno1) + "";
				pqxx::work W(connectionObject);
				pqxx::result RE = W.exec(quer);
				W.commit();
			}
			if (ch == 2)
			{
				pqxx::connection connectionObject(connectionString.c_str());
				string quer = "UPDATE books SET bookstatus='Borrowed' WHERE sno = " + to_string(sno1) + "AND bookstatus!='Reserved'";
				pqxx::work W(connectionObject);
				pqxx::result RE = W.exec(quer);
				W.commit();
			}
			if (ch == 3)
			{
				pqxx::connection connectionObject(connectionString.c_str());
				string quer = "UPDATE books SET bookstatus='Available' WHERE sno=" + to_string(sno1) + "";
				pqxx::work W(connectionObject);
				pqxx::result RE = W.exec(quer);
				W.commit();
			}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	void dbhandler::updatequery(int sno1,int ch,string name)
	{
		try
		{
		if (ch == 1)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			string quer = "UPDATE members SET book_id="+to_string(sno1)+" WHERE name='"+name+"'";
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(quer);
			W.commit();
		}
		if (ch == 2)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			string sql = "UPDATE users SET book_id1=" + to_string(sno1) + "WHERE username='"+name+"'";
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(sql);
			W.commit();
		}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	void dbhandler::insert_and_selectquery(int sno, int ch)
	{
		try
		{
		if (ch == 1)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			string qr = " INSERT INTO loan(book_id, member_id,loan_date,returned_date, membername) SELECT books.sno, members.sno,CURRENT_DATE,loan.loan_date+INTERVAL '10days', members.name FROM books, members,loan WHERE books.sno = " + to_string(sno) + " and members.book_id =" + to_string(sno) + "";
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(qr);
			W.commit();
		}
		if (ch == 2)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			string quer = "INSERT INTO reserved_books(booksid,member_id,member_name)SELECT books.sno,members.sno,members.name FROM books,members WHERE books.sno=" + to_string(sno) + " and members.book_id=" + to_string(sno) + "";
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(quer);
			W.commit();
		}
		if (ch == 3)
		{
			pqxx::connection connectionObject(connectionString.c_str());
			string sql = "INSERT INTO loan(book_id,members_id,returned date,membername) SELECT books.sno,users.user_id,loan.loan_date+INTERVAL '10days',users.username FROM books,users,loan WHERE books.sno=" + to_string(sno) + " and users.user_id=" + to_string(sno) + "";
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(sql);
			W.commit();
		}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
		void dbhandler::insert_and_selectquery(int sno)
		{
			try
			{
			pqxx::connection connectionObject(connectionString.c_str());
			string quer = "INSERT INTO members(sno,name,password,education,mail,status,book_id)SELECT user_id,username,password,education,mailid,'Active',book_id1 FROM users WHERE users.user_id="+to_string(sno)+"";
			pqxx::work W(connectionObject);
			pqxx::result RE = W.exec(quer);
			W.commit();
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}