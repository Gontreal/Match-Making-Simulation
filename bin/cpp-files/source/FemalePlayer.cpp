#include "Man.h"
#include"Woman.h"
#include"FemalePlayer.h"
#include"MalePlayer.h"

//Female Player's methods
FemalePlayer::FemalePlayer(Woman w) {

   woman_ptr = boost::make_shared<Woman>(w);
    // woman_ptr=new *w;
}
FemalePlayer::FemalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth) {
	woman_ptr = boost::make_shared<Woman>(Woman(id, appearence, personality, wealth, e_appear, e_personality, e_wealth));
}
//FemalePlayer::FemalePlayer() {
//	woman_ptr = boost::make_shared<Woman>(Woman());
//}
Woman& FemalePlayer::operator *() const {
	if (woman_ptr)
		return *woman_ptr;
	else
        throw runtime_error("OBJECT NOT LOADED.");
}

Woman* FemalePlayer::operator ->()const {
	if (woman_ptr)
		return &this->operator*();
	else
		return nullptr;
	//return woman_ptr.get();
}
Woman& FemalePlayer::operator *() {
	if (woman_ptr)
		return *woman_ptr;
	else
        throw runtime_error("OBJECT NOT LOADED.");
}

Woman* FemalePlayer::operator ->() {
	if (woman_ptr)
		return &this->operator*();
	else
		return nullptr;
	//return woman_ptr.get();
}

boost::shared_ptr<Woman> FemalePlayer::get() const {
	if (woman_ptr)
		return woman_ptr;
	else
		cerr << "ILLEGAL OPERATION: GETTING A NULLPTR!" << endl;
	return nullptr;
}
void FemalePlayer::set(const boost::shared_ptr<Woman>& w) {
	if (woman_ptr == nullptr)
		woman_ptr = w;
}
int FemalePlayer::id() {
	if (woman_ptr)
		return woman_ptr->id;
	else
		throw runtime_error("Object not loaded.");
}
int FemalePlayer::appearence() const {
	if (woman_ptr)
		return woman_ptr->appearence;
	else
		throw runtime_error("Object not loaded.");
}
int FemalePlayer::wealth() const {
	if (woman_ptr)
		return woman_ptr->wealth;
	else
		throw runtime_error("Object not loaded.");
}
int FemalePlayer::personality() const {
	if (woman_ptr)
		return woman_ptr->personality;
	else
		throw runtime_error("Object not loaded.");
}
bool FemalePlayer::is_avail() const {
	if (woman_ptr)
		return woman_ptr->availability;
	else
		throw runtime_error("Object not loaded.");
}
void FemalePlayer::ready() {
	if (woman_ptr)
		woman_ptr->availability = true;
	else
		throw runtime_error("Object not loaded.");
}
void FemalePlayer::chosen() {
	if (woman_ptr)
		woman_ptr->availability = false;
	else
		throw runtime_error("Object not loaded.");
}
bool FemalePlayer::expect_check() {
	if (woman_ptr)
		return woman_ptr->expect_appearence + woman_ptr->expect_personality + woman_ptr->expect_wealth == 100;
	else
		throw runtime_error("Object not loaded.");

}
int FemalePlayer::check_popularity() const
{
	if (woman_ptr)
		return woman_ptr->popularity;
	else
		throw runtime_error("Object not loaded.");
}
//evaluation of the male player who invite this girl according to the spec.
void FemalePlayer::meet(const MalePlayer& a)
{
	if (woman_ptr)
		woman_ptr->eval(a);
	else
		throw runtime_error("Object not loaded.");
}
//reset after each round
void FemalePlayer::reset(const MalePlayer& dummy)
{
	if (woman_ptr) {
		woman_ptr->popularity = 0;
		woman_ptr->loved_one = dummy;
	}
	else
		throw runtime_error("Object not loaded.");
}

void FemalePlayer::more_popular()
{
	if (woman_ptr)
		++(woman_ptr->popularity);
	else
		throw runtime_error("Object not loaded.");

}
void FemalePlayer::fell_love(const MalePlayer& m)
{
	if (woman_ptr)
		woman_ptr->loved_one = m;
	else
		throw runtime_error("Object not loaded.");

}
MalePlayer FemalePlayer::she_loves()
{
	if (woman_ptr)
		return woman_ptr->loved_one;
	else
		throw runtime_error("Object not loaded.");

}


