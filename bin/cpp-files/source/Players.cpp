#include"charactors.h"
#include"Players.h"

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
		cerr << "ILLEGAL OPERATION:DERENFEENCING A NULL OBJECT!" << endl;
	return Man();
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
		cerr << "ILLEGAL OPERATION:DERENFEENCING A NULL OBJECT!" << endl;
	return Man();
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

//Female Player's methods
FemalePlayer::FemalePlayer(woman w) {
	woman_ptr = boost::make_shared<woman>(w);
}
FemalePlayer::FemalePlayer(int id, int appearence, int personality, int wealth, int e_appear, int e_personality, int e_wealth) {
	woman_ptr = boost::make_shared<woman>(woman(id, appearence, personality, wealth, e_appear, e_personality, e_wealth));
}
//FemalePlayer::FemalePlayer() {
//	woman_ptr = boost::make_shared<woman>(woman());
//}
woman& FemalePlayer::operator *() const {
	if (woman_ptr)
		return *woman_ptr;
	else
		cerr << "ILLEGAL OPERATION:DERENFEENCING A NULL OBJECT!" << endl;
	return woman();
}

woman* FemalePlayer::operator ->()const {
	if (woman_ptr)
		return &this->operator*();
	else
		return nullptr;
	//return woman_ptr.get();
}
woman& FemalePlayer::operator *() {
	if (woman_ptr)
		return *woman_ptr;
	else
		cerr << "ILLEGAL OPERATION:DERENFEENCING A NULL OBJECT!" << endl;
	return woman();
}

woman* FemalePlayer::operator ->() {
	if (woman_ptr)
		return &this->operator*();
	else
		return nullptr;
	//return woman_ptr.get();
}

boost::shared_ptr<woman> FemalePlayer::get() const {
	if (woman_ptr)
		return woman_ptr;
	else
		cerr << "ILLEGAL OPERATION: GETTING A NULLPTR!" << endl;
	return nullptr;
}
void FemalePlayer::set(const boost::shared_ptr<woman>& w) {
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