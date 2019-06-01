#include "myHeader.h"


/*****************************************************************************
 * AUTHOR:       : Jose Cardenas
 * STUDENT ID    : 1026944
 * ASSIGNMENT 12 : MST
 * CLASS:        : CS1D
 * TIME:         : Mondays & Wednesday: 5:00 - 7:20PM
 * DUE DATE:     : 11/28/18
 * ---------------------------------------------------------------------------
 * PROGRAM DESCRIPTION:
 *  Determine the MST (identify edges and total mileage).
 ***************************************************************************/

int main()
{
	/************************************************************************************
	 * For Output purposes
	 * ----------------------------------------------------------------------------------
	 * Lab or Assignment, Author, Id of Author, Assignment #, Assignment Name, Due Date
	 ***********************************************************************************/
	assignmentDescription("fsd","Jose Cardenas",1026944 ,12,"MST","11/28/18");


	Graph graph;

	graph.addVertex("Boston");
	graph.addVertex("New York");
	graph.addVertex("Atlanta");
	graph.addVertex("Miami");
	graph.addVertex("Chicago");
	graph.addVertex("Kansas City");
	graph.addVertex("Dallas");
	graph.addVertex("Houston");
	graph.addVertex("Denver");
	graph.addVertex("Seattle");
	graph.addVertex("San Francisco");
	graph.addVertex("Los Angeles");

	//Boston
	graph.addEdges(0, 214,  1);
	graph.addEdges(0, 983,  4);

	//New York
	graph.addEdges(1, 214, 0);
	graph.addEdges(1, 888, 2);
	graph.addEdges(1, 787, 4);
	graph.addEdges(1, 1260, 5);

	//Atlanta
	graph.addEdges(2, 888, 1);
	graph.addEdges(2, 661, 3);
	graph.addEdges(2, 864, 5);
	graph.addEdges(2, 781, 6);
	graph.addEdges(2, 810, 7);

	//Miami
	graph.addEdges(3, 661, 2);
	graph.addEdges(3, 1187, 7);

	//Chicago
	graph.addEdges(4, 983, 0);
	graph.addEdges(4, 787, 1);
	graph.addEdges(4, 533, 5);
	graph.addEdges(4, 1003, 8);
	graph.addEdges(4, 2097, 9);

	//Kansas City
	graph.addEdges(5, 1260, 1);
	graph.addEdges(5, 864, 2);
	graph.addEdges(5, 533, 4);
	graph.addEdges(5, 496, 6);
	graph.addEdges(5, 599, 8);
	graph.addEdges(5, 1663, 11);

	//Dallas
	graph.addEdges(6, 781, 2);
	graph.addEdges(6, 496, 5);
	graph.addEdges(6, 239, 7);
	graph.addEdges(6, 1435, 11);

	//Houston
	graph.addEdges(7, 810, 2);
	graph.addEdges(7, 1187, 3);
	graph.addEdges(7, 239, 6);

	//Denver
	graph.addEdges(8, 1003, 4);
	graph.addEdges(8, 599, 5);
	graph.addEdges(8, 1331, 9);
	graph.addEdges(8, 1267, 10);
	graph.addEdges(8, 1015, 11);

	//Seattle
	graph.addEdges(9, 2097, 4);
	graph.addEdges(9, 1331, 8);
	graph.addEdges(9, 807, 10);

	//San Francisco
	graph.addEdges(10, 1267, 8);
	graph.addEdges(10, 807, 9);
	graph.addEdges(10, 381, 11);

	// Los Angeles
	graph.addEdges(11, 1663, 5);
	graph.addEdges(11, 1435, 6);
	graph.addEdges(11, 1015, 8);
	graph.addEdges(11, 381, 10);

	//Perform MST Algorithm
	graph.minimumSpanningTree(11);

	// Prints the order of the MST
	graph.printOrder();




	return 0;

}
