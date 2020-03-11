
#include "systemc.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
#define ROW 4
#define COL 4

int es_y,es_x, pf_y, pf_x, ptemp_y, ptemp_x, pnull_y, pnull_x;
string puzzle[ROW][COL];
void displayParkingLayout (string value[ROW][COL]);
void performLEFT();
void performUP();
void performRIGHT();
void performDOWN();
void assignCarNumber();
void performNext();


using namespace std;

// sc_main in top level function like in C++ main
int sc_main(int argc, char* argv[]) {

	string option, answer;
	int count = 0;
	int difference;

	for(int i = 0; i < ROW;i++)
	{
		for(int j = 0; j < COL;j++)
		{
			puzzle[i][j] = "--";

		}
	}


	es_y = 3;
	es_x = 1;
	pf_y = 3;
	pf_x = 0;
	puzzle[es_y][es_x] = " E";
	puzzle[pf_y][pf_x] = "  ";
	displayParkingLayout(puzzle);


	while(count < 16)
	{
		cout<<" Enter command P: Parking R: Retrieval\n";
		cin>>option;

		if(option=="P")
		{
			count++;

			if(count > 15)
			{
				count--;
				printf("\nParking full\n");
			}
		}


		if(option == "R")
		{

			if (count == 0)
			{
				cout<<"\nInvalid\n";
			}

			if(count > 0)
			{

				cout<<"\nPress Car No. to be retrieved: \n";
				cin>>answer;
				if(!answer.compare("1")) answer = " 1";
				if(!answer.compare("2")) answer = " 2";
				if(!answer.compare("3")) answer = " 3";
				if(!answer.compare("4")) answer = " 4";
				if(!answer.compare("5")) answer = " 5";
				if(!answer.compare("6")) answer = " 6";
				if(!answer.compare("7")) answer = " 7";
				if(!answer.compare("8")) answer = " 8";
				if(!answer.compare("9")) answer = " 9";


				for(int i = 0; i < ROW;i++)
				{  for(int j = 0; j < COL;j++)
				{
					if(!puzzle[i][j].compare(answer))           /* In order to use the same loop as for parking assign the car to be retrieved as pf */
					{
						pf_y = i;
						pf_x = j;
					}
					if(!puzzle[i][j].compare(" E"))
					{
						es_y = i;
						es_x = j;
					}
				}
				}

			}
		}

		difference = pf_y - pf_x;

		while(difference != 3)
		{
			if (es_y == 3 && es_x == 1 && pf_y == 2 && pf_x == 0)
			{
				performLEFT();  displayParkingLayout(puzzle);
				performUP();    displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 2 && pf_x == 1)
			{
				performRIGHT();  displayParkingLayout(puzzle);
				performDOWN();   displayParkingLayout(puzzle);
				performLEFT();   displayParkingLayout(puzzle);
				performUP();     displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if(es_y == 2 && es_x == 0 && pf_y == 3 && pf_x == 1)
			{
				performDOWN();
				displayParkingLayout(puzzle);
				performRIGHT();
				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;

			}

			else if (es_y == 3 && es_x == 1 && pf_y == 2 && pf_x == 1)
			{
				performUP();
				displayParkingLayout(puzzle);
				performLEFT();
				displayParkingLayout(puzzle);
				performDOWN();
				displayParkingLayout(puzzle);
				performRIGHT();
				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}



			else if ((es_y - pf_y == -1) && (es_x - pf_x == 0) && (es_x != 0) && (pf_x != 0))
			{
				performLEFT();			displayParkingLayout(puzzle);
				performDOWN();			displayParkingLayout(puzzle);
				performRIGHT();			displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if ((es_y - pf_y == 0) && (es_x - pf_x == 1) && (es_y != 3) && (pf_y != 3))
			{
				performDOWN();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 3 && pf_x == 2)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
				performUP();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 3 && pf_x == 3)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
				performUP();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
			}

			else if ((es_y - pf_y == 0) && (es_x - pf_x == 1) && es_y == 3 && pf_y == 3 && (pf_x == 1 || pf_x == 2) && (es_x == 2 || es_x == 3) )
			{
				performUP();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 2 && pf_x == 2)
			{
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 2 && pf_x == 3)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}


			else if (es_y == 3 && es_x == 1 && pf_y == 1 && pf_x == 0)
			{
				performUP();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
				performRIGHT();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
			}


			else if (es_y == 3 && es_x == 1 && pf_y == 1 && pf_x == 1)
			{
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 1 && pf_x == 2)
			{
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 1 && pf_x == 3)
			{
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 0 && pf_x == 0)
			{
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}


			else if ((es_y - pf_y == -1) && (es_x - pf_x == 0) && es_x == 0 && pf_x == 0 && (es_y == 0 || es_y == 1) && (pf_y == 1 || pf_y == 2) )
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
				performLEFT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 0 && pf_x == 1)
			{
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 0 && pf_x == 2)
			{
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 3 && es_x == 1 && pf_y == 0 && pf_x == 3)
			{
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 3 && pf_x == 2)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}


			else if (es_y == 2 && es_x == 0 && pf_y == 3 && pf_x == 3)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 2 && pf_x == 2)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}


			else if (es_y == 2 && es_x == 0 && pf_y == 2 && pf_x == 3)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 1 && pf_x == 0)
			{
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
				performRIGHT();				displayParkingLayout(puzzle);
				performDOWN();				displayParkingLayout(puzzle);
			}


			else if (es_y == 2 && es_x == 0 && pf_y == 1 && pf_x == 1)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 1 && pf_x == 2)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}


			else if (es_y == 2 && es_x == 0 && pf_y == 1 && pf_x == 3)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 0 && pf_x == 0)
			{
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 0 && pf_x == 1)
			{
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 0 && pf_x == 2)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}

			else if (es_y == 2 && es_x == 0 && pf_y == 0 && pf_x == 3)
			{
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performRIGHT();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				performUP();				displayParkingLayout(puzzle);
				pf_y =  ptemp_y;
				pf_x = ptemp_x;
			}


			difference = pf_y - pf_x;


		}




		if (pf_y == 3 && pf_x == 0)
		{
			if(count == 1)
			{
				if(!option.compare("P"))
				{
					for(int i = 0; i < ROW;i++)
					{   for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare(" E"))
						{
							es_y = i;
							es_x = j;
						}
					}
					}


					if(es_y == 3 && es_x == 1)
					{
						ptemp_y = pf_y;
						ptemp_x = pf_x;
						pf_y = pf_y - 1;

						puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
					}


					if(es_y == 2 && es_x == 0)
					{
						ptemp_y = pf_y;
						ptemp_x = pf_x;
						pf_x = pf_x + 1;
						puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
					}

					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}

			}



			else if(count == 2)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if(!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if(count == 3)
			{

				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}



				else if(!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if(count == 4 )
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if(!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 5)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}

			}



			else if (count == 6)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}

			}



			else if (count == 7)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}

			}



			else if (count == 8)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 9)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 10)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 11)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}


			else if (count == 12)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 13)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 14)
			{
				if(!option.compare("P"))
				{
					performNext();
					assignCarNumber ();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					for(int i = 0; i < ROW;i++)
					{for(int j = 0; j < COL;j++)
					{
						if(!puzzle[i][j].compare("  ") )
						{pnull_y = i;
						pnull_x = j;
						}
					}
					}

					puzzle[ptemp_y][ptemp_x] = puzzle[pnull_y][pnull_x];
					puzzle[pnull_y][pnull_x] = "--";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}



			else if (count == 15)
			{
				if(!option.compare("P"))
				{
					assignCarNumber();
					displayParkingLayout(puzzle);
				}


				else if (!option.compare("R"))
				{
					puzzle[ptemp_y][ptemp_x] = "  ";
					pf_y = ptemp_y;
					pf_x = ptemp_x;
					displayParkingLayout(puzzle);
				}
			}

		}

		if(!option.compare("R"))
			count--;

	}

	return(0);
}





