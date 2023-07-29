#ifndef HTML_GEN_H
#define HTML_GEN_H

#include <filesystem>
#include <fstream>
#include <string>


class HtmlGenerator {
	HtmlGenerator(std::filesystem::path input, std::filesystem::path output);
    ~HtmlGenerator();

    void parseAll();
    void parseScript(std::filesystem::path script);

private:
    std::filesystem::path scripts_dir;
    std::filesystem::path output_dir;
};

#endif  // HTML_GEN_H
