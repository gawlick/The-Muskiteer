/* 
 * Author: Dallas Gawlick
 * Date: December 20 2014 (to start)
 * Purpose: To create a text-based adventure about Guillaume the Musketeer
 * Some Direction: press 1 for yes, 0 for no, and q at any time for quit
 */

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define DIEMAX 20
#define HEALTH_ENEMY 100

void quit( void );
void story( void );
void manual( void );

void walkAway( int inventory[] );
void youDied( void );

void jeanLuc( int inventory[], int completion[], int location[], int victories[], int notes[] );

int roll( void );
int rollDie( void );
int rollPoem( void );

void signpostBeginning( void );

void aignan( int inventory[], int notes[], int victories[], int completion[], int location[] );
void aire( int inventory[], int notes[], int victories[], int completion[], int location[] );
void mont( int inventory[], int notes[], int victories[], int completion[], int location[] );
void roquefort( int inventory[], int notes[], int victories[], int completion[], int location[] );
void bordeaux( int inventory[], int notes[], int victories[], int completion[], int location[] );

void aignanFunction( int inventory[], int completion[], int location[], int victories[], int notes[] );
void aireFunction( int inventory[], int completion[], int location[], int victories[], int notes[] );
void montFunction( int inventory[], int completion[], int location[], int victories[], int notes[] );
void roquefortFunction( int inventory[], int completion[], int location[], int victories[], int notes[] );
void bordeauxFunction( int inventory[], int completion[], int location[], int victories[], int notes[] );

void tavernAignan( int inventory[], int notes[] );
void tavernAire( int inventory[], int notes[] );
void tavernMont( int inventory[], int notes[] );
void tavernRoquefort( int inventory[], int notes[] );
void tavernBordeaux( int inventory[], int notes[] );

void zoltarSpeaksAignan( void );
void zoltarSpeaksAire( void );
void zoltarSpeaksMont( void );
void zoltarSpeaksRoquefort( void );
void zoltarSpeaksBordeaux( void );

void bar( int inventory[] );
void gamble( int inventory[] );
void gambleGame( int inventory[] );
void gamblingInstruct( void );
void bard( int inventory[] );
void readPoems( int poemNum );

int fight( int inventory[], int healthEnemy );
int attack( int inventory[], int enemyHealth, int num, int damage );
void counter( int inventory[], int num, int damage );
void parry( int inventory[], int num );
void dodge( int inventory[], int num );

void readNotes( int notes[] );
void inventoryScreen( int inventory[], int notes[] );
void lootCorpse( int inventory[] );

int main( void ){

	int ans;

	do{

	srand( (unsigned) time( NULL ) );

	system( "cls" );
	
	printf("\n                          Welcome to THE MUSKETEER.\n\n");
	printf("      ( A text-based adventure written and directed by Dallas Gawlick. )\n\n\n\n\n\n");
	printf("                          Would you like to play?  ");
	printf("\n                        Press 2 to access manual...");
	printf("\n\n                                     ");
	scanf("%d", &ans);
	
	if( ans == 1 )
		story();
	if( ans == 2 )
		manual();
	if( ans == 0 )
		quit();

	} while(ans != 0);

	system( "PAUSE" );
	return 0;

}

/* Quits the game, if the user so desires.*/
void quit( void ){

	system( "cls" );

	printf("\n Merci d'avoir jouer!\n\n");
	system( "PAUSE" );
	exit(0);
	
}

void manual( void ){

	int close;

	do{
		system( "cls" );
		
		printf("\n               MANUAL\n\n");
		printf(" Press 0 for no, press 1 for yes.\n");
		printf("  ( Like binary.)\n");
		printf(" Press 1 to access Guillame's inventory.\n");
		printf("  ( When prompted. )\n");
		printf(" Your money is denoted by Francs.\n");
		printf(" Your health is healed by food. Each bite heals 20 health.\n");
		printf(" Your sword strength affects your duelling ability.\n");
		printf("  ( A higher level sword = easier duels. )\n");
		printf(" Guillame starts off with a level 1 sword.\n");

		printf("\n\n Close Manual?  ");
		printf("\n\n ( Press 2 to quit... )\n\n   ");
		scanf("%d", &close);

	} while( close == 0 );

	if( close == 2 ) quit();

}

/* Generates a random Die Roll Number ( 1 - 20 inclusive ) */
int roll( void ){
	 return ( rand() % DIEMAX ) + 1;
}

/*Generates a random die roll number ( 1 - 6 inclusive )*/
int rollDie( void ){
	return ( rand() % 6 ) + 1;
}

/* Generates a random number for poems, 1 - 10 inclusive */
int rollPoem( void ){
	return ( rand() % 10 ) + 1;
}

/*the general story arc of the game*/ ////////////////////////////////////////////////////////////////////////////////// STORY
void story( void ){

	/*inventory: 0th slot is money, 1st slot is food, 2nd slot is sword strength, 3rd slot is health (starts at 100).*/
	int inventory[4] = {5, 1, 1, 100};
	/*Acquired notes are stored here...*/
	int notes[5] = {0, 0, 0, 0, 0};
	/*Victories against enemies...*/
	int victories[5] = {0, 0, 0, 0, 0};
	/*Completed Cities Counter*/
	int completion[5] = {0, 0, 0, 0, 0};
	/*Shows where player is in the game; starting in Aignan*/
	int location[5] = {1, 0, 0, 0, 0};

	int ans; // answer to screen input

	system( "cls" );
		
	printf("\n You are Guillame. A former mousquetaire, lost somewhere south of Chateau\n");
	printf(" Castlemore. You must find your way to Bordeaux, and take vengeance upon he\n");
	printf(" who wronged you. You must end the man, before befalling great harm.\n");
	
	printf("\n There is a roadsign before you. Would you inspect it?  ");
	scanf("%d", &ans);
	if( ans ) signpostBeginning();

	aignan( inventory, notes, victories, completion, location );

	system( "cls" );

	if( completion[0] == 0 ) printf("\n Congratulations! You have completed Aignan.\n");
	completion[0] = 1;

	Sleep( 2500 );

	jeanLuc( inventory, completion, location, victories, notes );

	aire( inventory, notes, victories, completion, location );

	system( "cls" );

	if( completion[1] == 0 ) printf("\n Congratulations! You have completed Aire-sur-l'Adour.\n");
	completion[1] = 1;

	Sleep( 2500 );

	jeanLuc( inventory, completion, location, victories, notes );

	mont( inventory, notes, victories, completion, location );

	system( "cls" );

	if( completion[2] == 0 ) printf("\n Congratulations! You have completed Mont-de-Marsan.\n");
	completion[2] = 1;

	Sleep( 2500 );

	jeanLuc( inventory, completion, location, victories, notes );

	roquefort( inventory, notes, victories, completion, location );

	system( "cls" );

	if( completion[3] == 0 ) printf("\n Congratulations! You have completed Roquefort.\n");
	completion[3] = 1;

	Sleep( 2500 );

	jeanLuc( inventory, completion, location, victories, notes );

	bordeaux( inventory, notes, victories, completion, location );

	return;

}

