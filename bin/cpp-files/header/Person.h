#ifndef PERSON_H
#define PERSON_H
//#include<queue>
//#include<memory>
//#include<vector>
//#include<iostream>
//#include<unordered_map>
//#include<functional>
//#include<list>
using namespace std;
//consider it as a general "human" without regarding of sex
class Person
{
friend class Match;
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

#endif // PERSON_H
