#include "StrBlob.h"

StrBlob::StrBlob(): 
  data(std::make_shared<std::vector<std::string>> ()) {}
StrBlob::StrBlob(std::initializer_list<std::string> li):
  data(std::make_shared<std::vector<std::string>>(li)) {}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
  if(i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  data->back();
}
