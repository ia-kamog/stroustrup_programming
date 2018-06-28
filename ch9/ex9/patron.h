#ifndef PATRON_H_
#define PATRON_H_
#include <string>
class Patron {
public:
     Patron(std::string nname, int nid)
	  :name {nname}, id{nid}, fees{0} {}
     bool owes() const { return fees >= 0.01; }
     const std::string& get_name() const { return name; }
     double get_fees() const { return fees; }
     void set_fees(double f) { fees = f; }
     int get_id() const { return id; }
private:
     std::string name;
     int id;
     double fees;
};
bool operator==(const Patron&, const Patron&);
bool operator!=(const Patron&, const Patron&);
std::ostream& operator<<(std::ostream&, const Patron&);
#endif
