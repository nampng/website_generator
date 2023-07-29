#include "htmlGen.h"

#include <iostream>
#include <fstream>
#include <string>

HtmlGenerator::HtmlGenerator(std::filesystem::path input, std::filesystem::path output) {
    scripts_dir = input;
    output_dir = output;
}

HtmlGenerator::~HtmlGenerator() {

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
        std::cout << "Couldn't open for some reason!\n";
        return;   
    }

    std::string line;

    while(getline(file, line)) {
        std::cout << line << '\n';
    }
    
    file.close();
    return;
}
