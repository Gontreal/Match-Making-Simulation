#ifndef PERSON_H
#define PERSON_H
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include<iostream>
using namespace boost;
using namespace std;
//consider it as a general "human" without regarding of sex
class Person
{
public:
    Person(int id,int appearence,int personality,int wealth,int e_face,int e_character,int e_wealth)
    :id(id),appearence(appearence),personality(personality),wealth(wealth),expect_appearence(e_face),
    expect_personality(e_character),expect_wealth(e_wealth) { availability=true;}
    Person()=default;
    virtual ~Person() {}
   int show_id() {return id;}
    int show_appearence() const {return appearence;}
    int show_wealth() const {return wealth;}
    int show_personality() const {return personality;}
    bool is_avail() const {return availability;}
	void ready() { availability = true; }
	void chosen() { availability = false; }
	bool expect_check() {
		return expect_appearence + expect_personality + expect_wealth == 100;
	}
protected:
    int id=101;
    int appearence=0;
    int personality=0;
    int wealth=0;


    int expect_appearence=0;
    int expect_personality=0;
    int expect_wealth=0;
    bool availability=true;
};
#endif


