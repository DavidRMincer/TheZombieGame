#include <iostream>
#include <string>
#include <thread>
#include <stdlib.h>
using namespace std;

string name, respawn, p2name;
int health, hunger, thirst, energy, weapon, p2health, p2hunger, p2thirst, p2energy, p2weapon;
bool alive, p2;
// Define variables

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
	// If any player stats = 0, player dies
	// Outputs message for death
	// Alive sets to false
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
		// If survivor's stats = 0 player dies
		// Outputs message for death
		// Sets p2 to false
	}
}

void displayStats(){
	// Show player's and survivor's stats
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
	// If stat < 0, stat = 0
	if (health>100){
		health=100;
	}
	if (hunger>100){
		hunger=100;
	}
	if (thirst>100){
		thirst=100;
	}
	if (energy>100){
		energy=100;
	}
	// If stat > 100, stat = 100
	cout<<"Health: "<<health<<endl<<"Hunger: "<<hunger<<endl<<"Thirst: "<<thirst<<endl<<"Energy: "<<energy<<endl;
	// Output stats
	if (p2==true) {
		// If there is a survivor
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
		// If survivor's stat < 0, their stat = 0
		if (p2health>100){
			p2health=100;
		}
		if (p2hunger>100){
			p2hunger=100;
		}
		if (p2thirst>100){
			p2thirst=100;
		}
		if (p2energy>100){
			p2energy=100;
		}
		// If survivor's stat > 100, their stat = 100
		cout<<p2name<<"'s Health: "<<p2health<<endl<<p2name<<"'s Hunger: "<<p2hunger<<endl<<p2name<<"'s Thirst: "<<p2thirst<<endl<<p2name<<"'s Energy: "<<p2energy<<endl;
		// Output survivor's stats
		checkAlive();
		// Run checkAlive function
	}
}

void findP2() {
	// An encounter with another survivor
	string friends;
	int find;
	// Define friends as string and find as int
	if (p2==false){
		// If there is not another survivor
		find=rand()%7;
		// Set a random 1 in 7 chance of finding survivor
		if (find==1){
			cout<<name<<" found another survivor"<<endl;
			_sleep(1000);
			cout<<"Do you want to be friends?(y/n): ";
			cin>>friends;
			// Ask player if they want to befriend survivor
			_sleep(1000);
			if (friends=="yes"||friends=="y"){
				// If they say yes
				cout<<"What is there name? (1 word max): ";
				cin>>p2name;
				// Name the survivor
				_sleep(1000);
				cout<<name<<" and "<<p2name<<" are now friends"<<endl;
				// Output the player and survivor are now friends
				_sleep(1000);
				p2health=rand()%100+1;
				p2hunger=rand()%100+1;
				p2thirst=rand()%100+1;
				p2energy=rand()%100+1;
				// Randomise the survivor's stats
				p2=true;
				// Set p2 to true
				displayStats();
				// Run displayStats function
				_sleep(1000);
			}
			else {
				// If player says no, they continue game without survivor
			}
		}
	}
}

void travel() {
	int x, lostHung, lostThir, lostEng;
	// Define x, lostHung, lostThir and lostEng as integers
	x = rand() % 109;
	lostHung=rand()%12;
	lostThir=rand()%31;
	// Give x, lostHung and lostThir random values
	lostEng = x/3;
	// lostEng value = x divided by 2
	energy=energy-lostEng;
	hunger=hunger-lostHung;
	thirst=thirst-lostThir;
	// Take the lost value from player's stats
	cout<<name<<" starts their journey"<<endl;
	_sleep(1000);
	cout<<"They travelled for "<<x<<" miles before finding civilisation"<<endl;
	_sleep(1000);
	cout<<name<<" loses "<<lostEng<<" energy, "<<lostHung<<" hunger, "<<lostThir<<" thirst"<<endl;
	_sleep(1000);
	// Output the information

	if (p2==true){
		// If survivor is with the player
		lostHung=rand()%12;
		lostThir=rand()%31;
		// Set lostHung and lostThir as random values
		p2energy=p2energy-lostEng;
		p2hunger=p2hunger-lostHung;
		p2thirst=p2thirst-lostThir;
		// Take lost values from survivor's stats
		cout<<p2name<<" loses "<<lostEng<<" energy, "<<lostHung<<" hunger, "<<lostThir<<" thirst"<<endl;
		// Output information
		_sleep(1000);
	}

	displayStats();
	// Run displaystats function
	_sleep(1000);
	checkAlive();
	// Run checkAlive function
}

