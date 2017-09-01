#include"Man.h"
#include "Woman.h"
#include"Person.h"
#include"FemalePlayer.h"
#include"MalePlayer.h"
#include<string>
FemalePlayer Man::dream_girl()  {
        if(dream_girls.empty()){
            cerr<<"I need to know all the girls first"<<endl;
        }

		FemalePlayer a=dream_girls.top();
        while(!(a->is_avail())){
            if(dream_girls.empty()){
                cerr<<"No one fucking wants you!!"<<endl;
            }
            if(a->show_id()!=-1)
                girl_bin.push_back(a);
            dream_girls.pop();
            a=dream_girls.top();
        }
        return a;

    }
    void Man::restore_dream_girls(){
        if(!girl_bin.empty()){
            for(auto iter=girl_bin.begin();iter!=girl_bin.end();++iter){

                dream_girls.push(*iter);

            }
        }
        girl_bin.clear();

    }


    Man::Man():Person(){}


    //carefult it's a max_heap or min_heap
    bool Man::comparetype::operator()(const FemalePlayer& a,  const FemalePlayer& b){
		//cout << a->show_id() << endl;
		int score_a=(a->show_personality()*expect_personality)+(a->show_appearence()*expect_appearence)+(a->show_wealth()*expect_wealth);
        int score_b=(b->show_personality()*expect_personality)+(b->show_appearence()*expect_appearence)+(b->show_wealth()*expect_wealth);
        int alt_score_a=a->show_appearence()+a->show_wealth()+a->show_personality();
        int alt_score_b=b->show_appearence()+b->show_wealth()+b->show_personality();
        // cout<<score_a<<"!"<<endl;
        // cout<<score_b<<endl;
        // cout<<a->show_personality()<<"!!!"<<endl;
        //cout<<expect_personality<<"@@@"<<expect_appearence<<"@@@"<<expect_wealth<<endl;
        if(score_a<score_b){

            return true;
        }
        else if(score_a==score_b){
            if(alt_score_a<alt_score_b){

                return true;
            }
            else if(alt_score_a==alt_score_b){

                return (a->show_id()>b->show_id())? true:false;
            }
            else{

                return false;
            }
        }
        else{

            return false;
        }

 }

    void Man::build_heap(const vector<FemalePlayer>& women_pool){
        for(auto w:women_pool)
                dream_girls.push(w);
       // cout<<"No. "<<id<<" has met all girls."<<endl;

    }

