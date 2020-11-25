#include "DBHandler.h"

#include <iostream>
#include <string>
#include <sstream>

DBHandler::DBHandler(const char* filename){
   this->filename = filename;
}


int DBHandler::open_connection(){
    int sql_error = sqlite3_open_v2(this->filename, this->ppDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if (sql_error != 0){
         const char* errmsg = sqlite3_errmsg(*this->ppDb);
         std::cout << errmsg << "\n";
         return 1;
    }
    return 0;
}

void DBHandler::check_error(){
    const char* errmsg = sqlite3_errmsg(*this->ppDb);
    std::cout << errmsg << "\n";
    sqlite3_close(*this->ppDb);
}

void DBHandler::create_character(Character character){
    open_connection();
    std::string create_statement = std::string("CREATE TABLE player_character (name TEXT, Str INTEGER, Dex INTEGER, Con INTEGER, Wis INTEGER, Int INTEGER, Cha INTEGER)");
    char** error_msg = nullptr;
    int sql_error = sqlite3_exec(*this->ppDb,create_statement.c_str(), NULL, NULL, error_msg);
    if(sql_error != 0) std::cout << error_msg << "\n";
    std::ostringstream store_statement_stream;
    store_statement_stream << "INSERT INTO player_character VALUES (";
    store_statement_stream << "'" << character.Name << "',";
    store_statement_stream << "'" << character.Str << "',";
    store_statement_stream << "'" << character.Dex << "',";
    store_statement_stream << "'" << character.Con << "',";
    store_statement_stream << "'" << character.Wis << "',";
    store_statement_stream << "'" << character.Int << "',";
    store_statement_stream << "'" << character.Cha << "')";

    std::string store_statement(store_statement_stream.str());
    sql_error = sqlite3_exec(*this->ppDb,store_statement.c_str(), NULL, NULL, error_msg);
    if(sql_error != 0) std::cout << error_msg << "\n";
    sqlite3_close(*this->ppDb);
}
