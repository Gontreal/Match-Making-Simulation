#ifndef MALEPLAYER_H
#define MALEPLAYER_H
#include<vector>
#include<iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <stdexcept>

using namespace boost;
using namespace std;
class FemalePlayer;
class Man;
class Woman;

class MalePlayer
{
friend class Woman;
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
#endif

