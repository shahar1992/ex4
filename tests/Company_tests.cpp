#include "../Company.h"
#include "../mtmtest.h"
#include <set>
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;
using std::set;
using std::cout;
using std::endl;
void testCompanyConstructor() {
    Company company1("Company1","04-1111111");
    company1.createRoom((char*)"C1Room1",DEFAULT_ESCAPE_TIME,1,
                        DEFAULT_MAX_PARTICIPANTS);
    company1.createScaryRoom((char*)"C1ScaryRoom1",DEFAULT_ESCAPE_TIME,1,
                             DEFAULT_MAX_PARTICIPANTS,18,0);
    company1.createKidsRoom((char*)"C1KidsRoom1",90,5,4,5);
    set<EscapeRoomWrapper*> C1rooms=company1.getAllRooms();
    for(set<EscapeRoomWrapper*>::iterator i=C1rooms.begin();i!=C1rooms.end();
            ++i){
        cout<<**i<<endl;
    }
}

void testCompanyRemovales() {
    Company company1("Company1","04-1111111");
    company1.createRoom((char*)"C1Room1",DEFAULT_ESCAPE_TIME,1,
                        DEFAULT_MAX_PARTICIPANTS);
    company1.createScaryRoom((char*)"C1ScaryRoom1",DEFAULT_ESCAPE_TIME,1,
                             DEFAULT_MAX_PARTICIPANTS,18,0);
    company1.createKidsRoom((char*)"C1KidsRoom1",90,5,4,5);
    set<EscapeRoomWrapper*> C1rooms=company1.getAllRooms();
    //Start Of Test
    for(set<EscapeRoomWrapper*>::iterator i=C1rooms.begin();i!=C1rooms.end();
        ++i) {
        company1.removeRoom(**i);
    }

}

int main() {
    RUN_TEST(testCompanyConstructor);
    RUN_TEST(testCompanyRemovales);
}