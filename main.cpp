#include <iostream>
#include <filesystem>

#include "htmlGen.h"

int main()
{
    std::cout << "Generating website...\n";
    
    // PATHS
    std::filesystem::path origin = std::filesystem::current_path();

    std::filesystem::path scripts_dir = origin / "scripts";
    std::filesystem::path resources_dir = origin / "resources";
    std::filesystem::path output_dir = origin / "output"; 

    // Parse scripts and generate html files.
    HtmlGenerator generator(scripts_dir, output_dir);
    generator.parseAll();

    // Move resources to output/resource

    std::cout << "Goodbye!\n";
    return 0;
}
