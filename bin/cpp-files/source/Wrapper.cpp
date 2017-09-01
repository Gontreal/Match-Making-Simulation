#include "Person.h"
#include <boost/python.hpp>
#include<boost/python/register_ptr_to_python.hpp>
#include "Man.h"
#include "Man.cpp"
#include "Woman.h"
#include "Woman.cpp"
#include "MalePlayer.h"
#include "MalePlayer.cpp"
#include "FemalePlayer.h"
#include "FemalePlayer.cpp"
using namespace boost;
//using namespace std;
using namespace boost::python;

BOOST_PYTHON_MODULE(charactors)
{
    using namespace boost::python;
    class_<Person>("Person",
         init<int,int,int,int,int,int,int>())
        .def(init<>())
        //.def("id",&Person::id)
        //.def("appearence",&Person::appearence)
       // .def("personality",&Person::personality)
       // .def("wealth",&Person::wealth)
       // .def("expect_appearence",&Person::expect_appearence)
       // .def("expect_personality",&Person::expect_personality)
       // .def("expect_wealth",&Person::expect_wealth)
       // .def("availability",&Person::availability)
        .add_property("id",&Person::show_id)
        .add_property("appearence",&Person::show_appearence)
        .add_property("wealth",&Person::show_wealth)
        .add_property("personality",&Person::show_personality)
        .add_property("availability",&Person::is_avail)
        .def("ready",&Person::ready)
        .def("chosen",&Person::chosen)
        .def("expect_check",&Person::expect_check)
    ;
    class_<Man,bases<Person> >("Man",
            init<int,int,int,int,int,int,int>())
        .def(init<int,int,int,int,int,int,int,const vector<FemalePlayer>&>())
        .def(init<>())
        .def("meet_women",&Man::meet_women)
        .def("new_girl",&Man::new_girl)
        .def("dream_girl",&Man::dream_girl)
        .def("restore",&Man::restore)
        .def("q_size",&Man::q_size)
    ;
    class_<Woman,bases<Person> >("Woman",
            init<int,int,int,int,int,int,int>())
        .def(init<>())
        .def("check_popularity",&Woman::check_popularity)
        .def("meet",&Woman::meet)
        .def("reset",&Woman::reset)
        .def("she_loves",&Woman::she_loves)
        .def("more_popular",&Woman::more_popular)
        .def("fell_love",&Woman::fell_love)
    ;
    class_<FemalePlayer>("FemalePlayer",
            init<int,int,int,int,int,int,int>())
        .def(init<Woman>() )
        .def(init<boost::shared_ptr<Woman>>())
        .def(init<>())
        .def(init<const FemalePlayer&>())
        //assign operator not exported use alternative
        .add_property("woman_ptr",&FemalePlayer::get,&FemalePlayer::set)
        .def("free",&FemalePlayer::free)
        .def("is_loaded",&FemalePlayer::is_loaded)
        .def("id",&FemalePlayer::id)
        .def("appearence",&FemalePlayer::appearence)
        .def("personality",&FemalePlayer::personality)
        .def("wealth",&FemalePlayer::wealth)
        .def("is_avail",&FemalePlayer::is_avail)
        .def("ready",&FemalePlayer::ready)
        .def("chosen",&FemalePlayer::chosen)
        .def("expect_check",&FemalePlayer::expect_check)
        .def("check_popularity",&FemalePlayer::check_popularity)
        .def("meet",&FemalePlayer::meet)
        .def("reset",&FemalePlayer::reset)
        .def("she_loves",&FemalePlayer::she_loves)
        .def("more_popular",&FemalePlayer::more_popular)
        .def("fell_love",&FemalePlayer::fell_love)

    ;
    class_<MalePlayer>("MalePlayer",
            init<int,int,int,int,int,int,int>())
        .def(init<int,int,int,int,int,int,int,const vector<FemalePlayer>&>())
        .def(init<Man>() )
        .def(init<boost::shared_ptr<Man>>())
        .def(init<>())
        .def(init<const MalePlayer&>())
        //assign operator not exported use alternative
        .add_property("man_ptr",&MalePlayer::get,&MalePlayer::set)
        .def("free",&MalePlayer::free)
        .def("is_loaded",&MalePlayer::is_loaded)
        .def("id",&MalePlayer::id)
        .def("appearence",&MalePlayer::appearence)
        .def("personality",&MalePlayer::personality)
        .def("wealth",&MalePlayer::wealth)
        .def("is_avail",&MalePlayer::is_avail)
        .def("ready",&MalePlayer::ready)
        .def("chosen",&MalePlayer::chosen)
        .def("expect_check",&MalePlayer::expect_check)
        .def("meet_women",&MalePlayer::meet_women)
        .def("new_girl",&MalePlayer::new_girl)
        .def("dream_girl",&MalePlayer::dream_girl)
        .def("restore",&MalePlayer::restore)
        .def("q_size",&MalePlayer::q_size)
    ;
    //register_ptr_to_python<boost::shared_ptr<Woman>>();


}

