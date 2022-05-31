#pragma once
#include <iostream>
#include<string.h>
#include <pqxx/pqxx>
#include <exception>
using namespace std;
class dbhandler
{
public:
    string connectionString = "host=localhost port=5432 dbname=LIBRARY user=postgres password =root";
    string selectquery(string,int);
    void selectquery(int);
    void insertquery(int, string, string, string, string,string);
    void insertquery(int,string, string, string, string, string,int);
    void insertquery(int, string, string, string, string,int);
    void insert_and_selectquery(int,int);
    void insert_and_selectquery(int);
    void deletequery(int,int);
    void updatequery(int,string,string,string,string,string,string);
    void updatequery(int, string,string, string, string, string);
    void updatequery(int,int);
    void updatequery(int, int,string);
};