void signpostBeginning( void ){ // the first encountered signpost

	int ans;

	printf("\n This signpost reads:\n\n  Aignan - 2km en la norde\n  Aire-sur-l'Adour - 25km en l'ouest\n\n");
	printf(" Where would you travel? North?  ");
	scanf("%d", &ans);
	
	system( "cls" );
		
	if( ans == 0 ){
		printf("\n You look along the long, dusty road west.\n");
		printf(" The march is daunting - you decide to try your luck in the nearest town,\n");
		printf(" Aignan...\n");
		Sleep( 3000 );
		return;
	}	

	printf("\n You continue your journey north, toward Aignan...");

	return;
	
}

void walkAway( int inventory[] ){ // makes a chance of damage as you walk away from a battle

	int rNum;
	int hp = inventory[3];

	rNum = roll();

	system( "cls" );

	if( rNum % 2 == 0 )
		printf("\n You successfully walk away from the battle.\n");

	else{
		hp -= 5;
		printf("\n You are damaged by the coward! Health now at %i.\n", hp);
	}

	inventory[3] = hp;

	Sleep( 1000 );
	return;

}

/*Creates a somewhat randomized fight between the user and an enemy.*/
int fight( int inventory[], int healthEnemy ){

	int fightNum;
	int swordStrength;
	int walkAns;
	int attackDamage;
	int choice;
	int win;
	
	swordStrength = inventory[2];

	if( swordStrength == 1 ){
		attackDamage = 10;
	}

	else if( swordStrength == 2 ){
		attackDamage = 15;
	}

	else if( swordStrength == 3 ){
		attackDamage = 20;
	}

	else if( swordStrength == 4 ){
		attackDamage = 25;
	}

	else if( swordStrength == 5 ){
		attackDamage = 30;
	}

	system( "cls" );
	printf("\n You unsheath your sword. The polished steel glints in the sun...\n");

	printf("\n You have chosen to duel!\n");
	printf(" What would you do?\n\n");
	printf(" ATTACK : 0\n");
	printf(" PARRY  : 1\n");
	printf(" DODGE  : 2\n");
	printf("\n   ");
	scanf("%i", &choice);

	do{

		fightNum = roll();
		walkAns = 0;

		if( choice == 0 )
			healthEnemy = attack( inventory, healthEnemy, fightNum, attackDamage );

		else if( choice == 1 )
			parry( inventory, fightNum );

		else if( choice == 2 )
			dodge( inventory, fightNum );

		if( inventory[3] <= 20 && inventory[3] > 0 ){
			/*Health low - initiate walkAway function*/
			printf("\n Your health is dangerously low!\n");
			printf(" Would you walk away from this battle?   ");
			scanf("%i", &walkAns);
			printf("\n");

			if( walkAns == 1 ){
			walkAway( inventory );
			win = 0;
			return win;
			break;
			}
		}

		printf("\n What would you do?   ");
		scanf("%i", &choice);

	} while( healthEnemy > 0 && inventory[3] > 0 && walkAns == 0 && choice != 7 );

	if( inventory[3] <= 0 ){
		youDied();
	}

	if( healthEnemy <= 0 || choice == 7 ){
		win = 1;
	}
	else
		win = 0;

	return win;
}

/*Allows user to attack his/her enemy*/
int attack( int inventory[], int enemyHealth, int num, int damage ){

	if( num % 2 == 0 || num % 6 == 0 ){
		/*65% chance of attack success*/
		enemyHealth -= damage;
		printf("\n\n Successful attack! Foe health now at %i.\n\n", enemyHealth);
	}
	else counter( inventory, num, damage );

	return enemyHealth;

}

/*Provides the enemy with a chance to counterattack*/
void counter( int inventory[], int num, int damage ){

	int ans;
	
	printf("\n\n Your attack has been countered!\n\n");
	printf("\n What would you do?   ");
	scanf("%i", &ans);

	if( ans == 0 ){
		inventory[3] -= 10;
		printf("\n\n You failed to parry or dodge! Health now at %i.\n\n", inventory[3]);
	}

	else if( ans == 1 ){
		if( num % 3 == 0 || num % 5 == 0 ){
			/*30% chance of parry failure*/
			inventory[3] -= 10;
			printf("\n\n Parry failed! Health now at %i.\n\n", inventory[3]);
		}
		else printf("\n\n Parry successful!\n\n");
	}

	else if( ans == 2 ){
		if( num % 4 == 0 || num % 3 == 0 ){
			/*25% chance of dodge success*/
			printf("\n\n Dodge successful!\n\n");
		}
		else{
			inventory[3] -= 10;
			printf("\n\n Dodge failed! Health now at %i.\n\n", inventory[3]);
		}
	}

}

/*Allows user to parry a counterattack*/
void parry( int inventory[], int num ){


	if( num % 5 == 0 || num % 3 == 0 || num % 4 == 0 )
		printf("\n\n Parry successful!\n\n");
	
	else{
		/*30% chance of parry failure.*/
		inventory[3] -= 10;
		printf("\n\n Parry failed! Health now at %i.\n\n", inventory[3]);
	}

}

/*Allows user to dodge a counterattack*/
void dodge( int inventory[], int num ){


	if( num % 4 == 0 || num % 3 == 0 || num % 6 == 0 ){
		/*60% chance of dodge success*/
		printf("\n\n Dodge successful!\n\n");
	}

	else{
		inventory[3] -= 10;
		printf("\n\n Dodge failed! Health now at %i.\n\n", inventory[3]);
	}

}

/*Brings up the You Died / Play Again Screen*/
void youDied( void ){

	system( "cls" );

	printf("\n VALAR MORGHULIS...\n\n");

	Sleep( 1000 );

	quit();
}

