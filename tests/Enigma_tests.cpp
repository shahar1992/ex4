#include "../Enigma.h"
#include "../mtmtest.h"
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;
using std::set;
using std::cout;
using std::endl;
void testEnigmaCreate() {
    ASSERT_NO_THROW(Enigma("TheOzWizard",EASY_ENIGMA));
    set<string> elements;
    elements.insert("Stick");
    ASSERT_NO_THROW(Enigma("LiveOrDie",HARD_ENIGMA,1,elements));
    ASSERT_THROWS(EnigmaIllegalSizeParamException,
                  Enigma("LiveOrDie",HARD_ENIGMA,0,elements));
    ASSERT_THROWS(EnigmaIllegalSizeParamException,
                  Enigma("LiveOrDie",HARD_ENIGMA,3,elements));
}

void testEnigmaCpyAndAssignment() {
    set<string> elements;
    elements.insert("Stick");
    Enigma mystery1=Enigma("mystery1",HARD_ENIGMA,1,elements);
    Enigma mystery2=mystery1;
    assert(mystery1==mystery2);
    assert(mystery2.getDifficulty()==HARD_ENIGMA);
    assert(mystery2.getName()=="mystery1");
}
void testEnigmaEqualty() {
    set<string> elements1,elements2;
    elements1.insert("Stick");elements1.insert("Of");elements1.insert("Truth");
    elements2.insert("Gendalf");elements2.insert("Staff");
    Enigma mystery1=Enigma("mystery1",HARD_ENIGMA,3,elements1);
    Enigma mystery2=Enigma("mystery1",HARD_ENIGMA,2,elements2);
    assert(mystery1==mystery2);//same name and difficulty
    Enigma mystery3=Enigma("mystery3",HARD_ENIGMA,2,elements2);
    assert(mystery1!=mystery3);// different name
    Enigma mystery4=Enigma("mystery1",EASY_ENIGMA,2,elements2);
    assert(mystery1!=mystery4);//different difficulty
}

void testEnigmaComparison() {
    set<string> elements1,elements2;
    elements1.insert("Stick");elements1.insert("Of");elements1.insert("Truth");
    elements2.insert("Gendalf");elements2.insert("Staff");
    Enigma mystery1=Enigma("mystery1",EASY_ENIGMA,3,elements1);
    Enigma mystery2=Enigma("mystery2",MEDIUM_ENIGMA,2,elements2);
    Enigma mystery3=Enigma("mystery3",HARD_ENIGMA,2,elements2);
    assert(mystery1<mystery2 && mystery1<mystery3 && mystery2<mystery3);
    assert(mystery3>mystery2 && mystery3>mystery1 && mystery2>mystery1);
}

void testEnigmaEqualyComplex() {
    set<string> elements1,elements2;
    elements1.insert("Stick");elements1.insert("Of");elements1.insert("Truth");
    elements2.insert("Gendalf");elements2.insert("Staff");
    Enigma mystery1=Enigma("mystery1",EASY_ENIGMA,3,elements1);
    Enigma mystery2=Enigma("mystery2",EASY_ENIGMA,3,elements1);
    Enigma mystery3=Enigma("mystery3",HARD_ENIGMA,3,elements1);
    Enigma mystery4=Enigma("mystery3",EASY_ENIGMA,2,elements2);
    assert(mystery1.areEqualyComplex(mystery2)== true);
    assert(mystery1.areEqualyComplex(mystery3)== false);//different difficulty
    assert(mystery1.areEqualyComplex(mystery4)==false);//different numofelements
}

void testEnigmaGetDifficulty(){
    Enigma en1=Enigma("1",EASY_ENIGMA);
    Enigma en2=Enigma("2",MEDIUM_ENIGMA);
    Enigma en3=Enigma("1",HARD_ENIGMA);
    assert(en1.getDifficulty()==EASY_ENIGMA);
    assert(en2.getDifficulty()==MEDIUM_ENIGMA);
    assert(en3.getDifficulty()==HARD_ENIGMA);
}

void testEnigmaGetName(){
    Enigma en1=Enigma("1",EASY_ENIGMA);
    Enigma en2=Enigma("2",MEDIUM_ENIGMA);
    Enigma en3=Enigma("3",HARD_ENIGMA);
    assert(en1.getName()=="1");
    assert(en2.getName()=="2");
    assert(en3.getName()=="3");
}

/*void testEnigmaAddElement(){
    set<string> elements1;
    elements1.insert("Amir");elements1.insert("Shahar");
    Enigma mystery1=Enigma("mystery1",EASY_ENIGMA,2,elements1);
    assert(mystery1.)
    mystery1.addElement("Avivi");
}*NO REAL WAY TO CHECK FOR NOW*/

void testEnigmaRemoveElement(){
    set<string> elements1;
    elements1.insert("Amir");elements1.insert("Shahar");
    Enigma mystery1=Enigma("mystery1",EASY_ENIGMA,2,elements1);
    ASSERT_THROWS(EnigmaElementNotFoundException,mystery1.removeElement("mtm"));
    ASSERT_NO_THROW(mystery1.removeElement("Amir"));
    ASSERT_NO_THROW(mystery1.removeElement("Shahar"));
    ASSERT_THROWS(EnigmaNoElementsException,mystery1.removeElement("etc"));
}

int main() {
    RUN_TEST(testEnigmaCreate);
    RUN_TEST(testEnigmaCpyAndAssignment);
    RUN_TEST(testEnigmaEqualty);
    RUN_TEST(testEnigmaComparison);
    RUN_TEST(testEnigmaEqualyComplex);
    RUN_TEST(testEnigmaGetDifficulty);
    RUN_TEST(testEnigmaGetName);
    //RUN_TEST(testEnigmaAddElement);
    RUN_TEST(testEnigmaRemoveElement);

}