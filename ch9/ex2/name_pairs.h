#ifndef NAME_PAIRS_H_
#define NAME_PAIRS_H_
#include <string>
#include <vector>
const auto name_sentinel = "eof";
class Name_pairs {
public:
     void sort();
     void read_names();
     void read_ages();
     void print() const;
     Name_pairs() :names{}, ages{}, maxname {0} {}
private:
     std::vector<std::string> names;
     std::vector<double> ages;
     std::size_t maxname;
};
#endif
