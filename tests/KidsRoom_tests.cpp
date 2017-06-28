#include "../KidsRoom.h"
#include "../mtmtest.h"
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;
using std::set;
using std::cout;
using std::endl;
void testScaryRoomConstructor() {
    KidsRoom room1((char*)"Room1",DEFAULT_ESCAPE_TIME,1,DEFAULT_MAX_PARTICIPANTS,
    18);

}
void testKidsRoomSetandGetNewAgeLimit(){
    KidsRoom room1((char*)"room1",DEFAULT_ESCAPE_TIME,3,DEFAULT_MAX_PARTICIPANTS,18);
    ASSERT_THROWS(KidsRoomIllegalAgeLimit,room1.setNewAgeLimit(-1));
    assert(room1.getAgeLimit()==18);
    ASSERT_NO_THROW(room1.setNewAgeLimit(0));
    assert(room1.getAgeLimit()==0);
    cout<<room1<<endl;
}

int main() {
    RUN_TEST(testScaryRoomConstructor);
    RUN_TEST(testKidsRoomSetandGetNewAgeLimit);
}