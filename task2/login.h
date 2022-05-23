#pragma once
#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include<string.h>
#include <pqxx/pqxx>
#include <exception>
#include "VariadicTable.h"
using namespace std;
    class Lib
    {
    public:
        int sno;
        string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
        string title, author, subject, pd;
        void login();
       void Search_and_Manage();
        void addBook();
        void editBook();
        void removeBook();
        void book_status();
        void displayList();
    };
#endif