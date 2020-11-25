#pragma once


#include <sqlite3.h>
#include "character.hpp"

class DBHandler {
public:
    void create_character(Character);
    DBHandler(const char*);
private:
    const char *filename;
    sqlite3 **ppDb;
    int open_connection();
    void check_error();
};
