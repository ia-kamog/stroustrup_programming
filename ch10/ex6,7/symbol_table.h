#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "roman.h"
#include "std_lib_facilities.h"
class Variable {
public:
     string name;
     Roman_int value;
     bool is_const;
};

class Symbol_table {
public:
     Symbol_table() { }
     Roman_int get_value(const string& name);
     void set_value(const string& name, Roman_int value);
     bool is_declared(const string& name);
     Roman_int define_name(const string& name, Roman_int value, bool constant);
private:
     vector<Variable> var_table;
};
#endif
