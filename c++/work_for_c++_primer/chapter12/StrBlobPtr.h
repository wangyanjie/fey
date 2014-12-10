#ifndef CHAPTER12_STRBLOBPTR_H
#define CHAPTER12_STRBLOBPTR_H

#include <vector>
#include <string>
#include "StrBlob.h"


class StrBlob;
class StrBlobPtr {
  public :
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &sb, std::size_t sz = 0):
      wptr(sb.data), curr(0) {}
    std::string& deref() const;
    StrBlobPtr& incr();
  private :
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    std::shared_ptr<std::vector<std::string>>
      check(std::size_t sz, const std::string &s) const;
};

#endif