/*Allows the player to loot their deceased foe, in order to gain a random amount of food and money.*/
void lootCorpse( int inventory[] ){

	int foundFrancs;
	int foundFood;

	foundFrancs = roll() / 2;
	foundFood = roll() / 4;

	inventory[0] += foundFrancs;
	inventory[1] += foundFood;

	system( "cls" );

	printf("\n - You have recovered %i Francs!\n\n", foundFrancs);
	printf(" - And, you've recovered %i food!\n\n", foundFood);

}

/*Opens the inventory panel. inventory is denoted by an array, initialized above.*/
void inventoryScreen( int inventory[], int notes[] ){

	int numSword = inventory[2];
	int close;

	do{

	system( "cls" );

	printf("\n");
	printf("                       inventory\n\n");
	printf(" Money (Francs)     Food     Sword Strength     Health\n\n");
		
		printf("       ");
		printf("%d", inventory[0]);

		if( inventory[0] < 10 ) printf("              ");
		else printf("             ");
		printf("%d", inventory[1]);

		if( inventory[1] < 10 ) printf("             ");
		else printf("            ");
		printf("%d", inventory[2]);

		if( inventory[3] < 100 )
		printf("             ");
		else printf("            ");
		printf("%d", inventory[3]);

		printf("\n\n Name of Sword:\n\n");

		if( numSword == 1 )
			printf("   PITTED BLADE");
		else if( numSword == 2 )
			printf("   LE BASTILLE");
		else if( numSword == 3 )
			printf("   INSERT SWORD 3 NAME HERE");
		else if( numSword == 4 )
			printf("   INSERT SWORD 4 NAME HERE");
		else if( numSword == 5 )
			printf("   INSERT SWORD 5 NAME HERE");

		printf("\n\n Press 0 to close inventory.");
		printf("\n\n Press 1 to open journal.");
		printf("\n\n Press 2 to eat food.");
		printf("\n\n     ");

	scanf("%d", &close);

	if( close == 0 )
		break;

	if( close == 1 ) // reads notes
		readNotes( notes );

	do{

		if( close == 2 ){ // health capped at 100
			if( inventory[1] > 0 ){
				inventory[1]--;
				inventory[3] += 20;
				if( inventory[3] > 100 )
					inventory[3]= 100;
		}
		if( inventory[1] <= 0 && close == 2 ){ // checks if valid amount of food
			printf("\n\n No food remaining!");
			Sleep( 1000 );
		}
	}

	close = 0;

	} while( close == 3 );
	
	} while( close == 0 );

	if( close == 1 )
		return;

}

/*Allows user to read the notes they've acquired.*/
void readNotes( int data[] ){

	int ans;
	int close;

	do{

	system( "cls" );

	printf("\n You open your journal, scanning the many yellowed pages...");
	printf("\n\n Which note would you read?   ");
	printf("\n\n   ( You can have up to 5 notes. )");
	printf("\n\n     ");
	scanf("%d", &ans);
	printf("\n\n");

		if( ans == 1 ){
			if( data[0] == 0 )
				printf(" Sorry - you don't have that note yet.");
			else{
				system( "cls" );

				printf("\n      Dear Remy,\n\n");
				printf("   We know a certain individual from your past will appear in Aignan.\n");
				printf("   We need you prepared. Bring steel. He must be stopped at all costs.\n");
				printf("   We know your skill with a blade is unmatched. Achieve this, and you will\n");
				printf("   receive a bonus. We cannot have him leave Aignan alive; the life of\n");
				printf("   the princess depends upon it.\n\n");
				printf("        * * *\n\n");
				printf(" Remy... The man had once been an acquaintance of yours. Until, of course,\n");
				printf(" he had the audacity to openly accuse you of cheating at dice. You were tossed\n");
				printf(" out of Aignan, none too happy with the developments. Had Remy become mixed up\n");
				printf(" in something sinister..?");
			}
		}

		if( ans == 2 ){
			if( data[1] == 0 )
				printf(" Sorry - you don't have that note yet.");
			else{
				system( "cls" );

				printf("\n The outside of the letter says,");
				printf("\n\n     FOR COUNT ALAIN'S EYES ONLY");
				printf("\n\n You break the seal anyway, having vanquished the man.");
				Sleep( 2000 );

				do{					
					system( "cls" );

					printf("\n     Ser Alaine,");
					printf("\n In order to avoid the worst possible outcome, we need you prepared.");
					printf("\n As count of the lands surrounding Aire-sur-l'Adour, we need you to raise");
					printf("\n and rally your citizens against a man who may make his way to this town.");
					printf("\n\n This man - easily identifiable by his half-cape and sword, is a great threat");
					printf("\n to the crown, and to our beloved princess. He must not be allowed to live.");
					printf("\n Take care of the man, and report back duly. You will be rewarded in gold,");
					printf("\n and fertile farmland for your citizens.");
					printf("\n\n Signed,");
					printf("\n         Lord Castlemore.");

					printf("\n\n Press 1 to turn the letter over.");
					scanf("%d", &ans);
				} while( ans != 1 );

				do{
					system( "cls" );
				
					printf("\n Nothing is written on the other side.");
					printf("\n Staring at the blankness, you start to remember...");

					printf("\n\n Press 1 to remember.");
					printf("\n Press 0 to fold the letter and put it away.");
					scanf("%d", &ans);
				} while( ans != 0 && ans != 1 );

				if( ans == 1 ) do{
					system( "cls" );
					printf("\n As you close your eyes, visions return from long lost memories...\n");
					printf("\n You remember a cruel-looking count, his long black moustache");
					printf("\n flying in the wind.");
					printf("\n\n You remember a sword duel, a blow to the head, the feeling of");
					printf("\n flight as you are thrown into a moat.");
					printf("\n\n Press 1 to fold the letter and put it away.");
					scanf("%d", &ans);
				} while( ans != 1 );
			}
		}

		if( ans == 3 ){
			if( data[2] == 0 )
				printf(" Sorry - you don't have that note yet.");
		}

		if( ans == 4 ){
			if( data[3] == 0 )
				printf(" Sorry - you don't have that note yet.");
		}

		if( ans == 5 ){
			if( data[4] == 0 )
				printf(" Sorry - you don't have that note yet.");
		}

		printf("\n\n Close journal?   ");
		scanf("%d", &close);
	} while( close == 0 );

	return;

}

