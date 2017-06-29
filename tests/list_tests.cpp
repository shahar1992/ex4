#include <functional>
#include "../list.h"
#include "../Exceptions.h"
#include "../mtmtest.h"
#include <string>

/**
 * Function object for finding a target integer
 */
class EqualTo {
private:
    std::string target;
public:
    EqualTo(std::string str) : target(str) {}
    bool operator()(const std::string& str) const {
        return str == target;
    }
};


static void IteratorTests(){
    using std::string;
    using mtm::ListExceptions::ElementNotFound;
    List<unsigned int > list;
    list.begin();
    list.insert(1, list.end());
    list.insert(2, list.end());
    list.insert(3, list.end());
    list.insert(4, list.end());
    List<unsigned int >::Iterator it=list.begin();
    unsigned int counter=1;
    /** ------------------Move forward on list----------------------------- */
    for(;it!=list.end();it++){
        ASSERT_TRUE((*(it))==counter);
        counter++;
    }
    /** ------------------end Dereffrence exception-------------------------- */
    ASSERT_THROWS(mtm::ListExceptions::ElementNotFound,(*it));
    --it;
    counter=4;
    /** ------------------Move backwards on list----------------------------- */
    for (;it!=(--(list.begin())); it--){
        ASSERT_TRUE((*(it))==counter);
        counter--;
    }
    List<unsigned int > list2;
    list2.begin();
    list2.insert(1, list2.end());
    list2.insert(2, list2.end());
    list2.insert(3, list2.end());
    list2.insert(4, list2.end());
    List<unsigned int>::Iterator it2=list2.begin();
    /** ------------------check iterator == operator ---------------------------- */
    ASSERT_TRUE(it!=it2);
    ASSERT_TRUE(it2!=it);
    ASSERT_FALSE(it==it2);
    ASSERT_FALSE(it2==it);
    List<unsigned int>::Iterator it3=it;
    ASSERT_TRUE(it==it3);
    ASSERT_FALSE(it3==it2);
}


int main() {
    RUN_TEST(IteratorTests);
    return 0;
}
