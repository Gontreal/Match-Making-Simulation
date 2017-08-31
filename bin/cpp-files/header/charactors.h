#ifndef CHARACTORS_H
#define CHARACTORS_H
#include<queue>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<functional>
#include<list>
#include"Players.h"
using namespace boost;
using namespace std;
//consider it as a general "human" without regarding of sex
class base
{
friend class Match;
public:
    base(int id,int appearence,int personality,int wealth,int e_face,int e_character,int e_wealth)
    :id(id),appearence(appearence),personality(personality),wealth(wealth),expect_appearence(e_face),
    expect_personality(e_character),expect_wealth(e_wealth) { availability=true;}
    base()=default;
    virtual ~base() {}
	/*
	//copy constructor
	base(const base& b) {
	id = b.id;
	appearence = b.appearence;
	wealth = b.wealth;
	personality = b.personality;
	expect_appearence = b.expect_appearence;
	expect_personality = b.expect_personality;
	expect_wealth = b.expect_wealth;
	}

	//assign op
	base& operator =(base b) {
	swap(*this,b);
	return *this;
	}
	*/
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


class woman;
class MalePlayer;
class FemalePlayer;
class Man: public base
{
//friend class Match;
friend class MalePlayer;
friend istream& operator >>(istream& is, Man& w);
public:
    Man(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth)
        :base(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),dream_girls(comparetype{this->expect_appearence,this->expect_personality,this->expect_wealth})
    {}

    Man(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth,
         const vector<FemalePlayer>& women_pool)
        :base(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),dream_girls(comparetype{this->expect_appearence,this->expect_personality,this->expect_wealth})
    {
        build_heap(women_pool);
    }

    Man();

    //for batch initializing the max heap
    void meet_women(const vector<FemalePlayer>& girl) { build_heap(girl);}
    //for just add one new girl into the heap
    void new_girl(const FemalePlayer& girl)    {dream_girls.push(girl);}

    ~Man() {}
    //return the max
	FemalePlayer dream_girl();
	void restore()
	{
		restore_dream_girls();
	}
	size_t q_size() const{
		return dream_girls.size();
	}
private:
	// the custom compare method
    struct comparetype{
		//comparetype(int e_appearence,int e_personnality,int e_wealth);
		bool operator () (const FemalePlayer& a,  const FemalePlayer& b);
			//return m->Mycompare(a,b);
		int expect_appearence;
		int expect_personality;
		int expect_wealth;
    };
   // bool Mycompare(const shared_ptr<woman>& a,  const shared_ptr<woman>& b);
    // main max heap data structrue that return the most interested girl according the
    //the rating method of the spec.
    //PAY ATTENTION TO HOW YOU CONSTRUCT THE COMPARETYPE CLASS
    priority_queue<FemalePlayer,vector<FemalePlayer>,comparetype>
    dream_girls;
    //the recycle bin for the restore process in match class to collect the dream girl
    //once it is removed from the heap.
    //POTENTIAL OPTIMIZATION:it might be optimized by being used in the matching making process
    //because it is collected in sorted order and it would be a waste to just add them back to the heap
    //every time. So I defind it as linked list rather than stack for further update.
    //the main problem is when add a new female main characror, it main need some handling as to wether
    //add it into the heap or the already sorted list and remove it after the match.
    list<FemalePlayer> girl_bin;
    // add the girls back
    void restore_dream_girls();
    //fucntion to build the dream girl heap
    void build_heap(const vector<FemalePlayer> &);
};



class woman : public base
{
friend class FemalePlayer;
//friend class Match;
friend istream& operator >>(istream& is, woman& w);

public:
	woman(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth)
        :base(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),popularity(0)
    {}
    woman()=default;
	~woman(){}


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



#endif // CHARACTORS_H