/*Allows user to visit the tavern in Aignan*/ ///////////////////////////////////////////////////////////////////////// TAVERNS
void tavernAignan( int inventory[], int notes[] ){

	int ans;
	int count = 0;

	do{

		system( "cls" );

		printf("\n You step inside the musty tavern...\n\n");
		printf(" You see a bar, a gambling table, a bard - and a standoffish man in the corner.\n\n");

		printf(" Press 0 to leave the tavern.\n");
		printf(" Press 1 to sit at the bar.\n");
		printf(" Press 2 to inquire into gambling.\n");
		printf(" Press 3 to talk to the bard.\n");
		printf(" Press 4 to open your inventory.\n");
		if( count == 0 )
			printf(" Press 5 to approach the man.\n");
		printf("\n     ");
		scanf("%d", &ans);

		if( ans == 1 ){
			bar( inventory );
			ans = 7;
		}

		if( ans == 2 ){
			gamble( inventory );
			ans = 7;
		}

		if( ans == 3 ){
			bard( inventory );
			ans = 7;
		}

		if( ans == 4 ){
			inventoryScreen( inventory, notes );
			ans = 7;
		}

		if( ans == 5 && count == 0 ){
			zoltarSpeaksAignan();
			count++;
		}

	} while( ans != 0 );

}

/*Allows user to visit the tavern in Aire-sur-l'Adour*/
void tavernAire( int inventory[], int notes[] ){

	int ans = 0;
	int count = 0;

	do{

		system( "cls" );
		printf("\n The oak door creaks as you step inside...");
		printf("\n The tavern has a cheerful, riverside atmosphere.");
		printf("\n\n You see a bar, another gambling table, a man with a");
		printf("\n feathered hat, and a familiar old man in a far corner.\n\n");

		printf(" Press 0 to leave the tavern.\n");
		printf(" Press 1 to sit at the bar.\n");
		printf(" Press 2 to try your luck at gambling.\n");
		printf(" Press 3 to talk to the bard.\n");
		printf(" Press 4 to open your inventory.\n");
		if( count == 0 )
			printf(" Press 5 to talk to the familiar old man.\n");
		printf("\n     ");
		scanf("%d", &ans);

		if( ans == 1 ){
			bar( inventory );
			ans = 7;
		}

		if( ans == 2 ){
			gamble( inventory );
			ans = 7;
		}

		if( ans == 3 ){
			bard( inventory );
			ans = 7;
		}

		if( ans == 4 ){
			inventoryScreen( inventory, notes );
			ans = 7;
		}

		if( ans == 5 && count == 0 ){
			zoltarSpeaksAire();
			count++;
		}

	} while( ans != 0 );

}

/*Allows user to visit the tavern in Mont-de-Marsan*/
void tavernMont( int inventory[], int notes[] ){

}

/*Allows user to visit the tavern in Roquefort*/
void tavernRoquefort( int inventory[], int notes[] ){

}

/*Allows user to visit the tavern in Bordeaux*/
void tavernBordeaux( int inventory[], int notes[] ){

}

/*Allows player to visit the bar in any tavern.*/
void bar( int inventory[] ){

	int ans;

	do{

	system( "cls" );

	printf("\n   - Salut. What can I get you?\n");
	printf("   - Baguettes are 3 Francs.\n");
	printf("   - Wine is 1 Franc.\n\n");
	printf(" You have %d Francs.\n\n", inventory[0]);
	
	printf(" Press 0 to leave bar.\n");
	printf(" Press 1 for a baguette.\n");
	printf(" Press 2 for a cup of wine.\n");
	printf("\n     ");

	scanf("%i", &ans);

	if( ans == 1 ){
		if( inventory[0] >= 3 ){
			inventory[1]++;
			inventory[0] -= 3;
			printf("\n\n Food now at %i.", inventory[1]);
			printf("\n Money now at %i.", inventory[0]);
			Sleep( 2000 );
			ans = 7;
		}
		else{
			printf("\n\n Not enough money...");
			Sleep( 2000 );
			ans = 7;
		}
	}

	if( ans == 2 ){
		if( inventory[0] >= 1 ){
			if( inventory[3] >= 100 )
				inventory[3] = 100;
			else inventory[3] += 10;
			inventory[0] -= 1;
			printf("\n\n Health now at %i.", inventory[3]);
			printf("\n Money now at %i.", inventory[0]);
			Sleep( 2000 );
			ans = 7;
		}
		else{
			printf("\n\n Not enough money...");
			Sleep( 1000 );
			ans = 7;
		}
	}

	if( ans == 0 )
		return;

	} while( ans != 0 );

}

/*Allows player to gamble with people inside any tavern.*/
void gamble( int inventory[] ){

	int ans;

	do{

		system( "cls" );

		printf("\n You sit down at the gambling table, and take off your hat...");
		printf("\n\n Press 0 to leave gambling table.");
		printf("\n Press 1 to begin gambling.");
		printf("\n Press 2 to see instructions.\n");
		printf("\n     ");
		scanf("%d", &ans);

		if( ans == 0 )
			return;

		if( ans == 1 ){
			gambleGame( inventory );
			ans = 7;
		}

		if( ans == 2 ){
			gamblingInstruct();
			ans = 7;
		}
		
	} while( ans != 0 );
}

/*Allows player to read instructions for gambling.*/
void gamblingInstruct( void ){

	int ans;

	do{

		system("cls");

		printf("\n            PLAYERS WIN, AND WINNERS PLAY!");
		printf("\n\n This is a simple dice game, consisting of multiple rounds.\n");
		printf(" Guillame throws a die, and so does his opponent.\n");
		printf(" If Guillame's die is of a higher number than his opponent, he wins.\n");
		printf(" If not, Guillame loses.\n");
		printf("\n Press 0 to exit instructions.");
		printf("\n\n     ");
		scanf("%d", &ans);

		if( ans == 0 )
			return;

	} while( ans != 0 );	

}

