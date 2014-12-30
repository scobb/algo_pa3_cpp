#include "parser.h"
#include <iostream>

using namespace std;
void Parser::process(){
    ifstream my_ifstream = ifstream();
    my_ifstream.open(filename);

    if (my_ifstream.is_open()){
        // initialize the dictionary
        parse(&my_ifstream);
//        cout << "building sentences." << endl;
        build_sentences();
//        cout << "generating output." << endl;
        output();

    } else {
        cout << "Unable to open file." << endl;
    }

}

void Parser::parse(ifstream *my_ifstream) {
    string line;
    getline(*my_ifstream, line);
    num_words = stoi(line);

    for (int i = 0; i < num_words; i++){
        getline(*my_ifstream, line);
        dictionary.insert(line);
    }
    getline(*my_ifstream, line);
    set_transcript_str(line);

    my_ifstream->close();

}

void Parser::build_sentences() {
    vector<unsigned long> to_check = vector<unsigned long>();
    to_check.push_back(0);
    for (unsigned long start = 0; start < transcript_str.size(); start++){
        if (find(to_check.begin(), to_check.end(), start) == to_check.end()){
            // we don't need to check this one
            // cout << "start is " << start << ", continuing." << endl;
            continue;
        }
        // cout << "Checking from " << start << endl;
        for (unsigned long length = 1; length < transcript_str.size() + 1 - start; length++){
            unsigned long end = start+length;
            string word = transcript_str.substr(start, length);
            // cout << "checking " << word << endl;
            if (dictionary.count(word)){
                // cout << "found " << word << endl;
                if (start == 0){
                    // cout << "adding " << word << " at " << end << endl;
                    arr[end].push_back(word);
                } else {
                    for (string prev_phrase: arr[start]){
                        // cout << "adding " << prev_phrase + " " + word << " at " << end << endl;
                        arr[end].push_back(prev_phrase + " " + word);
                    }
                }
                if (find(to_check.begin(), to_check.end(), end) == to_check.end()){
                    // cout << "adding " << end << " to to_check" << endl;
                    to_check.push_back(end);
                    sort(to_check.begin(), to_check.end());
                }
            }

        }

    }

}

void Parser::output() {
    vector<string> output = arr[transcript_str.size()];
    cout << output.size() << endl;
    for (string phrase: output) {
        cout << phrase << endl;

    }

}
