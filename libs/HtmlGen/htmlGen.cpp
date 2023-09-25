#include "htmlGen.h"

#include <iostream>
#include <fstream>
#include <string>

HtmlGenerator::HtmlGenerator(std::filesystem::path input, std::filesystem::path output)
{
    scripts_dir = input;
    output_dir = output;
}

void HtmlGenerator::parseAll()
{
    for (auto const& script : std::filesystem::directory_iterator(scripts_dir))
    {
        parseScript(script);
    }
}

void HtmlGenerator::parseScript(std::filesystem::path script)
{
    std::cout << "Currently parsing: " << script << '\n';
    std::ifstream file(script);

    if (!file.is_open())
    {
        std::cout << "Failed to open: " << script << '\n';
        return;   
    }

    std::string line;

    while(getline(file, line))
    {
        std::cout << line << '\n';
        createElement(line);
    }
    
    file.close();
}

void HtmlGenerator::createElement(std::string &line)
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

void HtmlGenerator::write()
{
    std::filesystem::path outputFile = output_dir / "output.html";
    std::ofstream file(outputFile, std::ios::out);

    std::cout << "Writing to " << outputFile << '\n';

    if (!file.is_open())
    {
        std::cout << "Failed to open " << outputFile << '\n';
        return;
    }
    // Create the meta tags
    file << "<head>" << std::endl;
    for (Element &element : MetaElements)
    {
        file << '<' << element.tag << '>';
        file << element.value;
        file << '<' << '/' << element.tag << '>' << std::endl;
    }
    file << "</head>" << std::endl;
    // Now create the body tags
    file << "<body>" << std::endl;
    for (Element &element : BodyElements)
    {
        file << '<' << element.tag << '>';
        file << element.value;
        file << '<' << '/' << element.tag << '>' << std::endl;
    }
    file << "</body>" << std::endl;

    file.close();
}

