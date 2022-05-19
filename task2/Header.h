#pragma once
#include <iostream>
#include<string.h>
#include <pqxx/pqxx>
#include <exception>
using namespace std;
class Lib
{
public:
 int sno;
    string title, author, subject, pd;
    void login();
    void Search_and_Manage();
    void addBook();
    void editBook();
    void removeBook();
    void book_status();
    void displayList();
}l;
class Members
{
public:
    int id;
    string name1, pass, education, mailid, status;
    void Search_and_Manage_Members();
    void add_Member();
    void editMember();
    void delete_Member();
}m;