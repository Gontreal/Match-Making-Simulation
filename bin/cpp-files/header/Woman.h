#ifndef WOMAN_H
#define WOMAN_H
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "Person.h"
#include "FemalePlayer.h"
#include "MalePlayer.h"
using namespace boost;
using namespace std;
class Person;
class MalePlayer;
class FemalePlayer;

class Woman : public Person
{
friend class FemalePlayer;
//friend class Match;

public:
	Woman(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth)
        :Person(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),popularity(0)
    {}
    Woman()=default;
	~Woman(){}

	int check_popularity() const {return popularity;}
	//evaluation of the male player who invite this girl according to the spec.
	void meet(const MalePlayer& a) {eval(a);}
	//reset after each round
	void reset( const MalePlayer& dummy)  {popularity=0;loved_one=dummy;}
	MalePlayer she_loves() { return loved_one; }
	void more_popular() { ++popularity; }
	void fell_love(const MalePlayer& m) { loved_one = m; }
	//void reset_popularity() { popularity = 0; }
private:
    //number of male who invite this girl
    int popularity=0;
    //the one that match this girl's requirement best
	MalePlayer loved_one;
    //the process to select "the one"
	void eval(const MalePlayer& a );

};



#endif
