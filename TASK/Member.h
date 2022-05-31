#pragma once
#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include<string.h>
#include <pqxx/pqxx>
#include <exception>
#include "VariadicTable.h"
using namespace std;
    class Members
    {
    public:
        int id;
        string name1, pass, education, mailid, status;
       void Search_and_Manage_Members();
        void add_Member();
        void editMember();
        void delete_Member();
    };
#endif