void displayParkingLayout (string value[ROW][COL])
{

	printf("\n\n");
	printf("|-----+-----+-----+-----|\n");
	cout<<"| "<<value[0][0]<<"  | "<<value[0][1]<<"  | "<<value[0][2]<<"  | "<<value[0][3]<<"  |\n";

	printf("|-----+-----+-----+-----|\n");
	cout<<"| "<<value[1][0]<<"  | "<<value[1][1]<<"  | "<<value[1][2]<<"  | "<<value[1][3]<<"  |\n";

	printf("|-----+-----+-----+-----|\n");
	cout<<"| "<<value[2][0]<<"  | "<<value[2][1]<<"  | "<<value[2][2]<<"  | "<<value[2][3]<<"  |\n";

	printf("|-----+-----+-----+-----|\n");
	cout<<"| "<<value[3][0]<<"  | "<<value[3][1]<<"  | "<<value[3][2]<<"  | "<<value[3][3]<<"  |\n";

	printf("|-----+-----+-----+-----|\n");
}



void performLEFT()
{
	cout<<" LEFT ";
	ptemp_y = es_y;
	ptemp_x = es_x;
	es_x = es_x - 1;
	puzzle[ptemp_y][ptemp_x] = puzzle[es_y][es_x];
	puzzle[es_y][es_x] = " E";
}



void performRIGHT()
{
	cout<<" RIGHT ";
	ptemp_y = es_y;
	ptemp_x = es_x;
	es_x = es_x + 1;
	puzzle[ptemp_y][ptemp_x] = puzzle[es_y][es_x];
	puzzle[es_y][es_x] = " E";
}



void performUP()
{
	cout<<" UP ";
	ptemp_y = es_y;
	ptemp_x = es_x;
	es_y = es_y - 1;
	puzzle[ptemp_y][ptemp_x] = puzzle[es_y][es_x];
	puzzle[es_y][es_x] = " E";
}



