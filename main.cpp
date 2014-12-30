#include <iostream>
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }
    Parser my_parser = Parser(argv[1]);
    my_parser.process();
    return 0;
}