void fight() {
	int zombHealth, act, p2action, zomb;
	string action;
	bool cont;
	zomb=rand()%2;
	switch (zomb)
	{
	case 0:
		// Define zombHealth, act and p2action as integer, action as string and cont as boolean
			cont=true;
			// Set con to true
			zombHealth=rand()%100;
			// Set zombHealth to random value
			cout<<"A wild zombie appeared!"<<endl;
			_sleep(1000);
			// Output "A wild zombie appeared!"
			while (cont==true){
				// While cont = true
				cout<<name<<"'s health: "<<health<<endl;
				if (p2==true) {
					cout<<p2name<<"'s health: "<<p2health<<endl;
				}
				cout<<"Zombie's health: "<<zombHealth<<endl;
				// Output player's and zombies health
				_sleep(1000);
				cout<<"What will you do (hit, defend, run)?: ";
				cin>>action;
				// Input player's action
				if (action=="hit"||action=="1"||action=="h"){
					// If player inputs hit
					act=rand()%weapon;
					// Hit for a random value (0 - weapon's max)
					_sleep(1000);
					cout<<name<<" hits for "<<act<<" damage"<<endl;
					zombHealth=zombHealth-act;
					// Attack zombie
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
		break;
	}
}

void search() {
	string ans, p2ans;
	int searchItem;

	searchItem=rand()%101;
	cout<<name<<" must search for:"<<endl<<"(1) Food"<<endl<<"(2) Water"<<endl<<"(3) Medication"<<endl<<"(4) Weapons"<<endl<<"(5) Shelter"<<endl;
	_sleep(1000);
	cout<<"What does "<<name<<" search for?: ";
	cin>>ans;

	if (ans=="1" || ans=="food") {
		cout<<name<<" searches for food"<<endl;
		_sleep(1000);
		if (searchItem==0) {
			cout<<name<<" does not find any food"<<endl;
		}
		else {
			cout<<name<<" finds food to restore "<<searchItem<<" hunger"<<endl;
			hunger=hunger+searchItem;
		}
	}
	if (ans=="2" || ans=="water") {
		cout<<name<<" searches for water"<<endl;
		_sleep(1000);
		if (searchItem==0) {
			cout<<name<<" does not find any water"<<endl;
		}
		else {
			cout<<name<<" finds water to restore "<<searchItem<<" thirst"<<endl;
			thirst=thirst+searchItem;
		}
	}
	if (ans=="3" || ans=="meds" || ans=="medication") {
		cout<<name<<" searches for meds"<<endl;
		_sleep(1000);
		if (searchItem==0) {
			cout<<name<<" does not find any medication"<<endl;
		}
		else {
			cout<<name<<" finds medication to restore "<<searchItem<<" health"<<endl;
			health=health+searchItem;
		}
	}
	if (ans=="4" || ans=="weapon" || ans=="weapons") {
		cout<<name<<" searches for a weapon"<<endl;
		_sleep(1000);
		if (searchItem>=90) {
			cout<<name<<" found a shotgun"<<endl;
			weapon=100;
		}
		else if (searchItem>=80) {
			cout<<name<<" found a rifle"<<endl;
			weapon=90;
		}
		else if (searchItem>=70) {
			cout<<name<<" found a minigun"<<endl;
			weapon=80;
		}
		else if (searchItem>=60) {
			cout<<name<<" found a chainsaw"<<endl;
			weapon=70;
		}
		else if (searchItem>=50) {
			cout<<name<<" found a sword"<<endl;
			weapon=60;
		}
		else if (searchItem>=40) {
			cout<<name<<" found a pistol"<<endl;
			weapon=50;
		}
		else if (searchItem>=30) {
			cout<<name<<" found an axe"<<endl;
			weapon=40;
		}
		else if (searchItem>=20) {
			cout<<name<<" found a knife"<<endl;
			weapon=30;
		}
		else if (searchItem>=10) {
			cout<<name<<" found some knuckle dusters"<<endl;
			weapon=20;
		}
	}
	if (ans=="5" || ans=="shelter") {
		cout<<name<<" searches for shelter"<<endl;
		_sleep(1000);
		if (searchItem==0) {
			cout<<name<<" does not find any shelter"<<endl;
		}
		else {
			cout<<name<<" finds shelter and sleeps to restore "<<searchItem<<" energy"<<endl;
			energy=energy+searchItem;
		}
	}

	if (p2==true) {
		searchItem=rand()%101;
		cout<<"What does "<<p2name<<" search for?: ";
		cin>>ans;
		if (ans=="1" || ans=="food") {
			cout<<p2name<<" searches for food"<<endl;
			_sleep(1000);
			if (searchItem==0) {
				cout<<p2name<<" does not find any food"<<endl;
			}
			else {
				cout<<p2name<<" finds food to restore "<<searchItem<<" hunger"<<endl;
				p2health=p2health+searchItem;
			}
		}
		if (ans=="2" || ans=="water") {
			cout<<p2name<<" searches for water"<<endl;
			_sleep(1000);
			if (searchItem==0) {
				cout<<p2name<<" does not find any water"<<endl;
			}
			else {
				cout<<p2name<<" finds water to restore "<<searchItem<<" thirst"<<endl;
				p2thirst=p2thirst+searchItem;
			}
		}
		if (ans=="3" || ans=="meds" || ans=="medication") {
			cout<<p2name<<" searches for meds"<<endl;
			_sleep(1000);
			if (searchItem==0) {
				cout<<p2name<<" does not find any medication"<<endl;
			}
			else {
				cout<<p2name<<" finds medication to restore "<<searchItem<<" health"<<endl;
				p2health=p2health+searchItem;
			}
		}
		if (ans=="4" || ans=="weapon" || ans=="weapons") {
			cout<<p2name<<" searches for a weapon"<<endl;
			_sleep(1000);
			if (searchItem>=90) {
				cout<<p2name<<" found a shotgun"<<endl;
				p2weapon=100;
			}
			else if (searchItem>=80) {
				cout<<p2name<<" found a rifle"<<endl;
				p2weapon=90;
			}
			else if (searchItem>=70) {
				cout<<p2name<<" found a minigun"<<endl;
				p2weapon=80;
			}
			else if (searchItem>=60) {
				cout<<p2name<<" found a chainsaw"<<endl;
				p2weapon=70;
			}
			else if (searchItem>=50) {
				cout<<p2name<<" found a sword"<<endl;
				p2weapon=60;
			}
			else if (searchItem>=40) {
				cout<<p2name<<" found a pistol"<<endl;
				p2weapon=50;
			}
			else if (searchItem>=30) {
				cout<<p2name<<" found an axe"<<endl;
				p2weapon=40;
			}
			else if (searchItem>=20) {
				cout<<p2name<<" found a knife"<<endl;
				p2weapon=30;
			}
			else if (searchItem>=10) {
				cout<<p2name<<" found some knuckle dusters"<<endl;
				p2weapon=20;
			}
		}
		if (ans=="5" || ans=="shelter") {
			cout<<p2name<<" searches for shelter"<<endl;
			_sleep(1000);
			if (searchItem==0) {
				cout<<p2name<<" does not find any shelter"<<endl;
			}
			else {
				cout<<p2name<<" finds shelter and sleeps to restore "<<searchItem<<" energy"<<endl;
				p2energy=p2energy+searchItem;
			}
		}
	}

	_sleep(1000);
	cout<<name<<" left the area"<<endl;
}

void mainLoop(){
	alive=true;
	while (alive==true) {
		travel();
		_sleep(1000);
		if (alive==false) {
			break;
		}
		findP2();
		fight();
		if (alive==false) {
			break;
		}
		search();
		_sleep(1000);
	}
}

int main(void)
{
	bool quit;

	cout<<"***The Zombie Game***"<<endl;
	_sleep(1000);
	cout<<"v1.1 Arm Yourself 2015"<<endl;
	_sleep(1000);
	cout<<"Please enter your name (1 word max): ";
	cin>>name;
	_sleep(1000);
	quit=false;
	while (quit==false) {
		cout<<name<<" is one of few survivors of the zombie apocalypse"<<endl;
		_sleep(1000);
		cout<<"You must help "<<name<<" to survive"<<endl;
		_sleep(1000);
		weapon=11, health = 100, hunger = 100, thirst = 100, energy = 100;
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