#pragma once
#ifndef LIBRARYM_H
#define LIBRARYM_H
#include <iostream>
#include<string.h>
#include <pqxx/pqxx>
#include <exception>
using namespace std;
    class Lib
    {
    public:
        int sno;
        string title, author, subject, pd,status;
        void login();
        void Search_and_Manage();
        void addBook();
        void editBook();
        void removeBook();
        void book_status();
    };
#endif