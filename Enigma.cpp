#include "Enigma.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;

//using std::set;
//using std::string;
// Constructs a new Enigma with the specified data.
//
// @param name : the name of the enigma.
// @param difficulty : the difficulty of the enigma.
// @param numOfElements : the number of elements in the enigma.
Enigma::Enigma(const std::string& name, const Difficulty& difficulty,
               const int& numOfElements):
        name(name),difficulty(difficulty), numOfElements(numOfElements){
}
//copy constructor
//
//@param enigma : the enigma to be copied.
//Enigma::Enigma(const Enigma& enigma) = default;

//assignment operator
//
//@param enigma : the enigma to be assigned.
//Enigma& Enigma::operator=(const Enigma& enigma) = default;

// Comparison operators for Enigmas. enigmas are compared as described in
// the exercise sheet.
//
// @param enigma : the right-hand side operand.
bool Enigma::operator==(const Enigma& enigma) const {
    return (this->name==enigma.name && this->difficulty==enigma.difficulty);
}

bool Enigma::operator!=(const Enigma& enigma) const {
    return !(*this==enigma);
}

bool Enigma::operator<(const Enigma& enigma) const {
    return (this->difficulty-enigma.difficulty<0)? true: false;
}
bool Enigma::operator>(const Enigma& enigma) const {
    return (enigma<*this);
}

//bool Enigma::operator<=(const Enigma& enigma) const = delete;
//bool Enigma::operator>=(const Enigma& enigma) const = delete;

// method returns true if both enigmas are equaly complex.
//definition of equaly complex is described in the exercise sheet.
//
//@param enigma : the enigma being compared to.
bool Enigma::areEqualyComplex(const Enigma& enigma) const {
    return (this->difficulty==enigma.difficulty &&
            this->numOfElements==enigma.numOfElements);
}

//Function returns the name of the enigma.
//
string Enigma::getName() const {
    return this->name;
}


// return the difficulty level of the enigma.
//
Difficulty Enigma::getDifficulty() const {
    return this->difficulty;
}

// Prints the data of the Enigma in the following format:
//
//     "<name> (<Difficulty>) <number of items>"
//
// @param output : the output stream to which the data is printed.
// @param enigma : the enigma whose data is printed.
std::ostream& mtm::escaperoom::operator<<(std::ostream& output,
                                          const Enigma& enigma) {
     return output << enigma.name << "(" << enigma.difficulty << ")" <<
                                                           enigma.numOfElements;
}

//~Enigma() = default;


std::ostream& operator<<(std::ostream& output, const Enigma& enigma);