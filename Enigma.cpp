#include "Enigma.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;


Enigma::Enigma(const std::string& name, const Difficulty& difficulty,
               const int& numOfElements, const set<string>& elements):
        name(name),difficulty(difficulty), numOfElements(numOfElements),
        elements(elements){
    if(this->numOfElements!=this->elements.size()) {
        throw EnigmaIllegalSizeParamException();
    }
}

Enigma::Enigma(const std::string& name, const Difficulty& difficulty):
        name(name),difficulty(difficulty),numOfElements(0),
        elements(){
}

Enigma::Enigma(const Enigma& enigma):name(enigma.name),
                                     difficulty(enigma.difficulty),
                                     numOfElements(enigma.numOfElements),
                                     elements(enigma.elements){
}


Enigma& Enigma::operator=(const Enigma& enigma){
    if(this==&enigma){
        return *this;
    }
    this->name=enigma.name; ////////////possiably a memory leak
    this->numOfElements=enigma.numOfElements;
    this->difficulty=enigma.difficulty;
    this->elements=enigma.elements;////////////possiably a memory leak
}

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

void Enigma::addElement(const string& element){
    this->elements.insert(element);
}

void Enigma::removeElement(const string& element){
    if(this->elements.empty()){
        throw EnigmaNoElementsException();
    }
    int set_original_size=this->elements.size();
    this->elements.erase(element);
    if(this->elements.size()==set_original_size){
        throw EnigmaElementNotFoundException();
    }
}

std::ostream& mtm::escaperoom::operator<<(std::ostream& output,
                                          const Enigma& enigma) {
     return output << enigma.name << "(" << enigma.difficulty << ")" <<
                                                           enigma.numOfElements;
}

//~Enigma() = default;



std::ostream& operator<<(std::ostream& output, const Enigma& enigma);