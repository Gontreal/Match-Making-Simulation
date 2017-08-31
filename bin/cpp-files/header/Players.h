#ifndef PLAYERS_H
#define PLAYERS_H
#include<unordered_map>
#include<vector>
#include<iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <stdexcept>
//#include"charactors.h"

using namespace boost;
using namespace std;
class FemalePlayer;
class Man;
class woman;
class MalePlayer
{
friend class woman;
friend class Match;
public:
	//constructors
	MalePlayer(Man m);

	MalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth);

	MalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth,
		const vector<FemalePlayer>& women_pool); 
	MalePlayer(boost::shared_ptr<Man> w) :man_ptr(w) {}
	MalePlayer()=default;
	//copy&assign
	MalePlayer(const MalePlayer& m) :man_ptr(m.man_ptr) {}
	MalePlayer& operator =(const MalePlayer& m) {
		man_ptr = m.man_ptr;
		return *this;
	}
	
	//interface method
	boost::shared_ptr<Man> get() const;
	void set(const boost::shared_ptr<Man>& m);
	void free() { man_ptr=nullptr; }
	bool is_loaded() { return man_ptr ? true : false; }
	//Man interface method,once it's been loaded
	int id();
	int appearence() const;
	int wealth() const;
	int personality() const;
	bool is_avail() const;
	void ready();
	void chosen();
	bool expect_check();
	void meet_women(const vector<FemalePlayer>& girl);
	//for just add one new girl into the heap
	void new_girl(const FemalePlayer& girl);
	//return the max
	FemalePlayer dream_girl();
	void restore();	
	size_t q_size() const;
private:
	boost::shared_ptr<Man> man_ptr=nullptr;
	//ptr operations
	Man& operator *() const;
	Man* operator ->()  const;
	Man& operator *();
	Man* operator ->();
};

class FemalePlayer
{
friend class Man;
friend class Match;
public:
	//constructors
	FemalePlayer(woman m);
	FemalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth);
	FemalePlayer(boost::shared_ptr<woman> w) :woman_ptr(w) {}
	FemalePlayer()=default;
	//copy&assign
	FemalePlayer(const FemalePlayer& w) :woman_ptr(w.woman_ptr) {}
	FemalePlayer& operator =(const FemalePlayer& w) {
		woman_ptr = w.woman_ptr;
		return *this;
	}
	//interface method
	boost::shared_ptr<woman> get() const;
	void set(const boost::shared_ptr<woman>& w);
	void free() { woman_ptr=nullptr; }
	bool is_loaded() { return woman_ptr ? true : false; }
	//woman interface method,once it's been loaded
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
	boost::shared_ptr<woman> woman_ptr=nullptr;
	woman& operator *() const;

	woman* operator ->()const;
	woman& operator *();

	woman* operator ->();
};
#endif