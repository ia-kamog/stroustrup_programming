#ifndef NAME_PAIRS_H_
#define NAME_PAIRS_H_
#include <iostream>
#include <string>
#include <vector>
const auto name_sentinel = "eof";
class Name_pairs {
public:
     void sort();
     void read_names();
     void read_ages();
     Name_pairs() :names{}, ages{} {}
     const std::string& name(std::size_t i) const { return names[i]; }
     double age(std::size_t i) const { return ages[i]; }
     size_t size() const { return names.size(); }
private:
     std::vector<std::string> names;
     std::vector<double> ages;
};
std::ostream& operator<<(std::ostream&, const Name_pairs&);
bool operator==(Name_pairs&, Name_pairs&);
bool operator!=(Name_pairs&, Name_pairs&);
#endif
