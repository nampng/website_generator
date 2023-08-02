#include "htmlGen.h"

#include <iostream>
#include <fstream>
#include <string>

HtmlGenerator::HtmlGenerator(std::filesystem::path input, std::filesystem::path output) {
    scripts_dir = input;
    output_dir = output;
}

void HtmlGenerator::parseAll() {
    for (auto const& script : std::filesystem::directory_iterator(scripts_dir)) {
        parseScript(script);
    }
}

void HtmlGenerator::parseScript(std::filesystem::path script) {
    std::cout << "Currently parsing: " << script << '\n';
    std::ifstream file(script);

    if (!file.is_open()) {
        std::cout << "Failed to open: " << script << '\n';
        return;   
    }

    std::string line;

    while(getline(file, line)) {
        std::cout << line << '\n';
        createElement(line);
    }
    
    file.close();
}

void HtmlGenerator::createElement(std::string line)
{
    std::string::size_type delim = line.find(';');
    std::string tag = line.substr(0, delim);
    std::string value = line.substr(delim + 1, line.size());

    std::cout << "Tag: " << tag << '\n';
    std::cout << "Value: " << value << '\n';

    Element element;
    element.tag = tag; 
    element.value = value;

    switch(typeMap[tag])
    {
        case(META):
            std::cout << "Adding meta element...\n";
            MetaElements.push_back(element);
            break;
        case(BODY):
            std::cout << "Adding body element...\n";
            BodyElements.push_back(element);
            break;
        default:
            std::cout << "Cannot determine tag type of: " << tag << '\n';
            break;
    } 

}


