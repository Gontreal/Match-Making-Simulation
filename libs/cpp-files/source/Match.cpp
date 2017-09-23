#include "Match.h"

void Match::find_queen(const FemalePlayer& a){
    int pa=a->check_popularity();
    int pb=queen->check_popularity();
    int alt_a=a->show_appearence()+a->show_personality()+a->show_wealth();
    int alt_q=queen->show_appearence()+queen->show_personality()+queen->show_wealth();
    if(pa>pb)
        queen=a;
    else if(pa==pb){
        if(alt_a>alt_q)
            queen=a;
        else if(alt_a==alt_q)
            queen= a->show_id()<queen->show_id()?a:queen;
    }
}

void Match::initializing(ifstream& men_list,ifstream& women_list){
	cout << "Initialization begin... " << endl;
	MalePlayer mdummy=MalePlayer(Man());
	if (mdummy->show_id() != 101)
		cout << "WTF" << endl;
	m_list.reserve(100);
	w_list.reserve(100);
	for (auto i = 0; i != 100; ++i) {
		m_list.push_back(MalePlayer());
		w_list.push_back(FemalePlayer());
	}
	cout << "Database initialization Completed" << endl;
    while(women_list){
        woman w;
        women_list>>w;
		FemalePlayer fp(w);
        //cout<<w.appearence<<" "<<w.personality<<" "<<w.wealth<<endl;
        //cout<<w.loved_one->show_id()<<endl;
        if(fp->show_id()!=101){
            fp->fell_love(mdummy);
			//auto player = w.ready();
            //[w.show_id()]=boost::make_shared<woman>(w);
			w_list[fp->show_id()]=fp;
			//cout << "Female Player No." << fp->show_id() << " loaded" << endl;
		}
    }
	//cout << "Female player Initialization complete. " << endl;
    while(men_list){
        Man m;
        men_list>>m;
		MalePlayer mp(m);
        //cout<<m.appearence<<" "<<m.personality<<" "<<m.wealth<<endl;
        //cout<<"Male No. "<<m.show_id()<<" has met all the girls."<<endl;
		//vector<FemalePlayer> w_list;
		//w_list.reserve(women_pool.size());
		//for (auto w : women_pool) {
		//	w_list.push_back(FemalePlayer(w.second));
		//}
		
        if(mp->show_id()!=101){
			
            mp->meet_women(w_list);
            //cout<<m.dream_girls.size()<<endl;
			//auto player = m.ready();
            //men_pool[m.show_id()]= boost::make_shared<Man>(m);
			m_list[mp->show_id()]=mp;
        }
    }
	cout << "Initialization checking. " << endl;
	for (auto m = 0; m != m_list.size();++m) {
		if (m_list[m]->show_id() != m) {
			cout << "Initialization Failed" << endl;
			break;
		}
	}
	for (auto w = 0; w != w_list.size(); ++w) {
		if (w_list[w]->show_id() != w) {
			cout << "Initialization Failed" << endl;
			break;
		}
	}
    cout<<"Initialization complete. "<<endl;
}

void Match::make_invitations() {
	if (MaleMain.is_loaded()) {
		
		FemalePlayer w = MaleMain.dream_girl();
		w.meet(MaleMain);
		w.more_popular();
		find_queen(w);
		
	}
    for(auto a:m_list ){
		if (a.is_avail()&&a.get()) {
			FemalePlayer w = a.dream_girl();
			w.meet(a);
			w.more_popular();
			find_queen(w);
		}
		
    }
    //cout<<queen->show_id()<<endl;
}

void Match::reset_women_pool(){
	MalePlayer dummy=MalePlayer(Man());
    //int w_size =women_pool.size();
    for(auto a:w_list){
       // cout<<(a.second)->show_id()<<endl;
        a->reset(dummy);
    }
	if (FemaleMain.is_loaded())
		FemaleMain->reset(dummy);
    queen=FemalePlayer(woman());
}

