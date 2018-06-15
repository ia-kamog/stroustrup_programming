#include "symbol_table.h"

int Symbol_table::get_value(const string& s)
{
     for (const Variable& v: var_table)
	  if (v.name == s) return v.value;
     error("get: undefined variable ", s);
}

void Symbol_table::set_value(const string& s, int d)
{
     for (Variable& v : var_table)
	  if (v.name == s) {
	       if (v.is_const)
		    error("attempt to modify the constant ", v.name);
	       v.value = d;
	       return;
	  }
     error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(const string& var)
{
     for (const Variable& v : var_table)
	  if (v.name == var) return true;
     return false;
}

int Symbol_table::define_name(const string& var, int val, bool constant)
{
     if (is_declared(var)) error(var, " declared twice");
     var_table.push_back(Variable{var, val, constant});
     return val;
}