void performDOWN()
{
	cout<<" DOWN ";
	ptemp_y = es_y;
	ptemp_x = es_x;
	es_y = es_y + 1;
	puzzle[ptemp_y][ptemp_x] = puzzle[es_y][es_x];
	puzzle[es_y][es_x] = " E";
}


void assignCarNumber ()
{
	int pC = 0;
	int pB = 0;
	int pA = 0;
	int pG = 0;
	int pH = 0;
	int pI = 0;
	int pJ = 0;
	int pK = 0;
	int pL = 0;
	int pM = 0;
	int pN = 0;
	int pO = 0;
	int pP = 0;
	int pQ = 0;
	int pR = 0;

	for(int i = 0; i < ROW;i++)
	{for(int j = 0; j < COL;j++)
	{
		if(!puzzle[i][j].compare(" 1") ) pA = 1;
		if(!puzzle[i][j].compare(" 2") ) pB = 1;
		if(!puzzle[i][j].compare(" 3") ) pC = 1;
		if(!puzzle[i][j].compare(" 4") ) pG = 1;
		if(!puzzle[i][j].compare(" 5") ) pH = 1;
		if(!puzzle[i][j].compare(" 6") ) pI = 1;
		if(!puzzle[i][j].compare(" 7") ) pJ = 1;
		if(!puzzle[i][j].compare(" 8") ) pK = 1;
		if(!puzzle[i][j].compare(" 9") ) pL = 1;
		if(!puzzle[i][j].compare("10") ) pM = 1;
		if(!puzzle[i][j].compare("11") ) pN = 1;
		if(!puzzle[i][j].compare("12") ) pO = 1;
		if(!puzzle[i][j].compare("13") ) pP = 1;
		if(!puzzle[i][j].compare("14") ) pQ = 1;
		if(!puzzle[i][j].compare("15") ) pR = 1;
	}
	}

	if(pA != 1)
		puzzle[ptemp_y][ptemp_x] = " 1";

	else if(pB != 1)
		puzzle[ptemp_y][ptemp_x] = " 2";

	else if(pC != 1)
		puzzle[ptemp_y][ptemp_x] = " 3";

	else if(pG != 1)
		puzzle[ptemp_y][ptemp_x] = " 4";

	else if(pH != 1)
		puzzle[ptemp_y][ptemp_x] = " 5";

	else if(pI != 1)
		puzzle[ptemp_y][ptemp_x] = " 6";

	else if(pJ != 1)
		puzzle[ptemp_y][ptemp_x] = " 7";

	else if(pK != 1)
		puzzle[ptemp_y][ptemp_x] = " 8";

	else if(pL != 1)
		puzzle[ptemp_y][ptemp_x] = " 9";

	else if(pM != 1)
		puzzle[ptemp_y][ptemp_x] = "10";

	else if(pN != 1)
		puzzle[ptemp_y][ptemp_x] = "11";

	else if(pO != 1)
		puzzle[ptemp_y][ptemp_x] = "12";

	else if(pP != 1)
		puzzle[ptemp_y][ptemp_x] = "13";

	else if(pQ != 1)
		puzzle[ptemp_y][ptemp_x] = "14";

	else if(pR != 1)
		puzzle[ptemp_y][ptemp_x] = "15";



	pA = 0;
	pB = 0;
	pC = 0;
	pG = 0;
	pH = 0;
	pI = 0;
	pJ = 0;
	pK = 0;
	pL = 0;
	pM = 0;
	pN = 0;
	pO = 0;
	pP = 0;
	pQ = 0;
	pR = 0;

}



void performNext ()
{
	if (!puzzle[2][0].compare("--") )
	{
		pf_y = 2;
		pf_x = 0;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[3][1].compare("--") )
	{
		pf_y = 3;
		pf_x = 1;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[2][1].compare("--") )
	{
		pf_y = 2;
		pf_x = 1;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[1][0].compare("--") )
	{
		pf_y = 1;
		pf_x = 0;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[1][1].compare("--") )
	{
		pf_y = 1;
		pf_x = 1;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[3][2].compare("--") )
	{
		pf_y = 3;
		pf_x = 2;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[2][2].compare("--") )
	{
		pf_y = 2;
		pf_x = 2;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[3][3].compare("--") )
	{
		pf_y = 3;
		pf_x = 3;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[2][3].compare("--") )
	{
		pf_y = 2;
		pf_x = 3;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[1][2].compare("--") )
	{
		pf_y = 1;
		pf_x = 2;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[0][0].compare("--") )
	{
		pf_y = 0;
		pf_x = 0;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[0][1].compare("--") )
	{
		pf_y = 0;
		pf_x = 1;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[1][3].compare("--") )
	{
		pf_y = 1;
		pf_x = 3;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[0][2].compare("--") )
	{
		pf_y = 0;
		pf_x = 2;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

	else if (!puzzle[0][3].compare("--") )
	{
		pf_y = 0;
		pf_x = 3;
		puzzle[pf_y][pf_x] = puzzle[ptemp_y][ptemp_x];
	}

}