bool Match::matching_n_reset(){
	MalePlayer the_one=queen->she_loves();
    if(queen->show_id()==-1){
        cout<<"Congratulation: you just found your man. Male:"<<the_one->show_id()<<endl;
        queen->chosen();
        //women_pool.erase(-1);
		FemaleMain.free();
        return false;
    }
    if(the_one->show_id()==-1){
        cout<<"Congratulation: you just found your woman. Female:"<<queen->show_id()<<endl;
        //men_pool.erase(-1);
		MaleMain.free();
        return false;
    }
    // this is to remove the couple from futher matching
    queen->chosen();
    the_one->chosen();
    //cout<<the_one->show_id()<<" "<<queen->show_id()<<" : "<<queen->check_popularity()<<endl;

    missing_male_bin.push(the_one->show_id());
    //men_pool.erase(the_one->show_id());

    //if(m_list[the_one->show_id()])
     //   cout<<"erase failed."<<endl;

    reset_women_pool();
    return true;
}

 void Match::add_player(istream& is){
    string wealth;
    string appearence;
    string personality;
    string expect_wealth;
    string expect_appearence;
    string expect_personality;
    string sex;
    getline(is,sex,',');
    getline(is,appearence,',');
    getline(is,personality,',');
    getline(is,wealth,',');
    getline(is,expect_appearence,',');
    getline(is,expect_personality,',');
    getline(is,expect_wealth);
    bool the_sex=stoi(sex);
    if(is){
    // the basic idea is to remove a random player in the pool, store it in the missing ptr and add the player in the -1 position
        if(the_sex){
            //int id=rand()%100;
            //For debug, id=15 or don't erase the random player.
            int id=15;
            //missing_male_bin.push(men_pool[id]);
            //men_pool.erase(id);
			m_list[id].chosen();
			//boost::shared_ptr<Man> b= boost::make_shared<Man>(Man(-1,stoi(appearence),stoi(personality),stoi(wealth),
             //                                      stoi(expect_appearence),stoi(expect_personality),stoi(expect_wealth)));
			auto b = MalePlayer(-1, stoi(appearence), stoi(personality), stoi(wealth),
				stoi(expect_appearence), stoi(expect_personality), stoi(expect_wealth));
            //men_pool[-1]=b;
			MaleMain = b;

            MaleMain.meet_women(w_list);
            if(MaleMain->q_size()==100)
                cout<< "Player "<<" met all the girls."<<endl;
            if(MaleMain.expect_check())
                cout<<"Player "<<" created. "<<endl;
            else
                cout<<"Player's data is corrupted"<<endl;

        }
        else{
            //int id=rand()%100;
            //for debug id=99
            int id=99;
            w_list[id]->chosen();
			//boost::shared_ptr<woman> b= boost::make_shared<woman>(woman(-1,stoi(appearence),stoi(personality),stoi(wealth),
            //                                       stoi(expect_appearence),stoi(expect_personality),stoi(expect_wealth)));
			auto b = FemalePlayer(-1, stoi(appearence), stoi(personality), stoi(wealth),
				stoi(expect_appearence), stoi(expect_personality), stoi(expect_wealth));
			FemaleMain=b;

            //b->loved_one= boost::make_shared<Man>(Man());
			FemaleMain ->fell_love( MalePlayer(Man()));
            //cout<<women_pool[id]->show_id()<<endl;

            //updata men's dream girl list
            for(auto &a: m_list)
                a->new_girl(FemaleMain);
            //if(men_pool[0]->dream_girls.size()==101)
            cout<<"Player is introduced. "<<endl;

            if(FemaleMain.expect_check())
                cout<<"Player created. "<<endl;
            else
                cout<<"Player's data is corrupted"<<endl;
        }
    }
    else{
        cout<<"Failed to add player into the pool";
    }
}

void Match::restore(){
    for(auto &a:w_list){
        if(a->show_id()!=-1)
            a->ready();
        //women_pool[i]->reset(make_shared<Man>(Man()));
    }
	for (auto &a : m_list) {
		if (a->show_id() != -1)
			a->ready();
		a->restore();
	}
	
	while(!missing_male_bin.empty()){
		//auto a=missing_male_bin.top();
		m_list[missing_male_bin.top()]->ready();
		missing_male_bin.pop();
	}
	if (missing_male_bin.size())
		cout << "Restore failed." << m_list.size() << endl;
	else{
		for(auto &a:m_list){
			a->restore();
		}
	}	
    reset_women_pool();
	
    cout<<"*****************************"<<endl;

}