/*Allows player to gamble against opponents in a simple dice game.*/
void gambleGame( int inventory[] ){

	int dieGuillame;
	int dieOpponent;
	int ans;
	int roundCount;
	int winCount = 0;
	int loseCount = 0;
	int bet;

	do{
		
		system("cls");

		printf("\n Press 0 to leave table.");
		printf("\n Press 1 to make a bet.");
		printf("\n   (You have %d Francs)", inventory[0]);
		printf("\n\n     ");
		scanf("%d", &ans);

		if( ans == 1 ){
			printf("\n\n Place bet: ");
			scanf("%d", &bet);
			
			if( bet > inventory[0] || bet <= 0 ){
				printf("\n\n Invalid bet...");
				ans = 7;
			}
			
			else if( bet <= inventory[0] ){

				do{
					for( roundCount = 1; roundCount <= 5; roundCount++){
						dieGuillame = rollDie();
						dieOpponent = rollDie();

						system("cls");

						printf("\n   ROUND %d", roundCount);
						printf("\n   BET: %d", bet);

						printf("\n\n You rolled a %d.", dieGuillame);
						printf("\n Your opponent rolled a %d.", dieOpponent);
	
						if( dieGuillame > dieOpponent ){
							printf("\n\n You win the round!");
							winCount++;
						}
						if( dieGuillame <= dieOpponent ){
							printf("\n\n You lost the round.");
							loseCount++;
						}

						if( roundCount == 5 ) 
							break;

						printf("\n\n Roll again?");
						printf("\n\n     ");
						scanf("%d", &ans);

						if( ans == 0 ){
							winCount = 0;
							loseCount = 0;
							break;
						}
					}

					if( roundCount == 5 )
						break;
					if( ans == 0 ){
						winCount = 0;
						loseCount = 0;
						break;
					}

				} while( ans == 1 );
			}

			if( winCount > loseCount ){
				printf("\n\n You win!");
				inventory[0] += bet;
				printf("\n Money now at %d.", inventory[0]);
			}

			if( winCount < loseCount ){
				printf("\n\n You lost...");
				inventory[0] -= bet;
				if( inventory[0] < 0 )
					inventory[0] = 0;
				printf("\n Money now at %d.", inventory[0]);
			}

			printf("\n\n Play again?");
			printf("\n\n     ");
			scanf("%d", &ans);

			if( ans == 1 )
				ans = 7;
			if( ans == 0 )
				return;

		}

		else if( ans == 0 )
			return;

	} while( ans != 0 );
}

/*Allows player to pay a bard in return for a short poem.*/
void bard( int inventory[] ){

	int ans;
	int poemNum;

	do{
		system("cls");

		poemNum = rollPoem();

		printf("\n   - Bonjour, good sir. Would you hear a poem?");
		printf("\n   - They are my own creation, borne from hours of hard labor.");
		printf("\n        (Poems are 5 Francs each. You have %d.)", inventory[0]);
		printf("\n\n     ");
		scanf("%d", &ans);

		if( ans == 0 )
			return;

		if( inventory[0] < 5 && ans == 1 ){
			printf("\n\n   - I am sorry, but you do not appear to have money!");
			Sleep( 2000 );
			ans = 7;
		}

		if( ans == 1 && inventory[0] >= 5 ){
			inventory[0] -= 5;
			readPoems( poemNum );
		}

	} while( ans != 0 );

}

/*Puts a poem on screen for user to read.*/
void readPoems( int poemNum ){

	int ans;

	do{

		system("cls");

		printf("\n   - Thank you, kind sir.");

		if( poemNum == 1 ){
			printf("\n");
			printf("\n   I met a traveller from an antique land");
			printf("\n   Who said: Two vast and trunkless legs of stone");
			printf("\n   Stand in the desert. Near them on the sand,");
			printf("\n   Half sunk, a shattered visage lies, whose frown");
			printf("\n   And wrinkled lip and sneer of cold command");
			printf("\n   Tell that its sculptor well those passions read");
			printf("\n   Which yet survive, stamped on these lifeless things,");
			printf("\n   The hand that mocked them and the heart that fed.");
			printf("\n   And on the pedestal these words appear:");
			printf("\n       My name is Ozymandias, King of Kings:");
			printf("\n       Look on my works, ye mighty, and despair!");
			printf("\n   Nothing beside remains. Round the decay");
			printf("\n   Of that colossal wreck, boundless and bare");
			printf("\n   The lone and level sands stretch far away...");
			/* percy bysshe shelly */
		}
		else if( poemNum == 2 ){
			printf("\n");
			printf("\n   Some say the world will end in fire,");
			printf("\n   Some say in ice.");
			printf("\n   From what I've tasted of desire");
			printf("\n   I hold with those who favor fire.");
			printf("\n   But if it had to perish twice,");
			printf("\n   I think I know enough of hate");
			printf("\n   To say that for destruction ice");
			printf("\n   Is also great");
			printf("\n   And would suffice. ");
			/* robert frost */
		}
		else if( poemNum == 3 ){
			printf("\n");
			printf("\n   i will wade out");
			printf("\n                  till my thighs are steeped in burning flowers");
			printf("\n   I will take the sun in my mouth");
			printf("\n   and leap into the ripe air");
			printf("\n                             Alive");
			printf("\n                                  with closed eyes");
			printf("\n   to dash against darkness");
			printf("\n                          in the sleeping curves of my body");
			printf("\n   Shall enter fingers of smooth mastery");
			printf("\n   with chasteness of sea-girls");
			printf("\n                               Will i complete the mystery");
			printf("\n                               of my flesh");
			printf("\n   I will rise");
			printf("\n              after a thousand years");
			printf("\n   lipping");
			printf("\n   flowers");
			printf("\n          And set my teeth in the silver of the moon");
			/* ee cummings */
		}
		else if( poemNum == 4 ){
			printf("\n");
			printf("\n   GAILY bedight,");
			printf("\n      A gallant knight,");
			printf("\n   In sunshine and in shadow,");
			printf("\n      Had journeyed long,");
			printf("\n      Singing a song,");
			printf("\n   In search of Eldorado.");
			printf("\n");
			printf("\n      But he grew old --");
			printf("\n      This knight so bold --");
			printf("\n   And o'er his heart a shadow");
			printf("\n      Fell as he found");
			printf("\n      No spot of ground");
			printf("\n   That looked like Eldorado.");
			printf("\n");
			printf("\n      And, as his strength");
			printf("\n      Failed him at length");
			printf("\n   He met a pilgrim shadow --");
			printf("\n      'Shadow,' said he,");
			printf("\n      'Where can it be --");
			printf("\n   This land of Eldorado?'");
			printf("\n");
			printf("\n      'Over the Mountains");
			printf("\n      Of the Moon,");
			printf("\n   Down the Valley of the Shadow,");
			printf("\n      Ride, boldy ride,'");
			printf("\n      The shade replied, --");
			printf("\n   'If you seek for Eldorado!'");
			/* edgar allan poe */
		}
		else if( poemNum == 5 ){
			printf("\n");
			printf("\n   she tries to get things");
			printf("\n   out of men");
			printf("\n   that she can't get");
			printf("\n   because she's not");
			printf("\n   15 percent prettier");
			/* richard brautigan*/
		}
		else if( poemNum == 6 ){
			printf("\n");
			printf("\n   Some came in chains");
			printf("\n   Unrepentant but tired.");
			printf("\n   Too tired but to stumble.");
			printf("\n   Thinking and hating were finished");
			printf("\n   Thinking and fighting were finished");
			printf("\n   Retreating and hoping were finished.");
			printf("\n   Cures thus a long campaign,");
			printf("\n   Making death easy.");
			/* ernest hemingway */
		}
		else if( poemNum == 7 ){
			printf("\n");
			printf("\n   Unto whose use the pregnant suns are poised,");
			printf("\n   With idiot moons and stars retracting stars?");
			printf("\n   Creep thou between -- thy coming's all unnoised.");
			printf("\n   Heaven hath her high, as Earth her baser, wars.");
			printf("\n   Heir to these tumults, this affright, that fray");
			printf("\n   (By Adam's, fathers', own, sin bound alway);");
			printf("\n   Peer up, draw out thy horoscope and say");
			printf("\n   Which planet mends thy threadbare fate, or mars. ");
			/* rudyard kipling */
		}
		else if( poemNum == 8 ){
			printf("\n");
			printf("\n   I DREAMED that one had died in a strange place");
			printf("\n   Near no accustomed hand,");
			printf("\n   And they had nailed the boards above her face,");
			printf("\n   The peasants of that land,");
			printf("\n   Wondering to lay her in that solitude,");
			printf("\n   And raised above her mound");
			printf("\n   A cross they had made out of two bits of wood,");
			printf("\n   And planted cypress round;");
			printf("\n   And left her to the indifferent stars above");
			printf("\n   Until I carved these words:");
			printf("\n   'She was more beautiful than thy first love,");
			printf("\n   But now lies under boards.'");
			/* william butler yeats */
		}
		else if( poemNum == 9 ){
			printf("\n");
			printf("\n   the phone rang at 1:30 a.m.");
			printf("\n   and it was a man from Denver:");
			/* charles bukowski */
		}
		else if( poemNum == 10 ){
			printf("\n");
			printf("\n   I could not dig; I dared not rob:");
			printf("\n   Therefore I lied to please the mob.");
			printf("\n   Now all my lies are proved untrue");
			printf("\n   And I must face the men I slew.");
			printf("\n   What tale shall serve me here among");
			printf("\n   Mine angry and defrauded young?");
			/* rudyard kipling */
		}

		printf("\n\n Press 0 to return. ");
		scanf("%d", &ans);

		if( ans == 0 )
			return;

	} while( ans != 0 );

}

