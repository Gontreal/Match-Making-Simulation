#include"Woman.h"
#include"MalePlayer.h"
#include"Man.h"
#include<string>

Woman::Woman(int id,int appearence,int personality,int wealth,int e_appear,int e_personality,int e_wealth)
        :Person(id,appearence,personality,wealth,e_appear,e_personality,e_wealth),popularity(0)
    {
        loved_one=MalePlayer(Man());
    }
void Woman::eval(const MalePlayer& a ){
        int score_a=a->show_appearence()*expect_appearence+a->show_wealth()*expect_wealth+a->show_personality()*expect_personality;
        int score_b=loved_one->show_appearence()*expect_appearence+loved_one->show_wealth()*expect_wealth+loved_one->show_personality()*expect_personality;
        int alt_score_a=a->show_appearence()+a->show_wealth()+a->show_personality();
        int alt_score_b=loved_one->show_appearence()+loved_one->show_wealth()+loved_one->show_personality();
        if(score_a>score_b)
            loved_one=a;
        else if(score_a==score_b){
            if(alt_score_a>alt_score_b)
                loved_one=a;
            else if(alt_score_a==alt_score_b)
                loved_one=(a->show_id()<loved_one->show_id())?a:loved_one;
        }
}
void Woman::reset()
{
    loved_one=MalePlayer(Man());
    popularity=0;
}
