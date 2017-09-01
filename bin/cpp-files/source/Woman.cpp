#include"Woman.h"
#include"MalePlayer.h"
#include"Man.h"
#include<string>

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
