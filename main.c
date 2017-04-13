/*
 * main.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */


#include <stdio.h>
#include <stdlib.h>
#include "crossfireOperations.h"
#include<string.h>
#include<time.h>     // the libraries used in the coding
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
		{   type = rand()%3;
			arrSlots[i][j].type = type;
			arrSlots[i][j].playernum = NUM;
		}
		}
		
		printf("\n slots:ground=0 hill=1 city=2\n");
		
		for(i =0; i <7; i++)  
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
	if(a<1)
	{
		printf("not enough players to start the game");
	}	


   if(a>=1 && remaining_players>=1 ){
			 for(i = 0; i<a; i++)
				{	
								 do
								 {
								 num1=rand()% 7;
			
								 num2=rand()% 7;
								} 
								while(arrSlots[num1][num2].playernum != NUM);
											  
								arrSlots[num1][num2].playernum = i;
								arrayrow[i]=num1;
								arraycolumn[i]=num2;
								printf("slot (%d,%d)  player %d\n",num1,num2, arrSlots[num1][num2].playernum);
							   arrSlots[num1][num2].player_in_slot=1;
				  }            
                 			  
						/*		arrSlots[1][1].playernum = 0;
							printf("slot (1,1)  player %d\n", arrSlots[1][1].playernum);
							   arrSlots[1][1].player_in_slot=1;

								
								arrSlots[0][1].playernum = 1;
								printf("slot (1,2)  player %d\n", arrSlots[0][1].playernum);
							   arrSlots[0][1].player_in_slot=1;
				       */



			int row, column;
		 
			
			for(int i=0;i<a;i++ )
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

								printf("\n enter one of the following for player %d \n 1=move to adjacent slot \n 2=attack 3=quit the game\n",i);
								int num_entered;
							scanf("%d",&num_entered);
							
							if(num_entered==1)
							{
								   
		                      move(row,column,i);
	
								
							}
							if(num_entered==2)
							{
								
								printf("the player can perform 3 types of attcks\n 1=near attack \n 2=distant attack\n 3=magic attck\n");
								int no;
								scanf("%d",&no);
								
								if(no==1)
								{
									int attacked=-1;
								 nearattack(row,column,i,attacked);
								 
								
								}
								
								if(no==2)
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
								
								for(int i=0; i<BOARD_SIZE; i++){
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
									findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
									for(int i=0; i<count; i++)
									{
										printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
									}
								}
								
	
								
							}
									
									
								}
								
								if(no==3)
								{
									magic_attack(row,column,i,a);
								}
								
		                     
								}

								
							
							if(num_entered==3)
							{
								   
		                      printf("player has decided to quit the game");
							  remaining_players=remaining_players-1;
	
								
							}
							
								
								
						
								
							
						remaining_player_fun(remaining_players,i);
								
			}
     }	
			return 0;
}
	
	
	
	
 void move(int row,int column,int i)
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
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==1)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									
									newabilities(row,column,i);
								}      

                     //case2-=if the player is in(6,0)	
                              				
								else if(slot[i].row==6 && slot[i].column==0)
								{
									
									printf("the player is in leftdown corner:can move up=0 or right=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==1)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								}      
								
							//case3:player is in (0,6)
							else if(slot[i].row==0 && slot[i].column==6)
								{
									
									printf("the player is in rightup corner:can move left=0 or down=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==1)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								} 
								
								//case4:player is in (6,6)
							else if(slot[i].row==6 && slot[i].column==6)
								{
									
									printf("the player is in rightdown corner:can move left=0 or up=1");
									
									scanf("%d",&numb);
									if(numb==0)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								} 
								
								//case5:player is in row 1 other than the corners
							else if(slot[i].row==0 && slot[i].column!=6 && slot[i].column!=0)
								{
									
									printf("the player is in 1st row other than the corners:can move \nleft=1 or down=2 or right=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==2)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									else if(numb==3)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								} 
								//case6:player is in column 1 other than the corners
							 else if(slot[i].column==0 && slot[i].row!=6 && slot[i].row!=0)
								{
									
									printf("the player is in 1st column other than the corners:can move \nup=1 or right=2 or down=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==2)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									else if(numb==3)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								} 
								//case7:player is in row6 other than the corners
							 else if(slot[i].row==6 && slot[i].column!=6 && slot[i].column!=0)
								{
									
									printf("the player is in 6th row other than the corners:can move \n left=1 or up=2 or right=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==2)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									else if(numb==3)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								} 
								//case8:player is in column 6 other than the corners
							 else if(slot[i].column==6 && slot[i].row!=6 && slot[i].row!=0)
								{
									
									printf("the player is in 6th column other than the corners:can move \nup=1 or left=2 or down=3 ");
									
									scanf("%d",&numb);
									if(numb==1)
									{
										slot[i].row--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==2)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									else if(numb==3)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
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
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
										
									}
									else if(numb==2)
									{
										slot[i].column--;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									else if(numb==3)
									{
										slot[i].row++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									else if(numb==4)
									{
										slot[i].column++;
										printf("the new slot(%d,%d)",slot[i].row,slot[i].column);
									}
									newabilities(row,column,i);
								} 

                  

											
 } 
 
void newabilities(int row,int column,int i)
 {
	        // the change of abilities due to moving
							if(arrSlots[row][column].type==0)
									{
										printf("the player moves to ground-the capabilities are unchanged");
									}
									
									else if(arrSlots[row][column].type==1)
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
									
									else if(arrSlots[row][column].type==2)
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
			printf("\n  %s ( %s ,%d)",player[i].name,player[i].type,player[i].Lifepoints);
			printf("\n Luck=%d\n",player[i].Luck);
			printf("\n smartness=%d\n",player[i].Smartness);
			printf("\n strength=%d\n",player[i].Strength);
			printf("\n MagicSkills=%d\n",player[i].MagicSkills);
			printf("\n Dexterity=%d\n",player[i].Dexterity);
 }
 int remaining_player_fun(int remaining_players,int i)
 {
	 if(player[i].Lifepoints==0)
	 {
		 remaining_players=remaining_players-1;
	 }
	 return remaining_players;
 }

 
 
 void magic_attack(int row,int column,int i,int a)
	{
		if(player[i].Smartness+player[i].MagicSkills>150)
		{
			printf("enter the player u wanna attack 0-%d",a-1);
			
              int attacked;
		        scanf("%d",&attacked);
				player[attacked].Lifepoints = player[i].MagicSkills*0.5+player[i].Smartness*0.2;
			
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
	void nearattack(int row,int column,int i,int attacked)
	{
		
		printf("the player can attack the following players");
		int arr[4],j;
		for(j=0;j<4;j++)
		{
			arr[j]=-1;
		}
		int count=0;
		 if(row!=0 && arrSlots[row-1][column].player_in_slot== 1  )
		{
			printf("\nthe player can attack the player above-player number: %d \n",arrSlots[row-1][column].playernum);
			arr[0]=arrSlots[row-1][column].playernum;
			count++;
			attacked=arr[0];
		}
		
		else if(column!=0 && arrSlots[row][column-1].player_in_slot==1  )
		{
			printf("\nthe player can attack the player left :player %d\n",arrSlots[row][column-1].playernum);
			arr[1]=arrSlots[row][column-1].playernum;
			count++;
			attacked=arr[1];
		}
		else if( row!=6 && arrSlots[row+1][column].player_in_slot==1  )
		{
			printf("\nthe player can attack the player down :player %d\n",arrSlots[row+1][column].playernum);
			arr[2]=arrSlots[row+1][column].playernum;
		count++;
		  attacked=arr[2];
		}
		else if( column!=6 && arrSlots[row][column+1].player_in_slot==1  )
		{
			printf("\nthe player can attack the player right:player %d\n",arrSlots[row][column+1].playernum);
			arr[3]=arrSlots[row][column+1].playernum;
			count++;
			attacked=arr[3];
		}
		else{
			printf("\n no neighbouring players found,cannot perform this attack\n");
		}
		
		int num;
		printf("possible attacks to players:");
		for(j=0;j<4;j++)
		{
		if(arr[j]!=-1)
		printf("%d",arr[j]);
	    
		
		}
		if(count>1)
		{
		scanf("%d",&num);
		attacked=num;
		}
	     //printf("checking if the atttacked player is right %d",attacked);
		 //printf("enter the value of i %d",i);
		if(attacked!=-1)
		{
				after_near_attack(i,attacked);
		}
		printf(".......near attack end ..........");
	}
	void after_near_attack(int i,int attacked)
	{
		
			if(player[attacked].Strength <= 70)
			{
				player[attacked].Lifepoints=player[attacked].Lifepoints-(player[i].Strength*0.5);
			}

			else if(player[attacked].Strength > 70)
			{
				player[i].Lifepoints =player[i].Lifepoints- player[attacked].Strength*0.3;
			}
			
			printf("\nname and lifepoints of the player after near attack \n");
			printf("\n  %s ( %s ,%d)",player[i].name,player[i].type,player[i].Lifepoints);
			
			
			printf("\nlifepoints of attacked players\n");
			printf("\n  %s ( %s ,%d)",player[attacked].name,player[attacked].type,player[attacked].Lifepoints);
			
		
	}
	
	/*int playercanattack(int row,int column,int i,int attacker)
	{
		
		return attacker;
	}
	*/
 
 
 
 
 
 
 
 
 
 
 
 
