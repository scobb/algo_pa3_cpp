#ifndef _PARSER_H
#define _PARSER_H

#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>

class Parser{
private:
    std::string filename;
    std::string transcript_str;
    std::vector<std::string>* arr;
    std::unordered_set<std::string> dictionary;
    int num_words;
    void parse(std::ifstream*);
    void build_sentences();
    void output();
public:
    Parser(std::string filename) : filename(filename) {
        dictionary = std::unordered_set<std::string>();
        arr = NULL;
    }

    virtual ~Parser() {
        if (arr != NULL){
            delete[] arr;
        }
    }

    void set_transcript_str(std::string &transcript_str) {
        Parser::transcript_str = transcript_str;
        arr = new std::vector<std::string>[transcript_str.size()+1];
    }

    void process();
};

#endif