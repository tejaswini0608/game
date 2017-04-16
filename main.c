
#include <stdio.h>          // the libraries used in the coding
#include <stdlib.h>
#include "crossfireOperations.h" //inclusion of file crossfireOperations.h
#include<string.h>
#include<time.h>     
#include<stdbool.h>
#define NUM -1





int main(){
	
	
	//players
	int a;
	
	printf("Input the maximum number of players 1-6"); //input the total number of players by the user
	scanf("%d",&a);                                  //scan in the number of players inputted by the user

	

	
     //players
	 
	 //the numbering of the player starts from 0
	 int x,k,b,c,d; 
		


		  for(x=0;x<a;x++)                        //for loop that runs for each player
		  {
			  printf("enter the name of the player %d ",x);  //takes in the name of the player
			  scanf("%s",player[x].name);                   
			  printf("enter the type of the player:Elf, Human, Ogre, Wizard-");//takes in the type of the player
			  scanf("%s",player[x].type);
			  player[x].Lifepoints=100;          //takes input for the lifepoints of the player.This is initialised to 100.
		 // }
			 char str2[]="Elf";
			 k=strcmp(player[x].type,str2);         
													 /*strcmp compares the 2 strings and prints out a 0 if they are both equal.This is used here so that the characteristics of a
													  particular player type is dislayed ..according to the input of the player type  by the user*/
			 b=strcmp(player[x].type,"Human");       
			 c=strcmp(player[x].type,"Wizard");
			 d=strcmp(player[x].type,"Ogre");
		 
		 
		 
			  //for(x=0;x<=a;x++)
	 
		if(k==0)                                 /*if k=o,that is if the user iputted the player type as elf then the characteristics of elf dislays*/
		{
			player[x].Luck=rand()%(100 + 1 - 60) + 60;  /*characteristics of the player type elf that is assigned as a random integer in the given range*/
			player[x].Smartness=70+rand()%30;
			player[x].Strength=rand()%50;
			player[x].MagicSkills=50+rand()%29;
			player[x].Dexterity=rand()%100;

		}
		 
		 else if(b==0)
		 {                                     /*if b=o,that is if the user iputted the player type as human then the characteristics of human dislays*/
			player[x].Luck=rand()%100;         /*characteristics of the player type human  is assigned as a random integer in the given range*/
			player[x].Smartness=rand()%100;
			player[x].Strength=rand()%100;
			player[x].MagicSkills=rand()%100;
			player[x].Dexterity=rand()%100;

			 int t=(player[x].Luck+player[x].Smartness+player[x].Strength+player[x].MagicSkills);
			 while(t>300)
												 /*if the sum of luck,smartness,strength and magicskills exceeds 300 then it reassigns the value randomly..condition given by the professor*/
			 {
				 player[x].Luck=rand()%100;      // using while loop so that it iterates until the condition is satisfied
				 player[x].Smartness=rand()%100;
				 player[x].Strength=rand()%100;
				 player[x].MagicSkills=rand()%100;
				 t=(player[x].Luck+player[x].Smartness+player[x].Strength+player[x].MagicSkills);
			   //  break;
					
			 }			 
		 }
		 
		 else if(c==0)                    /*if c=o,that is if the user iputted the player type as wizard then the characteristics of wizard dislays*/
		{
			player[x].Luck=50+rand()%50;   /*characteristics of the player type wizard is assigned as a random integer in the given range*/
			player[x].Smartness=90+rand()%10;
			player[x].Strength=rand()%20;
			player[x].MagicSkills=80+rand()%20;
			player[x].Dexterity=rand()%100;

		}
		
		else if(d==0)
		{                                    /*if d=o,that is if the user iputted the player type as ogre then the characteristics of ogre dislays*/
			player[x].Luck=rand()%100;      /*characteristics of the player type ogre is assigned as a random integer in the given range*/
			player[x].Smartness=rand()%20;
			player[x].Strength=80+rand()%20;
			player[x].MagicSkills=0;
			player[x].Dexterity=80+rand()%20;
			int k=player[x].Luck+player[x].Smartness;  // if the sum of luck and smartness is greater than 50 then it should reassign the values
			while (k>50)
			  {                                     // using while loop so that it iterates until the condition is satisfied
						player[x].Luck=rand()%100;
						player[x].Smartness=rand()%20;
						k=player[x].Luck+player[x].Smartness;

			}
		}
			
			//printing the name,type ,life pionts and the characteristics of the player
			
			printf("\n  %s ( %s ,%d)",player[x].name,player[x].type,player[x].Lifepoints);
			printf("\n Luck=%d\n",player[x].Luck);
			printf("\n smartness=%d\n",player[x].Smartness);
			printf("\n strength=%d\n",player[x].Strength);
			printf("\n MagicSkills=%d\n",player[x].MagicSkills);
			printf("\n Dexterity=%d\n",player[x].Dexterity);			

	   
	 }
	 
	 
	//slots
	int i,j,type;
		

	for(i=0;i<7;i++) 
        {
       for(j=0;j<7;j++)
		 {   type = rand()%3;                //choose a random integer between 0-2
			arrSlots[i][j].type = type;       //assigning a type randomly to each slot
			arrSlots[i][j].playernum = NUM;   //making the playernum=-1
		 }
		}
		
		printf("\n slots:ground=0 hill=1 city=2\n"); //the types of slots
		
	for(i =0; i <7; i++)            //printing the type of slots assigned to the entire board
	{
		for(j=0;j<7;j++)
		{
			printf(" (%d,%d)=%d \n",i,j, arrSlots[i][j].type);
		}
	}
    	printf("\n");
		
		
		//Assigning each player to a Slot randomly
		int num1,num2;
		 int arrayrow[10],arraycolumn[10];
		 int remaining_players=a;
		 //sets all the slots to number -1 initially which is increaded to 1 if the player is assigned to that slot
		 for(i=0;i<7;i++)                      
		 {
			 for(j=0;j<7;j++)
			 {
				 arrSlots[i][j].player_in_slot=-1;
				// printf("%d",arrSlots[i][j].player_in_slot);
			 }
		 }
	if(a<1)     //declaring a condition to start the game only if there are more than 1 player
	{
		printf("not enough players to start the game");
	}	
  
  
            for(i = 0; i<a; i++)    //assign a player to a slot randomly
				{	
								 do
								 {
								 num1=rand()% 7;     //choose a random number between 0-6
			
								 num2=rand()% 7;
								} 
								while(arrSlots[num1][num2].playernum != NUM);//checks if the player number is not equal to -1
											  
								arrSlots[num1][num2].playernum = i; 
								arrayrow[i]=num1;          //row player i is assigned to
								arraycolumn[i]=num2;       //column player i is assigned to
								printf("slot (%d,%d)  player %d\n",num1,num2, arrSlots[num1][num2].playernum);
							   arrSlots[num1][num2].player_in_slot=1;//if the player is present in slot=player_in_slot=1 else where its -1
				  }        
				  
				  /*		arrSlots[1][1].playernum = 0;
							printf("slot (1,1)  player %d\n", arrSlots[1][1].playernum);
							   arrSlots[1][1].player_in_slot=1;

								
								arrSlots[0][1].playernum = 1;
								printf("slot (1,2)  player %d\n", arrSlots[0][1].playernum);
							   arrSlots[0][1].player_in_slot=1;
				       */
					   
					   
					   
    while(a>1 && remaining_players>1 )    //if the number of players is greater than 1 then only the game continues
   {
			     

			int row, column;
		 
			
			for(int i=0;i<a;i++ )//to run a loop where a=total num of players
			{
					row=arrayrow[i];
					slot[i].row=arrayrow[i];
					column=arraycolumn[i];
					slot[i].column=arraycolumn[i];
					int player_number=i;
					
					struct slot* currSlot = NULL;
					struct slot *foundSlots;
					bool explored[BOARD_SIZE][BOARD_SIZE];
					int count =0;

					//pointer to slot (0,0)
					struct slot *upLeft;

					//pointer to slot (0,boardSize -1)
					struct slot *upRight;

					//pointer to slot (boardSize - 1, 0)
					struct slot *downLeft;

					//pointer to slot (boardSize - 1, boardSize -1)
					struct slot *downRight;


								//Creates the board
								createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight);
								/*	getDesiredElement(BOARD_SIZE, &row,&column,arrayrow[i],arraycolumn[j]);

								//Finds the slot

                 
								/*If the the required slot is closer to the down-right
								 * corner of the board the search starts from downRight,
				 * which points to slot at position (boardSize-1, boarSize -1)*/

				 
				 
				 //decide whether the player wants to move or attack or quit
								printf("\n enter one of the following for player %d \n 1=move to adjacent slot \n 2=attack 3=quit the game\n",i);
								int num_entered;
							scanf("%d",&num_entered);
							
							if(num_entered==1)       //if number entered is 1 then the player moves
							{
								   
		                      move(row,column,i);   //move function that takes in 3 arguments-row,column and player number
	
								
							}
							if(num_entered==2)   //if number entered is 1 then the player moves
							{
								
								printf("the player can perform 3 types of attcks\n 1=near attack \n 2=distant attack\n 3=magic attck\n");
								int no;                //the player chooses from 3 types of attacks
								scanf("%d",&no);
								
								if(no==1)            // no=1 means near attack
								{
									int attacked=-1;
								 nearattack(row,column,i,attacked);  //near attack function is called 
								 
								
								}
								
								if(no==2)       //no=2 distant attack
								{
									 if(row >= BOARD_SIZE/2){
									if(column >= BOARD_SIZE/2)
										currSlot = reachDesiredElement(row,column,downRight);
									else
									/*If the the required slot is closer to the down-left
									* corner of the board the search starts from downLeft,
									* which points to slot at position (boardSize-1, 0)*/
										currSlot = reachDesiredElement(row,column,downLeft);
								} else {
									/*If the the required slot is closer to the up-right
									* corner of the board the search starts from upRight,
									* which points to slot at position (0, boarSize -1)*/
									if(column >= BOARD_SIZE/2)
										currSlot = reachDesiredElement(row,column, upRight);
									/*If the the required slot is closer to the up-left
									* corner of the board the search starts from upLeft,
									* which points to slot at position (0, 0)*/
								else currSlot = reachDesiredElement(row,column,upLeft);
								
								for(int m=0; m<BOARD_SIZE; m++){         //set all explored[][]=false
									for(int j=0; j<BOARD_SIZE;j++){
										explored[i][j] = false;
									}
								}

								foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
								printf("\n\nFunction findSlotsinvoked:\n");
								

								if(currSlot!= NULL)
								{
									//invokes function findSlots. The required distance is a constant
									//However you can reuse this function providing as input any arbitrary distance
									findSlots(REQ_DISTANCE, 1, currSlot, foundSlots, &count, explored);
									int m=0;
									for( m=0; m<count; m++)
									{
										printf("(%d, %d)-> ",foundSlots[m].row, foundSlots[m].column);
									}
								}
								//printf("check 1");
								int count1=0,number[6],m;
								for(m=0;m<6;m++)      //loop to set all values of number[] tp -1
								{
									number[m]=-1;
								}
								for(int m=0;m<7;m++)
								{
									for(j=0;j<7;j++)
									{
										if(arrSlots[m][j].player_in_slot== 1)  //if the player is present in the slot
										{
									     	if(slot[j].row==foundSlots[j].row && slot[j].column==foundSlots[j].column)//if the slot of the player and that of found slots are both same
											{
												 
												number[count]=arrSlots[m][j].playernum;//number array fills in the number of player//the numbering of players start from 0
												count1++;
											}
	
										}
									}
								}
								if(count1>0)     //if there is atleast 1 player found
								{
									printf("\nchoose the player to attack from the following\n");
                                    for(m=0;m<6;m++)
									{
										if(number[m]!=-1)
										{
										
											printf("%d",number[m]); //prints the number of player u can attack
										}
									}
									printf("\nenter the number of the player u wanna attack\n");
									int number_player;
									scanf("%d",&number_player);    //scans in the number of player that is attacked
									after_dist_attack(i,number_player); //calling of function after distance attack
									
								}
								
	                           
								
							}
									
									
								}
								
								if(no==3)              //if n0=3 then magic attack is performed
								{
									magic_attack(row,column,i,a);//calling of function magic attack
								}
								
		                     
								}

								
							
							if(num_entered==3)             //if num_entered=3,then the player has decided to quit the game
							{
								   
		                      printf("player has decided to quit the game");
							  remaining_players=remaining_players-1;
	
								
							}
							
							
						//remaining_player_fun(remaining_players,i);//remaining player function is called to check the number of remaining players
						
						
						//checks the number of remaining player
						if(player[i].Lifepoints==0)
	                    {
		               remaining_players=remaining_players-1;
		 
	                     }
	// return remaining_players;
								if(remaining_players<=1)
								{
									printf("\nthe game ends as not enough players\n");
									break;
								}
			}
     }	
			return 0;
}
	
	
		void after_dist_attack(int i,int attacked)//distance attack function
		{
			if(player[attacked].Dexterity >=player[i].Dexterity ) //if the dexterity of attacked player is greater than that of the attacking player the following happens
			{
				printf("\nthe lifepoints of attacked player is unchanged = %d\n ",player[attacked].Lifepoints);
			}

			else if(player[attacked].Dexterity < player[i].Dexterity)//if the dexterity of attacked player is less than that of the attacking player the following happen
			{
				player[attacked].Lifepoints =player[attacked].Lifepoints- (player[i].Strength*0.3);
			}
			
			printf("\nname and lifepoints of the player after distant attack \n");
			printf("\n  %s ( %s ,%d)",player[i].name,player[i].type,player[i].Lifepoints);
			
			
			printf("\nlifepoints of attacked player after distant attack\n");
			printf("\n  %s ( %s ,%d)",player[attacked].name,player[attacked].type,player[attacked].Lifepoints);
		}

	
 void move(int row,int column,int i)//move function
 {
	                int numb;
					//case 1-4 checks the corner, 5-8: checks the sides  ,9 checks elsewhere
					
					
					
					//case1--move: if the player is in the position(0,0)
								if(slot[i].row==0 && slot[i].column==0)
								{
									
									printf("the player is in leftup corner:can move down=0 or right=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==1)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									
									newabilities(row,column,i);//new abilities function is called
								}      

								
								
                     //case2-=if the player is in(6,0)	
                              				
								else if(slot[i].row==6 && slot[i].column==0)
								{
									
									printf("the player is in leftdown corner:can move up=0 or right=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==1)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);//new abilities function is called
								}      
								
								
								
							//case3:player is in (0,6)
							else if(slot[i].row==0 && slot[i].column==6)
								{
									
									printf("the player is in rightup corner:can move left=0 or down=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==1)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column); //prints the new position of the player after moving
									}
									newabilities(row,column,i);//new abilities function is called
								} 
								
								
								
								//case4:player is in (6,6)
							else if(slot[i].row==6 && slot[i].column==6)
								{
									
									printf("the player is in rightdown corner:can move left=0 or up=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);//new abilities function is called
								} 
								
								
								
								//case5:player is in row 1 other than the corners
							else if(slot[i].row==0 && slot[i].column!=6 && slot[i].column!=0)
								{
									
									printf("the player is in 1st row other than the corners:can move \nleft=1 or down=2 or right=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==2)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									else if(numb==3)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);//new abilities function is called
								} 
								
								
								//case6:player is in column 1 other than the corners
							 else if(slot[i].column==0 && slot[i].row!=6 && slot[i].row!=0)
								{
									
									printf("the player is in 1st column other than the corners:can move \nup=1 or right=2 or down=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==2)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									else if(numb==3)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);        //new abilities function is called
								} 
								
								
								//case7:player is in row6 other than the corners
							 else if(slot[i].row==6 && slot[i].column!=6 && slot[i].column!=0)
								{
									
									printf("the player is in 6th row other than the corners:can move \n left=1 or up=2 or right=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==2)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									else if(numb==3)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);      //new abilities function is called
								} 
								
								
								
								
								//case8:player is in column 6 other than the corners
							 else if(slot[i].column==6 && slot[i].row!=6 && slot[i].row!=0)
								{
									
									printf("the player is in 6th column other than the corners:can move \nup=1 or left=2 or down=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==2)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									else if(numb==3)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);//new abilities function is called
								} 
								
								
								
								
								//case9:player is in column 1-5 and row 1-5
								//int numbering;
								//numbering=1 || 2|| 3|| 4|| 5;
							   else //if(slot[i].column==numbering && slot[i].row==numbering )
								{
									
									printf("the player has 4 neighbours:can move \nup=1 or left=2 or down=3 or right=4 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
										
									}
									else if(numb==2)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									else if(numb==3)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									else if(numb==4)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);//prints the new position of the player after moving
									}
									newabilities(row,column,i);      //new abilities function
								} 

                  

											
 } 
 
void newabilities(int row,int column,int i)
 {
	        // the change of abilities due to moving
			
							if(arrSlots[row][column].type==0)//if the player moves to slot type ground
									{
										printf("the player moves to ground-the capabilities are unchanged");
									}
									
									
									else if(arrSlots[row][column].type==1)//if the player moves to slot type hill
									{
										printf("the player moves to slot_type hill");
										if(player[i].Dexterity<50)
										{
											player[i].Strength=player[i].Strength-10;
										}
										else if(player[i].Dexterity>=60)
										{
											player[i].Strength=player[i].Strength+10;
										}
									}
									
									
									else if(arrSlots[row][column].type==2)//if the player moves to slot type hill
									{
										printf("the player moves to slot_type city");
										if(player[i].Smartness>60)
										{
											player[i].MagicSkills=player[i].MagicSkills+10;
										}
										else if(player[i].Smartness<=50)
										{
											player[i].Dexterity=player[i].Dexterity-10;
										}
									}
									
									
									//prints the characteristics of the players
									
			printf("\n  %s ( %s ,%d)",player[i].name,player[i].type,player[i].Lifepoints);
			printf("\n Luck=%d\n",player[i].Luck);
			printf("\n smartness=%d\n",player[i].Smartness);
			printf("\n strength=%d\n",player[i].Strength);
			printf("\n MagicSkills=%d\n",player[i].MagicSkills);
			printf("\n Dexterity=%d\n",player[i].Dexterity);
 }
 
 
 
 //remaining player function-if the lifepoint of a player =0 then that person quits the game
// int remaining_player_fun(int remaining_players,int i) 
 //{
	 
 //}

 
 //function magic attacks 
 void magic_attack(int row,int column,int i,int a)
	{
		if(player[i].Smartness+player[i].MagicSkills>150)     //checks if the magic attack can be performed
		{
			printf("enter the player u wanna attack 0-%d",a-1);    //choose the player u wanna attack
			
              int attacked;
		        scanf("%d",&attacked);                   //takes in the player to attack
				player[attacked].Lifepoints = player[i].MagicSkills*0.5+player[i].Smartness*0.2;//the lifepoints of the attacked player changes
			
			printf("\nname and lifepoints of the player after magic attack \n");
			printf("\n  %s ( %s ,%d)",player[i].name,player[i].type,player[i].Lifepoints);
			
			
			printf("\nlifepoints of attacked players after magic attack\n");
			printf("\n  %s ( %s ,%d)",player[attacked].name,player[attacked].type,player[attacked].Lifepoints);
			
			
			
		}
		else
		{
			printf("the player cannot perform this attack");
		}
	}
	
	
	//near attack function
	void nearattack(int row,int column,int i,int attacked)  
	{
		
		printf("the player can attack the following players");
		int arr[4],j;
		for(j=0;j<4;j++)           //fills all elements in arr[]=-1
		{
			arr[j]=-1;
		}
		int count=0;
		//checks if there is a player in the slot above-here row cannot be 0 as there is no up row if the row is initially 0 
		 if(row!=0 && arrSlots[row-1][column].player_in_slot== 1  )
		{
			printf("\nthe player can attack the player above-player number: %d \n",arrSlots[row-1][column].playernum);
			arr[0]=arrSlots[row-1][column].playernum; //stores the playernum in that slot
			count++;
			attacked=arr[0];                    
		}
		
		//checks if there is a player in the left slot-here column cannot be 0 as there is no left column if the column is initially 0 

		else if(column!=0 && arrSlots[row][column-1].player_in_slot==1  )
		{
			printf("\nthe player can attack the player left :player %d\n",arrSlots[row][column-1].playernum);
			arr[1]=arrSlots[row][column-1].playernum;//stores the playernum in that slot
			count++;
			attacked=arr[1];
		}
		
		//checks if there is a player in the down slot-here row cannot be 6 as there is no below row if the row is initially 6 

		else if( row!=6 && arrSlots[row+1][column].player_in_slot==1  )
		{
			printf("\nthe player can attack the player down :player %d\n",arrSlots[row+1][column].playernum);
			arr[2]=arrSlots[row+1][column].playernum;//stores the playernum in that slot
		count++;
		  attacked=arr[2];
		}
		
				//checks if there is a player in the right slot-here column cannot be 6 as there is no right column if the column is initially 6 

		else if( column!=6 && arrSlots[row][column+1].player_in_slot==1  )
		{
			printf("\nthe player can attack the player right:player %d\n",arrSlots[row][column+1].playernum);
			arr[3]=arrSlots[row][column+1].playernum;  //stores the playernum in that slot
			count++;
			attacked=arr[3];
		}
		
		//if no neighbouring players are found
		else
		{
			printf("\n no neighbouring players found,cannot perform this attack\n");
		}
		
		int num;
		printf("possible attacks to players:");
		for(j=0;j<4;j++)
		{
		if(arr[j]!=-1)       //arr[] had stored in the playernum of the adjacent players
		printf("%d",arr[j]); //prints the playernum of all neighbouring players
	    
		
		}
		if(count>1)       //if more than 1 player is found
		{
		scanf("%d",&num);//takes in the number of player as input
		attacked=num;
		}
	     //printf("checking if the atttacked player is right %d",attacked);
		 //printf("enter the value of i %d",i);
		if(attacked!=-1)
		{
				after_near_attack(i,attacked);         //near attack function is called
		}
		printf("\n.......near attack end ..........\n");
	}
	
	
	
	//near attack function
	void after_near_attack(int i,int attacked)
	{
		
			if(player[attacked].Strength <= 70) //if the strenghth points of the attacked player is less than or equal to 70 the following takes place 
			{
				player[attacked].Lifepoints=player[attacked].Lifepoints-(player[i].Strength*0.5);
			}

			else if(player[attacked].Strength > 70)//if the strenghth points of the attacked player is greater 70 the following takes place
			{
				player[i].Lifepoints =player[i].Lifepoints- player[attacked].Strength*0.3;
			}
			
			printf("\nname and lifepoints of the player after near attack \n");
			printf("\n  %s ( %s ,%d)",player[i].name,player[i].type,player[i].Lifepoints);//prints the lifepoints of both the players
			
			
			printf("\nlifepoints of attacked players\n");
			printf("\n  %s ( %s ,%d)",player[attacked].name,player[attacked].type,player[attacked].Lifepoints);
			
		
	}
	
	
 
 
 
 
 
 
 
 
 
 
 
 
