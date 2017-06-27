#include "../EscapeRoomWrapper.h"
#include "../mtmtest.h"
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;
using std::set;

void testEscapeRoomWrapperConstructor() {

    ASSERT_NO_THROW(EscapeRoomWrapper((char *)"shahar",1));
    ASSERT_NO_THROW(EscapeRoomWrapper((char *)"shahar",60,2,3));
}
void testEscapeRoomWrapperComparison(){
    EscapeRoomWrapper room1=EscapeRoomWrapper((char *)"shahar",
                                DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS);
    EscapeRoomWrapper room2=EscapeRoomWrapper((char *)"shahar",
                               DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS);
    assert(room1==room2);
    EscapeRoomWrapper room3=EscapeRoomWrapper((char *)"amir",
                               DEFAULT_ESCAPE_TIME,10,DEFAULT_MAX_PARTICIPANTS);
    assert(room3!=room1);//diffrent level
    EscapeRoomWrapper room4=EscapeRoomWrapper((char *)"amir",
                               61,10,DEFAULT_MAX_PARTICIPANTS);
    assert(room4!=room3);//diffrent max time
    EscapeRoomWrapper room5=EscapeRoomWrapper((char *)"amir",
                                              61,10,1);
    assert(room4!=room5);//diffrent max_participants
    assert(room3>room1);//better level
    assert(room1<room3);
    assert(room4>room3);//better time
    assert(room3<room4);
    assert(room5>room4);//better divider as max_participants
    assert(room4<room5);

}

void testEscapeRoomWrapperlevel() {
    EscapeRoomWrapper room1=EscapeRoomWrapper((char *)"shahar",
                                DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS);
    assert(room1.level()==1);
}

void testEscapeRoomWrapperrate() {
    EscapeRoomWrapper room1=EscapeRoomWrapper((char *)"shahar",
                                DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS);
    ASSERT_THROWS(EscapeRoomIllegalRateException,room1.rate(-1));
    ASSERT_THROWS(EscapeRoomIllegalRateException,room1.rate(6));
    for(int i=0;i<=5;i++){
        ASSERT_NO_THROW(room1.rate(i));
    }
}
void testEscapeRoomWrapperGet(){
    EscapeRoomWrapper room1=EscapeRoomWrapper((char *)"shahar",
                                DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS);
    assert(room1.getName()=="shahar");
    assert(room1.getMaxTime()==DEFAULT_ESCAPE_TIME);
    room1.rate(3);
    assert(room1.getRate()==3);
    assert(room1.getMaxParticipants()==DEFAULT_MAX_PARTICIPANTS);
}

void testEscapeRoomWrapperEnigmaHandle(){
    /*initilaizition*/
    EscapeRoomWrapper room1=EscapeRoomWrapper((char *)"shahar",
                                DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS);
    set<string> elements;
    elements.insert("Amir");
    elements.insert("Shahar");
    Enigma riddle1("riddle1",EASY_ENIGMA,2,elements);
    /*Tests start */
    ASSERT_THROWS(EscapeRoomNoEnigmasException,room1.getHardestEnigma());
    //TEST empty enigma vector
    room1.addEnigma(riddle1);
    ASSERT_NO_THROW(room1.getHardestEnigma());
    assert(room1.getHardestEnigma()==riddle1);
    Enigma riddle2=Enigma("riddle2",EASY_ENIGMA,2,elements);
    ASSERT_THROWS(EscapeRoomEnigmaNotFoundException,room1.removeEnigma(riddle2));
    vector<Enigma> test_vec;
    test_vec.push_back(riddle2);
    assert(room1.getAllEnigmas()!=test_vec);
    vector<Enigma> test_vec2;
    test_vec2.push_back(riddle1);
    test_vec=room1.getAllEnigmas();
    ASSERT_NO_THROW(room1.removeEnigma(riddle1));
    assert(room1.getAllEnigmas().empty());
}

int main() {
    RUN_TEST(testEscapeRoomWrapperConstructor);
    RUN_TEST(testEscapeRoomWrapperComparison);
    RUN_TEST(testEscapeRoomWrapperlevel);
    RUN_TEST(testEscapeRoomWrapperrate);
    RUN_TEST(testEscapeRoomWrapperGet);
    RUN_TEST(testEscapeRoomWrapperEnigmaHandle);
}