#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "std_lib_facilities.h"
class Variable {
public:
    string name;
    double value;
    bool is_const;
};

class Symbol_table {
public:
    Symbol_table() { }
    double get_value(const string& name);
    void set_value(const string& name, double value);
    bool is_declared(const string& name);
    double define_name(const string& name, double value, bool constant);
private:
    vector<Variable> var_table;
};
#endif