/*Allows player to talk to Zoltar; a mysterious, knowing character. */ /////////////////////////////////////////////// ZOLTAR
void zoltarSpeaksAignan( void ){

	int ans;

	system("cls");

	printf("\n   - Good day to you, sir. Guillame, is it?");
	printf("\n\n Would you ask how the mysterious man knew your name?  ");
	scanf("%d", &ans);
		
	if( ans == 1 ){
		system("cls");
		printf("\n   - Ah, of course. You see, I know a great many things, Guillame.");
		printf("\n   - As if by happenstance, you met your old foe Remy here - met with steel.");
		printf("\n   - Or how you once killed a man, if only for insulting your sister.");
		printf("\n   - Or even how you were once thrown out of Aignan, if only for gambling");
		printf("\n     a little too much.");
		printf("\n   - I know a great many things, Guillame...\n");
	}

	printf("\n   - What is your purpose here, hero?");
	printf("\n\n Press 0 to tell the truth.");
	printf("\n Press 1 to lie.");
	printf("\n Press 2 to remain silent.");
	printf("\n\n     ");
	scanf("%d", &ans);
	printf("\n\n");

	if( ans == 0 ){
		system("cls");
		printf("\n   - Vengeance. A modern man's drug of choice.\n\n");
	}
	if( ans == 1 ){
		system("cls");
		printf("\n   - Lying won't fool me, unfortunately. You seek Bordeaux, I know.\n\n");
	}
	if( ans == 2 ){
		system("cls");
		printf("\n   - Silence: a small man's answer. You must learn to speak your mind, Guillame.\n\n");
	}
	printf("   - Talk to the man outside, Guillame. He is important;\n");
	printf("     he will become an asset.\n");
	printf("   - Good luck on your quest. May the odds be ever in your favor,\n");
	printf("     and may your steel be ever sharp.");

	printf("\n\n Press 0 to leave. ");
	scanf("%d", &ans);
	return;

}

/*Allows player to talk to Zoltar in Aire-sure-l'Adour*/
void zoltarSpeaksAire( void ){

	int ans = 0;

	system( "cls" );

	printf("\n   - Ah, hello there, Guillame. I was wondering\n     when you'd arrive.");
	printf("\n\n Would you ask how the man got here so fast?  ");
	scanf("%d", &ans);

	if( ans == 1 ){
		system( "cls" );
		printf("\n   - Ha ha, well, Guillaume, there are many things you've\n     yet to learn.");
		printf("\n   - For instance, those men outside - why are they really arguing?");
		printf("\n   - Simple village folk rarely get into such heated debates over\n     fish.");
	}

	printf("\n\n   - Great things lie ahead, Guillaume. Great things.");
	printf("\n\n Press 0 to remain silent.");
	printf("\n Press 1 to ask about greatness.");
	printf("\n Press 2 to inquire into fish.");
	printf("\n\n     ");
	scanf("%d", &ans);

	system( "cls" );

	if( ans == 0 ){
		printf("\n   - Ah, not interested, are we? Very well.");
		printf("\n   - Continue on your quest, Guillaume.");
	}

	if( ans == 1 ){
		printf("\n   - Sic Parvis Magna, my good man - Greatness, from small beginnings.");
		printf("\n   - A motto from a very dear friend of mine, you see.");
		printf("\n   - I think you'll find it true for you, as well, in time.");
		printf("\n   - Keep on your quest. Make your way to Bordeaux. Seek your fortune.");
	}

	if( ans == 2 ){
		printf("\n   - Fish, yes. This is a riverside town, is it not?");
		printf("\n   - Hear the waters lap gently, the gulls call in the sky.");
		printf("\n   - As the sun travells, so do the fish.");
		printf("\n\n   - You see, the men here, they do not have quite enough food.");
		printf("\n   - Their farms run dead, their river losing its bounty.");
		printf("\n   - With the arrival of their dear count, they have cause for complaint.");
		printf("\n   - Maybe they'll get a settlement, or some solution to their woes?");
		printf("\n   - Or, truly, they may only receive blood.");
	}

	do{
		printf("\n   - Remember Guillaume, there are more things to life than wine and bread.");
		printf("\n\n   - Good luck on your quest. May the odds be ever in your favor,\n");
		printf("     and may your steel be ever sharp.");

		printf("\n\n Press 0 to leave. ");
		scanf("%d", &ans);
	} while( ans != 0 );
	return;

}

