#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
using namespace std;

string name, respawn, p2name;
int health, hunger, thirst, energy, p2health, p2hunger, p2thirst, p2energy;
bool alive, p2;

void displayStats(){
	if (health<0){
		health=0;
	}
	if (hunger<0){
		hunger=0;
	}
	if (thirst<0){
		thirst=0;
	}
	if (energy<0){
		energy=0;
	}
	cout<<"Health: "<<health<<endl<<"Hunger: "<<hunger<<endl<<"Thirst: "<<thirst<<endl<<"Energy: "<<energy<<endl;

	if (p2==true) {
		if (p2health<0){
			p2health=0;
		}
		if (p2hunger<0){
			p2hunger=0;
		}
		if (p2thirst<0){
			p2thirst=0;
		}
		if (p2energy<0){
			p2energy=0;
		}
		cout<<p2name<<"'s Health: "<<p2health<<endl<<p2name<<"'s Hunger: "<<p2hunger<<endl<<p2name<<"'s Thirst: "<<p2thirst<<endl<<p2name<<"'s Energy: "<<p2energy<<endl;
	}
}

void findP2() {
	string friends;
	if (p2==false){
		int find;
		find=rand()%7;
		if (find==1){
			cout<<name<<" found another survivor"<<endl;
			_sleep(1000);
			cout<<"Do you want to be friends?: ";
			cin>>friends;
			_sleep(1000);
			if (friends=="yes"||friends=="y"){
				cout<<"What is there name?: ";
				cin>>p2name;
				_sleep(1000);
				cout<<name<<" "<<p2name<<" are now friends"<<endl;
				_sleep(1000);
				p2health=rand()%100+1;
				p2hunger=rand()%100+1;
				p2thirst=rand()%100+1;
				p2energy=rand()%100+1;
				p2=true;
				displayStats();
				_sleep(1000);
			}
			else {
			}
		}
	}
}

void checkAlive(){
	if (health<=0){
		cout<<name<<" is now a zombie"<<endl;
		alive=false;
	}
	if (hunger<=0){
		cout<<name<<" starved to death"<<endl;
		alive=false;
	}
	if (thirst<=0){
		cout<<name<<" died of dehydration"<<endl;
		alive=false;
	}
	if (energy<=0){
		cout<<name<<" collapsed of exhaustion and died"<<endl;
		alive=false;
	}

	if (p2==true){
		if (p2health<=0){
			cout<<p2name<<" is now a zombie"<<endl;
			p2=false;
		}
		if (p2hunger<=0){
			cout<<p2name<<" starved to death"<<endl;
			p2=false;
		}
		if (p2thirst<=0){
			cout<<p2name<<" died of dehydration"<<endl;
			p2=false;
		}
		if (p2energy<=0){
			cout<<p2name<<" collapsed of exhaustion and died"<<endl;
			p2=false;
		}
	}
}

void travel() {
	int x, lostHung, lostThir, lostEng;
	x = rand() % 109;
	lostHung=rand()%12;
	lostThir=rand()%31;
	lostEng = x/2;
	energy=energy-lostEng;
	hunger=hunger-lostHung;
	thirst=thirst-lostThir;
	cout<<name<<" starts their journey"<<endl;
	_sleep(1000);
	cout<<"They travelled for "<<x<<" miles before finding civilisation"<<endl;
	_sleep(1000);
	cout<<name<<" loses "<<lostEng<<" energy, "<<lostHung<<" hunger, "<<lostThir<<" thirst"<<endl;
	_sleep(1000);

	if (p2==true){
		lostHung=rand()%12;
		lostThir=rand()%31;
		p2energy=p2energy-lostEng;
		p2hunger=p2hunger-lostHung;
		p2thirst=p2thirst-lostThir;
		cout<<p2name<<" loses "<<lostEng<<" energy, "<<lostHung<<" hunger, "<<lostThir<<" thirst"<<endl;
		_sleep(1000);
	}

	displayStats();
	_sleep(1000);
	checkAlive();
}

void fight() {
	int zombHealth, act, p2action;
	string action;
	bool cont;
	cont=true;
	zombHealth=rand()%100;
	cout<<"A wild zombie appeared!"<<endl;
	_sleep(1000);
	while (cont==true){
		cout<<name<<"'s health: "<<health<<endl<<"Zombie's health: "<<zombHealth<<endl;
		_sleep(1000);
		cout<<"What will you do (hit, defend, run)?: ";
		cin>>action;
		if (action=="hit"||action=="1"||action=="h"){
			act=rand()%21;
			_sleep(1000);
			cout<<name<<" hits for "<<act<<" damage"<<endl;
			zombHealth=zombHealth-act;
			act=rand()%21;
			_sleep(1000);
			cout<<"Zombie hits for "<<act<<" damage"<<endl;
			health=health-act;
		}
		if (action=="defend"||action=="2"||action=="d"){
			_sleep(1000);
			cout<<name<<" defends the zombie's attack"<<endl;
		}
		if (action=="run"||action=="3"||action=="r"){
			act=rand()%20;
			_sleep(1000);
			cout<<name<<" runs to escape the zombie"<<endl;
			_sleep(1000);
			cout<<"They lose "<<act<<" energy"<<endl;
			checkAlive();
			cont=false;
		}
		if (health<=0){
			health=0;
			cont=false;
		}
		if (zombHealth<=0){
			_sleep(1000);
			cout<<name<<" killed the zombie"<<endl;
			cont=false;
		}
	if (p2==true){
		if (action=="hit"||action=="1"||action=="h"||action=="defend"||action=="2"||action=="d"){
			p2action=rand()%2;
			if (p2action==0){
				act=rand()%21;
				zombHealth=zombHealth-act;
				_sleep(1000);
				cout<<"Zombie hits "<<p2name<<" for "<<act<<" damage"<<endl;
			}
			else {
				cout<<p2name<<" defends zombie's attack"<<endl;
				_sleep(1000);
			}
		}
	}
	_sleep(1000);
	}
}

