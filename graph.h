

#ifndef GRAPH_H_
#define GRAPH_H_


#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;


typedef priority_queue < pair<int, pair<int,int> >,
		   	   	   	     vector<  pair<int, pair<int,int> > >,
						 greater< pair<int, pair<int,int> > > > pri_que;

// composite data type declaration
struct vertex
{
	bool visited;
	string cityName;  			     // name of the city
	vector< pair< int, int> >  edge; // edge of pairs (distance, endingCity)

	vertex(){
		this->visited = false;
		this->cityName = " ";
	}
};

class Graph
{
private:
	vector<vertex> vertices; 					  // container holding the vertices inside a graph
	vector< pair< int , pair<int,int>  > > order; // holds the order of the MST paths
	int totalDistance; 						      // total Distance of MST

public:
	Graph();  // constructor
	~Graph(); // destructor

	// adds vertex to the graph
	void addVertex(const string & cityName);

	 // adds edges to the graph
	void addEdges(const int &vertex, const int & distance, const int & endingVertex);

	// Prims Algorithm for MST
	void minimumSpanningTree(int start);

	// Clears the priority queue for the next visited vertices
	void clearPriorityQueue(pri_que & priorityQueue);

	// prints the order of the MST
	void printOrder();
};

// constructor
Graph::Graph() : totalDistance (0){}

// destructor
Graph::~Graph() {}


// adds edges to the graph
void Graph::addVertex(const string & cityName)
{
	vertex newVertex; // creates vertex

	newVertex.cityName = cityName;  // name is assigned to the new vertex

	vertices.push_back(newVertex); // added to container
}

// adds vertex to the graph
void Graph::addEdges(const int & startingVertex, const int & distance, const int & endingVertex)
{
	vertices.at(startingVertex).edge.push_back(make_pair(distance, endingVertex ));
}

// Prims Algorithm for MST
void Graph::minimumSpanningTree(int start)
{

	vertices.at(start).visited = true; // checks the starting vertex to visited

	pri_que priorityQueue; // min heap, to hold the least mileage from the vistied vertices

	while(order.size() < 11)
	{
		// for loop = runs through the vertices checking
		for(int index = 0; index < vertices.size(); index++)
		{
			/*
			 * If a vertex is visited, it checks its corresponding edges by running a for loop. Then pushing
			 * the edges into a min heap that lead to a vertex that is unvisited.
			 */
			if( vertices.at(index).visited)
			{
				for(int index2 = 0; index2 < vertices.at(index).edge.size(); index2++)
				{
					int city = vertices.at(index).edge.at(index2).second  ;
					int distance =  vertices.at(index).edge.at(index2).first ;

					if( !vertices.at( city  ).visited )
					{
						// starting vertex (index), ending city (city) and distance are pushed into the heap
						priorityQueue.push(  make_pair( distance, make_pair( index,city  ) ));
					}
				}
			}
		}

		int lowestDistance = priorityQueue.top().first;
		int startingCity = priorityQueue.top().second.first;
		int leastMileageVertex = priorityQueue.top().second.second;

		totalDistance += lowestDistance; // adds the distance to the totatDistance

		 // checks the leastMilage edge, so it on the next loop it can have its edges checked
		vertices.at(leastMileageVertex).visited = true;

		// pushed back the corresponding edge with its vertices and distances
		order.push_back( make_pair( lowestDistance, make_pair( startingCity,leastMileageVertex  )));

		clearPriorityQueue(priorityQueue); // clears the priority queue for the next run

	}

}

// Clears the priority queue for the next visited vertices
void Graph::clearPriorityQueue(pri_que & priorityQueue)
{
	// runs while loop until the priority_queue is empty
	while(!priorityQueue.empty())
	{
		priorityQueue.pop();
	}
}

// prints the order of the MST
void Graph::printOrder()
{
	for(vector< pair< int , pair<int,int> > > ::iterator it = order.begin(); it != order.end(); it++)
	{
		cout << endl  << endl  << vertices.at((*it).second.first).cityName
			 << " --> "        << vertices.at((*it).second.second).cityName
			 << "\nDistance: " << (*it).first;
	}
	cout << "\n\nThe total Distance of the MST is " << totalDistance;
}




#endif /* GRAPH_H_ */
