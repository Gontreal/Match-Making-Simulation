#ifndef MAN_H
#define MAN_H
#include<queue>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<functional>
#include<list>
#include "Person.h"
#include "FemalePlayer.h"
#include "MalePlayer.h"
using namespace boost;
using namespace std;
class Woman;
class Person;
class MalePlayer;
class FemalePlayer;
class Man: public Person
{
 friend class MalePlayer;
//friend istream& operator >>(istream& is, Man& w);
public:
    Man(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth)
        :Person(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),dream_girls(comparetype{this->expect_appearence,this->expect_personality,this->expect_wealth})
    {}

    Man(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth,
         const vector<FemalePlayer>& women_pool)
        :Person(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),dream_girls(comparetype{this->expect_appearence,this->expect_personality,this->expect_wealth})
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
#endif
