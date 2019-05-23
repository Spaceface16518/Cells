//
// Created by Amrit Rathie on 2019-05-18.
//
#include <string>
#include <fstream>
#include <regex>
#include "options.h"

std::string get_file_contents(const char *filename);

void include_coords(const std::string &s, std::vector<std::tuple<int, int>> &coords);

std::tuple<int, int> parse(std::string match);

std::vector<std::tuple<int, int>> get_initial_living(int argc, const char **argv) {
    std::vector<std::tuple<int, int>> coords;
    for (int i = 1; i < argc; ++i) {
        std::string contents = get_file_contents(argv[i]);
        include_coords(contents, coords);
    }

    return coords;
}

// Stolen from http://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html
std::string get_file_contents(const char *filename) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (!in) {
        throw std::runtime_error("Error opening file");
    }

    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return (contents);
}

void include_coords(const std::string &string, std::vector<std::tuple<int, int>> &coords) {
    std::string s = string;
    const std::regex re("\\d* \\d*");

    std::smatch matchResults;

    while (std::regex_search(s, matchResults, re)) {
        for (auto &match: matchResults) {
            const std::string delimiter = " ";

            // Get the string out of the match
            std::string matchString = match.str();

            // Find the index of the space separator in the string
            auto delimiterIndex = matchString.find(delimiter);

            // Use the space to separate the two halves of the string
            std::string xStr = matchString.substr(0, delimiterIndex);
            std::string yStr = matchString.substr(delimiterIndex + delimiter.length(), matchString.length());

            // Convert the strings to integers
            int x = std::stoi(xStr);
            int y = std::stoi(yStr);

            coords.emplace_back(x, y);

            s = matchResults.suffix().str(); // TODO: optimize this a lot
        }
    }
}
