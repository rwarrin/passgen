/******************************************************************************
 * passgen.cpp
 *
 * Rick W
 * 02/14/2012
 *
 * Generates a specified number of passwords of an optional length. Default
 * length is 8 characters.
 *
 *****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

// Generates a list of randomly generated passwords.
// @param: numberOfPasswords - Total number of passwords to generate
// @param: passwordLength - Length of passwords generated
// @return: Vector containing strings of generated passwords
std::vector<std::string> GeneratePasswords(int numberOfPasswords, int passwordLength);

// Write password vector to stream
// @param: out - Reference to a stream to output passwords too
// @param: passwords - Vector containing password strings to write
void WritePasswordsToStream(std::ostream& out, std::vector<std::string> &passwords);

int main(int argc, char *argv[]) {
    using namespace std;

    // seed random number generator
    srand(time(NULL));

    // check arguments
    if(argc < 2 || argc > 3) {
        cout << "passgen <num passwords> <password length>\n";
        return 1;
    }

    int numberOfPasswords = 0;
    int passwordLength = 8;

    // process arguments
    numberOfPasswords = atoi(argv[1]);

    // get length of passwords to generate if specified
    if(argc == 3)
        passwordLength = atoi(argv[2]);

    // vector to hold passwords
    vector<string> passwords = GeneratePasswords(numberOfPasswords, passwordLength);

    // write passwords to stream
    WritePasswordsToStream(cout, passwords);

    return 0;
}

// Generate a list of random passwords
std::vector<std::string> GeneratePasswords(int numberOfPasswords, int passwordLength) {
    using namespace std;

    vector<string> passwords;
    string str;

    // for the number of passwords to generate, create one string of the 
    // specified length. store the generated password in the vector.
    for(int count = 0; count < numberOfPasswords; count++) {
        str = "";
        for(int length = 0; length < passwordLength; length++) {
            str += (rand() % 93) + 33;  // normal alpha and special characters
        }
        passwords.push_back(str);
    }

    return passwords;
}

// Write a vector of passwords to a stream
void WritePasswordsToStream(std::ostream& out, std::vector<std::string> &passwords) {
    using namespace std;
    
    // create iterator, then loop through the vector writing one password
    // at a time to the stream.
    vector<string>::iterator iter;
    for(iter = passwords.begin(); iter != passwords.end(); iter++)
        out << *iter << endl;
}

