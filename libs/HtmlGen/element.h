#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <map>

struct Element {
    std::string tag; 
    std::string value;
};

enum TagType {
    META = 1,
    BODY = 2,
};

#endif  // ELEMENT_H
