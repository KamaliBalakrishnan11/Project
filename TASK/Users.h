#pragma once
#ifndef USERS_H
#define USERS_H
#include<iostream>
#include<string.h>
#include <pqxx/pqxx>
#include <exception>
#include "VariadicTable.h"
using namespace std;
class Users
{
public:
    int id;
    string  username, password1, education, mailid,bookid1;
    void Search_and_Manage_Users();
    void add_User();
    void delete_User();
    void privilege();
};
#endif