/*Allows player to communicate with Jean-Luc, and travel between cities*/ //////////////////////////////////////////// Jean-Luc
void jeanLuc( int inventory[], int completion[], int location[], int victories[], int notes[] ){

	int ans;

	do{

	system( "cls" );

	printf("\n Jean-Luc smiles at you from atop his carriage.");
	printf("\n\n   - Hello there, fair sir. Where can I take you?\n\n");

	if( location[0] == 1 ){
		printf(" Press 0 to stay in Aignan.\n");
		if( completion[0] == 1 ) printf(" Press 1 to travel to Aire-sur-l'Adour.\n");
		if( completion[1] == 1 ) printf(" Press 2 to travel to Mont-de-Marsan\n");
		if( completion[2] == 1 ) printf(" Press 3 to travel to Roquefort\n");
		if( completion[3] == 1 ) printf(" Press 4 to travel to Bordeaux\n");
	}

	else if( location[1] == 1 ){
		printf(" Press 0 to travel to Aignan.\n");
		printf(" Press 1 to stay in Aire-sur-l'Adour.\n");
		if( completion[1] == 1 ) printf(" Press 2 to travel to Mont-de-Marsan\n");
		if( completion[2] == 1 ) printf(" Press 3 to travel to Roquefort\n");
		if( completion[3] == 1 ) printf(" Press 4 to travel to Bordeaux\n");
	}
	
	else if( location[2] == 1 ){
		printf(" Press 0 to travel to Aignan.\n");
		printf(" Press 1 to travel to Aire-sur-l'Adour.\n");
		printf(" Press 2 to stay in Mont-de-Marsan\n");
		if( completion[2] == 1 ) printf(" Press 3 to travel to Roquefort\n");
		if( completion[3] == 1 ) printf(" Press 4 to travel to Bordeaux\n");
	}

	else if( location[3] == 1 ){
		printf(" Press 0 to travel to Aignan.\n");
		printf(" Press 1 to travel to Aire-sur-l'Adour.\n");
		printf(" Press 2 to travel to Mont-de-Marsan\n");
		printf(" Press 3 to stay in Roquefort\n");
		if( completion[3] == 1 ) printf(" Press 4 to travel to Bordeaux\n");
	}

	else if( location[4] == 1 ){
		printf(" Press 0 to travel to Aignan.\n");
		printf(" Press 1 to travel to Aire-sur-l'Adour.\n");
		printf(" Press 2 to travel to Mont-de-Marsan\n");
		printf(" Press 3 to travel to Roquefort\n");
		printf(" Press 4 to stay in Bordeaux\n");
	}

	printf("\n     ");
	scanf("%d", &ans);

	if( ans == 0 ) aignanFunction( inventory, completion, location, victories, notes );

	else if( ans == 1 ){
		if( completion[1] == 1 ) aireFunction( inventory, completion, location, victories, notes );
		else return;
	}

	else if( ans == 2 ){
		if( completion[2] == 1 ) montFunction( inventory, completion, location, victories, notes );
		else return;
	}

	else if( ans == 3 ){
		if( completion[3] == 1 ) roquefortFunction( inventory, completion, location, victories, notes );
		else return;
	}

	else if( ans == 4 ){
		if( completion[4] == 1 ) bordeauxFunction( inventory, completion, location, victories, notes );
		else return;
	}

	} while( 1 );

	return;
	
}

/*The story in Aignan*////////////////////////////////////////////////////////////////////////////////////////////////  CITY STORIES
void aignan( int inventory[], int notes[], int victories[], int completion[], int location[] ){

	int ans = 0;
	int victory = 0;
	for( ans = 0; ans < 5; ++ans ) location[ans] = 0; // sets all locations to 0, save the current
	location[0] = 1; // initializes current location (aignan)
	ans = 0; // resets ans;

	system( "cls" );

	printf("\n     * * *\n\n");
	printf(" You have walked for a few hours. You are tired. Too tired.");
	printf("\n Feet dragging in the dirt road, you see a man clad all in black approach.\n\n");
	printf("   - Guillame! I had not expected to see your ugly face back here so soon.\n\n");
	printf(" This man is Remy.\n This man is a pansy.\n You are tired, and do not want to tango with such a man.\n");

	printf("\n Would you walk away?  ");
	scanf("%d", &ans);

	if( ans == 1 )
		walkAway( inventory );

	else if( ans == 0 ){
		victory = fight( inventory, HEALTH_ENEMY );
		if( victory == 1 )
			victories[0] = victory;
	}

	if( victory == 1 ){
		system( "cls" );

		printf("\n You have vanquished your foe! Would you loot his corpse?  ");
		scanf("%i", &ans);
	

		if( ans == 1 ){
			lootCorpse( inventory );
			printf("\n Bonus! You acquired Remy's Sword!\n");
			inventory[2]++;
			printf("\n Sword now level 2 - THE BASTILLE.\n\n");
			
			printf("\n On Remy's corpse you find a small note...\n");
			notes[0]++;
		}
	}

	printf("\n     * * *\n\n");
	printf(" You leave the fool Remy behind you.\n");
	printf("\n Would you like to access your inventory?  ");
	scanf("%d", &ans);
	if( ans == 1 ) inventoryScreen( inventory, notes );

	system( "cls" );

	printf("\n Before you lies a tavern. Would you enter it?  ");
	scanf("%d", &ans);
	printf("\n   - Hey! You there! You with the sword!");
	printf("\n\n A fat man approaches, wearing a jaunty feather hat and red-striped pantalons.");
	printf("\n\n Would you ignore him, and enter the tavern?  ");
	scanf("%d", &ans);

	if( ans == 1 ){

		tavernAignan( inventory, notes );

		system( "cls" );

		printf("\n Outside, the sun shines brightly. You squint and shade your eyes.\n");
		printf(" The fat man approaches once again. He is slightly rumpled; a bit irritated.\n");
	
	}

	printf("\n   - Good sir! I apologize if I appear somewhat out of breath.\n");
	printf("   - My name is Jean-Luc.\n");
	printf("     Jean-Luc Picard, to be precise.\n");
	printf("     I am a humble traveller, by trade - a carriage driver, actually.\n");
	printf("   - I can take you many places - for a nominal fee, of course!\n\n");
	printf(" Would you ask Jean-Luc where you can go? ");
	scanf("%d", &ans);

	if( ans == 1 ){
		printf("\n   - Well, I can go many places - from here to Aire sur-l'Adour, for example.");
		printf("\n   - I also run through Mont-de-Marsan to the East, then Roquefort,");
		printf("\n     and finally Bordeaux.");
	}

	printf("\n\n   - For free, I'll take you to Aire-sur-l'Adour - I'm going there anyway.");

	if( ans == 1 ){ 
		Sleep( 6000 );
		return;
	}

	else Sleep( 1500 );

	return;

}