void search() {
	string ans, p2ans;
	int searchItem, zomb;
	
	if (alive==true){
		zomb=rand()%2;
		if (zomb==1){
			fight();
			checkAlive();
		}

		if (alive==true){
			cout<<name<<" must search for..."<<endl<<"1. Food"<<endl<<"2. Drink"<<endl<<"3. Medication"<<endl<<"4. Shelter"<<endl;
			_sleep(1000);
			cout<<"What does "<<name<<" search for?: ";
			cin>>ans;

			if (ans=="1"||ans=="a"||ans=="food"){
				searchItem=rand()%81;
				cout<<name<<" searches for food"<<endl;
				_sleep(1000);
				cout<<"They find food to restore "<<searchItem<<" hunger"<<endl;
				hunger=hunger+searchItem;
				if (hunger>100){
					hunger=100;
				}
			}
			if (ans=="2"||ans=="b"||ans=="drink"){
				searchItem=rand()%41;
				cout<<name<<" searches for water"<<endl;
				_sleep(1000);
				cout<<"They find enough to restore "<<searchItem<<" thirst"<<endl;
				thirst=thirst+searchItem;
				if (thirst>100){
					thirst=100;
				}
			}
			if (ans=="3"||ans=="c"||ans=="medication"||ans=="meds"){
				searchItem=rand()%61;
				cout<<name<<" searches for medication"<<endl;
				_sleep(1000);
				cout<<"They find meds to restore "<<searchItem<<" health"<<endl;
				health=health+searchItem;
				if (health>100){
					health=100;
				}
			}
			if (ans=="4"||ans=="d"||ans=="shelter"){
				searchItem=rand()%101;
				cout<<name<<" searches for shelter"<<endl;
				_sleep(1000);
				cout<<"They find shelter and sleep to restore "<<searchItem<<" energy"<<endl;
				energy=energy+searchItem;
				if (energy>100){
					energy=100;
				}
			}

			if (p2==true){
				if (ans=="1"||ans=="a"||ans=="food"){
					searchItem=rand()%81;
					cout<<p2name<<" searches for food"<<endl;
					_sleep(1000);
					cout<<"They find food to restore "<<searchItem<<" hunger"<<endl;
					p2hunger=p2hunger+searchItem;
					if (p2hunger>100){
						p2hunger=100;
					}
				}
				if (ans=="2"||ans=="b"||ans=="drink"){
					searchItem=rand()%41;
					cout<<p2name<<" searches for water"<<endl;
					_sleep(1000);
					cout<<"They find enough to restore "<<searchItem<<" thirst"<<endl;
					p2thirst=p2thirst+searchItem;
					if (p2thirst>100){
						p2thirst=100;
					}
				}
				if (ans=="3"||ans=="c"||ans=="medication"||ans=="meds"){
					searchItem=rand()%61;
					cout<<p2name<<" searches for medication"<<endl;
					_sleep(1000);
					cout<<"They find meds to restore "<<searchItem<<" health"<<endl;
					p2health=p2health+searchItem;
					if (p2health>100){
						p2health=100;
					}
				}
				if (ans=="4"||ans=="d"||ans=="shelter"){
					searchItem=rand()%101;
					cout<<p2name<<" searches for shelter"<<endl;
					_sleep(1000);
					cout<<"They find shelter and sleep to restore "<<searchItem<<" energy"<<endl;
					p2energy=p2energy+searchItem;
					if (p2energy>100){
						p2energy=100;
					}
				}	
			}
			_sleep(1000);
			cout<<name<<" left the area"<<endl;
		}
	}
}

void mainLoop(){
	alive=true;
	while (alive==true) {
		travel();
		_sleep(1000);
		findP2();
		search();
		_sleep(1000);
	}
}

int main(void)
{
	bool quit;

	cout<<"***The Zombie Game***"<<endl;
	_sleep(1000);
	cout<<"v1.1 Z-Friend 2015"<<endl;
	_sleep(1000);
	cout<<"Please enter your name: ";
	cin>>name;
	_sleep(1000);
	quit=false;
	while (quit==false) {
		cout<<name<<" is one of few survivors of the zombie apocalypse"<<endl;
		_sleep(1000);
		cout<<"You must help "<<name<<" to survive"<<endl;
		_sleep(1000);
		health = 100, hunger = 100, thirst = 100, energy = 100;
		displayStats();
		_sleep(1000);

		mainLoop();

		cout<<"Do you want to respawn?: ";
		cin>>respawn;
		if (respawn=="no"||respawn=="n") {
			cout<<"Thank you for playing!"<<endl;
			_sleep(1000);
			cout<<"Goodbye";
			_sleep(1000);
			quit=true;
		}
		else if (respawn=="yes"||respawn== "y") {
			quit=false;
		}
		}
	return 0;
}