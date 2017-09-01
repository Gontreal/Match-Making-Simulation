#include "Woman.h"
#include "Man.h"
#include "FemalePlayer.h"
#include "MalePlayer.h"

MalePlayer::MalePlayer(Man m) {
	man_ptr = boost::make_shared<Man>(m);
}
MalePlayer::MalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth) {
	man_ptr = boost::make_shared<Man>(Man(id, appearence, personality, wealth, e_appear, e_personality, e_wealth));
}
MalePlayer::MalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth,
	const vector<FemalePlayer>& women_pool) {
	auto m = Man(id, appearence, personality, wealth, e_appear, e_personality, e_wealth);
	for (auto i = 0; i != women_pool.size(); ++i) {
		m.new_girl(women_pool[i]);
	}
	man_ptr = boost::make_shared<Man>(m);
}
Man& MalePlayer::operator *() const {
	if (man_ptr)
		return *man_ptr;
	else
        throw runtime_error("OBJECT NOT LOADED.");
}
Man* MalePlayer::operator ->()  const {
	if (man_ptr)
		return &(this->operator*());
	else
		return nullptr;
	//return man_ptr.get();
}
Man& MalePlayer::operator *() {
	if (man_ptr)
		return *man_ptr;
	else
	    throw runtime_error("OBJECT NOT LOADED");

}

Man* MalePlayer::operator ->() {
	if (man_ptr)
		return &(this->operator*());
	else
		return nullptr;
	//return man_ptr.get();
}
boost::shared_ptr<Man> MalePlayer::get() const {
	if (man_ptr)
		return man_ptr;
	else
		cerr << "ILLEGAL OPERATION: GETTING A NULLPTR!" << endl;
	return nullptr;

}
void MalePlayer::set(const boost::shared_ptr<Man>& m) {
	if (man_ptr == nullptr)
		man_ptr = m;
}
int MalePlayer::id() {
	if (man_ptr)
		return man_ptr->id;
	else
		throw runtime_error("Object not loaded.");
}
int MalePlayer::appearence() const {
	if(man_ptr)
		return man_ptr->appearence;
	else
		throw runtime_error("Object not loaded.");
}
int MalePlayer::wealth() const {
	if(man_ptr)
		return man_ptr->wealth;
	else
		throw runtime_error("Object not loaded.");
}
int MalePlayer::personality() const {
	if(man_ptr)
		return man_ptr->personality;
	else
		throw runtime_error("Object not loaded.");
}
bool MalePlayer::is_avail() const {
	if(man_ptr)
		return man_ptr->availability;
	else
		throw runtime_error("Object not loaded.");
}
void MalePlayer::ready() {
	if(man_ptr)
		man_ptr->availability = true;
	else
		throw runtime_error("Object not loaded.");
}
void MalePlayer::chosen() {
	if(man_ptr)
		man_ptr->availability = false;
	else
		throw runtime_error("Object not loaded.");
}
bool MalePlayer::expect_check() {
	if (man_ptr)
		return man_ptr->expect_appearence + man_ptr->expect_personality + man_ptr->expect_wealth == 100;
	else
		throw runtime_error("Object not loaded.");

}
void MalePlayer::meet_women(const vector<FemalePlayer>& girl)
{
	if (man_ptr)
		man_ptr->build_heap(girl);
	else
		throw runtime_error("Object not loaded.");

}
//for just add one new girl into the heap
void MalePlayer::new_girl(const FemalePlayer& girl)
{
	if (man_ptr)
		man_ptr->dream_girls.push(girl);
	else
		throw runtime_error("Object not loaded.");

}
//return the max
FemalePlayer MalePlayer::dream_girl()
{
	if (man_ptr)
		return man_ptr->dream_girl();
	else
		throw runtime_error("Object not loaded.");

}
void MalePlayer::restore()
{
	if (man_ptr)
		return man_ptr->restore_dream_girls();
	else
		throw runtime_error("Object not loaded.");

}
size_t MalePlayer::q_size() const {
	if (man_ptr)
		return man_ptr->dream_girls.size();
	else
		throw runtime_error("Object not loaded.");

}
