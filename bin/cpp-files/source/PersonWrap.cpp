#include "Person.h"
#include <boost/python.hpp>
using namespace boost;
//using namespace std;
using namespace boost::python;

BOOST_PYTHON_MODULE(charactors)
{
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
    ;
}

