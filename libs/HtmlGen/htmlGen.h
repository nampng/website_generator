#ifndef HTML_GEN_H
#define HTML_GEN_H

#include <filesystem>
#include <fstream>
#include <string>
#include <list>
#include <map>

#include "element.h"

class HtmlGenerator {
public:
	HtmlGenerator(std::filesystem::path input, std::filesystem::path output);
    ~HtmlGenerator() {};

    std::map<std::string, TagType> typeMap {
        {"TITLE", META},
        {"H1", BODY},
        {"H2", BODY},
        {"P", BODY},
        {"IMG", BODY},
        {"BREAK", BODY},
        {"LINK", BODY},
    };

    void parseAll();
    void parseScript(std::filesystem::path script);
    void createElement(std::string &line);
    void write();
private:
    std::filesystem::path scripts_dir;
    std::filesystem::path output_dir;

    std::list<Element> MetaElements;
    std::list<Element> BodyElements;
};

#endif  // HTML_GEN_H