/*The story in Aire-sur-l'Adour*/ 
void aire( int inventory[], int notes[], int victories[], int completion[], int location[] ){
	
	int ans = 0;
	int victory = 0;
	for( ans = 0; ans < 5; ++ans ) location[ans] = 0; // sets all locations to 0, save the current
	location[1] = 1; // initializes current location (aire)
	ans = 0; // resets ans;

	do{
		system( "cls" );

		printf("\n     * * *");

		printf("\n\n Jean-Luc's carriage creaks to a halt as he gently pulls on the reigns.");
		printf("\n\n The wooden door squeaks as you push it open, your boots \n treading on the dusty road.");
		Sleep( 2000 );
		
		printf("\n\n Jean-Luc leans across his carriage bench. He says,");
		printf("\n\n   - Here we are! Aire-sur-l'Adour. Lovely little town. \n     Enjoy yourself! I'll be here when you need me.");
		
		printf("\n\n Press 1 to continue.  ");
		scanf("%d", &ans);
	} while( ans != 1 );

	do{
		system( "cls" );
	
		printf("\n The red-shingled townhomes lay before you, down a soft grassy slope\n toward the riverside.");
		printf("\n\n It really is a charming little town, you think to yourself.");
		printf("\n You listen to the chirp of birds in the springtime sun.");
		Sleep( 2500 );

		printf("\n\n Before you lies the town square.");
		printf("\n\n On your left you see the local tavern. \n A good thing, too - long rides bring a certain thirst.");
		printf("\n\n Near the center of town lies a well. \n Near that, a crowd of people has assembled.");
		printf("\n There seems to be a sort of argument afoot, with their raised voices\n carrying up the hill.");
		printf("\n\n Behind you, at the side of the road, \n Jean-Luc snores softly on his carriage bench.");
		
		printf("\n\n Press 1 to decide what to do next.  ");
		scanf("%d", &ans);
	} while( ans != 1 );

	do{
		system( "cls" );

		printf("\n Press 1 to enter the tavern.");
		printf("\n Press 2 to approach the crowd.");
		printf("\n\n     ");
		scanf("%d", &ans);
	} while( ans != 1 && ans != 2 );

	system( "cls" );

	if( ans == 1 ){
		tavernAire( inventory, notes );

		system( "cls" );

		printf("\n Outside, the sun shines brightly. You squint and shade your eyes.");
		printf("\n Gulls wheel in the sky above you. Water laps at the shore nearby.");
		printf("\n The commotion still brews near the town's central well.\n");
	}

	printf("\n The crowd yells abuse and general rudeness as two men and one woman argue in its centre.");

}

void mont( int inventory[], int notes[], int victories[], int completion[], int location[] ){} // make this rainy
void roquefort( int inventory[], int notes[], int victories[], int completion[], int location[] ){}
void bordeaux( int inventory[], int notes[], int victories[], int completion[], int location[] ){}

/*Allows player to dick around in Aignan */ ////////////////////////////////////////////////////////////////////////////// CITIES
void aignanFunction( int inventory[], int completion[], int location[], int victories[], int notes[] ){

	int ans;
	int victory;

	do{

		system("cls");

		printf("\n Aignan - a beautiful, sunny, riverside town.");
		printf("\n          white chateaus with gray slate roofs adorn");
		printf("\n          the rolling green countryside.");

		printf("\n\n Press 0 to speak to Jean-Luc.");
		printf("\n Press 1 to enter the Tavern.");
		printf("\n Press 2 to view inventory.");
		if( victories[0] == 0 )
			printf("\n Press 3 to fight Remy.");
		printf("\n\n     ");
		scanf("%d", &ans);

		if( ans == 0 )
			return;

		if( ans == 1 )
			tavernAignan( inventory, notes );

		if( ans == 2 )
			inventoryScreen( inventory, notes );

		if( ans == 3 && victories[0] == 0 ){
			
			victory = fight( inventory, HEALTH_ENEMY );
			
			if( victory == 1 ){
				system( "cls" );

				victories[0] = victory;

				printf("\n You have vanquished your foe! Would you loot his corpse?  ");
				scanf("%i", &ans);
	

				if( ans == 1 ){
					lootCorpse( inventory );
					printf("\n Bonus! You acquired Remy's Sword!\n");
					inventory[2]++;
					printf("\n Sword now level 2 - THE BASTILLE.\n\n");
			
					printf("\n On Remy's corpse you find a small note...\n");
					notes[0]++;

					Sleep( 4000 );
				}
			}
		}


	} while( ans != 0 );

}
void aireFunction( int inventory[], int completion[], int location[], int victories[], int notes[] ){}
void montFunction( int inventory[], int completion[], int location[], int victories[], int notes[] ){}
void roquefortFunction( int inventory[], int completion[], int location[], int victories[], int notes[] ){}
void bordeauxFunction( int inventory[], int completion[], int location[], int victories[], int notes[] ){}

