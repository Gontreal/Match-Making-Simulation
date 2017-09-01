#ifndef FEMALEPLAYER_H
#define FEMALEPLAYER_H
#include<vector>
#include<iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <stdexcept>

using namespace boost;
using namespace std;

class MalePlayer;
//class Man;
class Woman;
class FemalePlayer
{
friend class Man;
friend class Match;
public:
	//constructors
	FemalePlayer(Woman m);
	FemalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth);
	FemalePlayer(boost::shared_ptr<Woman> w) :woman_ptr(w) {}
	FemalePlayer()=default;
	//copy&assign
	FemalePlayer(const FemalePlayer& w) :woman_ptr(w.woman_ptr) {}
	FemalePlayer& operator =(const FemalePlayer& w) {
		woman_ptr = w.woman_ptr;
		return *this;
	}
	//interface method
	boost::shared_ptr<Woman> get() const;
	void set(const boost::shared_ptr<Woman>& w);
	void free() { woman_ptr=nullptr; }
	bool is_loaded() { return woman_ptr ? true : false; }
	//Woman interface method,once it's been loaded
	int id();
	int appearence() const;
	int wealth() const;
	int personality() const;
	bool is_avail() const;
	void ready();
	void chosen();
	bool expect_check();
	int check_popularity() const;
	//evaluation of the male player who invite this girl according to the spec.
	void meet(const MalePlayer& a);
	//reset after each round
	void reset(const MalePlayer& dummy);
	MalePlayer she_loves();
	void more_popular();
	void fell_love(const MalePlayer& m);

private:
	boost::shared_ptr<Woman> woman_ptr=nullptr;
	Woman& operator *() const;

	Woman* operator ->()const;
	Woman& operator *();

	Woman* operator ->();
};



#endif
