#include "../ScaryRoom.h"
#include "../mtmtest.h"
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;
using std::set;
using std::cout;
void testScaryRoomConstructor() {
    ScaryRoom room1((char*)"room1",DEFAULT_ESCAPE_TIME,3,DEFAULT_MAX_PARTICIPANTS,18,2);
}
void testScaryRoomSetandGetNewAgeLimit(){
    ScaryRoom room1((char*)"room1",DEFAULT_ESCAPE_TIME,3,DEFAULT_MAX_PARTICIPANTS,18,2);
    ASSERT_THROWS(ScaryRoomIllegalAgeLimit,room1.setNewAgeLimit(-1));
    assert(room1.getAgeLimit()==18);
    ASSERT_NO_THROW(room1.setNewAgeLimit(0));
    assert(room1.getAgeLimit()==0);
    cout<<room1;
}

int main() {
    RUN_TEST(testScaryRoomConstructor);
    RUN_TEST(testScaryRoomSetandGetNewAgeLimit);
}