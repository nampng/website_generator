#include "htmlGen.h"

#include <iostream>

HtmlGenerator::HtmlGenerator(std::filesystem::path input, std::filesystem::path output) {
    scripts_dir = input;
    output_dir = output;
}

HtmlGenerator::~HtmlGenerator() {

}

void HtmlGenerator::parseAll()
{
    for (auto const& script : std::filesystem::directory_iterator(scripts_dir))
    {
        std::cout << script;

    }
}
