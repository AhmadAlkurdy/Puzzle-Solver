//////////////////////////////////////////////////////////////////////////////////////////////
// functions' implemntations
// depth-first search
// Astar
//breadth-first search
////////////////////////////////




#include "classDef.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <queue>



using namespace std;




void sliders::menu()
{
	cout << "Welcome to the puzzle game" << endl;
	
}

void sliders:: input ()
{
	int numArray [] = {0,0,0,0,0,0,0,0,0};
	
	cout << "input the numbers and replace the empty slider with zero hit space or enter between the numbers: " << endl;
	for (int i = 0; i < 9; i++)
	{
		cin >> numArray[i];
	}
	
	 cout << "Breadth first search : " << endl;
	
	breadth_first_search(numArray);
	
	
	//cout << "Astar search: " << endl;
//	Astar(numArray);
	
	
//	cout << "Depth first search : " << endl;
//	Depth_first_search(numArray);
	
	
}

void sliders :: output (int numArray[])
{

	cout << " " << " " <<  "_____________" << endl;
	cout << " " << " " << "| " << numArray[0] << " | " << numArray[1] << " | " << numArray[2] << " |" << endl;
	cout << " " << " " << "_____________" << endl;
	cout << " " << " " << "| " << numArray[3] << " | " << numArray[4] << " | " << numArray[5] << " |" << endl;
	cout << " " << " " << "_____________" << endl;
	cout << " " << " " << "| " << numArray[6] << " | " << numArray[7] << " | " << numArray[8] << " |" << endl;
	cout << " " << " " << "_____________" << endl;
}


void sliders:: breadth_first_search (int numArray[])
{
	map <string,int> mymap;
	
	int depth = 0;
    int goalState[] = {1,2,3,4,5,6,7,8,0};
	int goal = 0;
	int nodeNum = 0;
	int nodeNum2 = 0;
	int nodeNum3 = 0;
	queue <int> tree;
	string root;
	int depthR = 0;

	for(int i = 0; i < 9; i++)
	{
		stringstream ss;
		ss << numArray[i];
		root += ss.str();
	}
	
	
	depth++;
	 mymap.insert(pair<string, int> (root, depthR));
	 
	
	
	// while the goal state is not reached yet
	while(!goal)
	{
		//if 0 in the first box
	if(numArray[0] == 0)
	{
		//do the swap accroding to the clockwise then send the array to the storage function
		//where i have a linked list and it will add a node for the new state
		//if it creates a node and the node is not already exist then nodeNum will be 0
		// and then will be pushed in the queue,
		string snumArray;
		swap(numArray[0],numArray[1]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree.push(*numArray);

		//check if we reached the goal state
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	// hoewever if the node is already exist then nodeNum = 1
		// and the node is not created and it will move to the second node clockwise and swap with other 
	// value and then do the same process
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[0],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 
			  }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
		}
	
		}
	}


	if(numArray[1] == 0)
	{
		string snumArray;
		swap(numArray[1],numArray[2]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 { 
				 nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
				  
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 

			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[0]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 

			 { 
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth)); nodeNum = 1;
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	
		}
		}
		
	}
	if(numArray[2] == 0)
	{
		string snumArray;
		swap(numArray[2],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth
		}
		if(nodeNum != 0)
		{
			string snumArray;
	
			swap(numArray[2],numArray[1]);
		
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
			 }

			tree.push(*numArray);
		
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])	
		
			{
			
				cout << "Goal State found" << endl;
				cout << "Depth" << depth << endl;
			
				return;
			//show the depth and the stuff
		
			}
	
		
		}
	}
	if(numArray [3] == 0)
	{
		string snumArray;
		swap(numArray[3],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
			swap(numArray[3],numArray[6]);
		
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if (mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
			 }

			tree.push(*numArray);
		
			if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		
			{
			
				cout << "Goal State found" << endl;
				cout << "Depth" << depth << endl;
			
				return;
			//show the depth and the stuff
		
			}
	
		}
	}
	if(numArray [4] == 0)
	{
		string snumArray;
		swap(numArray[4],numArray[1]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
		
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		
		 if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
		
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		
		
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
	}
	
	
		}
		}
		}

	}

	if(numArray [5] == 0)
	{
		string snumArray;
		swap(numArray[5],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[5],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	
		}
	}

	if(numArray[6] == 0)
	{
		string snumArray;
		swap(numArray[6],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[6],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 mymap.insert(pair<string, int> (snumArray, depth));
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	
		}
	}

	if(numArray[7] == 0)
	{
		string snumArray;
		swap(numArray[7],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[7],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 mymap.insert(pair<string, int> (snumArray, depth));
			 if (mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				  mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		
		 if(nodeNum !=0)
		{
			string snumArray;
		swap(numArray[7],numArray[6]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	
		 }
		}
	}
	if(numArray[8] == 0)
	{
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	string snumArray;
		swap(numArray[8],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[8],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				  nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
			 }

		tree.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth" << depth << endl;
			return;
			//show the depth and the stuff
		}
	
		}
	}

	}

	output(numArray);
	mymap.clear();
	
}



void sliders::Astar(int numArray[])
{
	map <string,int> mymap;
	
	int depth = 0;

	int goalState[] = {1,2,3,4,5,6,7,8,0};
	int goal = 0;
	int nodeNum = 0;
	int nodeNum2 = 0;
	int nodeNum3 = 0;
	queue <int> tree2;
	string root;
	int depthR = 0;
	int a, b, c, d = 0;

	for(int i = 0; i < 9; i++)
	{
		stringstream ss;
		ss << numArray[i];
		root += ss.str();
	}
	
	
	
	 mymap.insert(pair<string, int> (root, depthR));
	
	//it will check for the goal state from the beggining just different style than before but the same 
	// stratiges 
	if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
	{
		cout << "Goal state fount" << endl;
		cout << "Depth " << depth << endl;
	}
	else 

	{
	
		while(!goal)
	
		{
	
	// if the 0  in the first box we will send the array to the priority Queue function I built
	// that would subtract the possible moves from the values that supposed to be in box 0 which is 1
			// and then pick the less results and do the swap
			//then it will send the array to the storage function to be be stored and compared and see
			// if the state has already exisisted in the linked list
		if(numArray[0] == 0)
	
		{
		string snumArray;
		    a = abs(numArray[1] - 1);
			b = abs(numArray[3] - 1);
			if(a > b)
			{
				swap(numArray[0],numArray[3]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[0],numArray[1]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
		}
			}
			else
			{
			swap(numArray[0],numArray[1]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[0],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
			
		    }
			
	}

	}
		if(numArray[1] == 0)
		{
		string snumArray;
		a = abs(numArray[2] - 2);
		b = abs(numArray[4] - 2);
		c = abs(numArray[0] - 2);
		if(a > b && c > b)
		{
			swap(numArray[1],numArray[4]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[2]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[1],numArray[0]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "Unsolvable state" << endl;
		cout << "depth: " << depth << endl;
	}
	
		}
	}
	
		}
		else if (a < b && a < c)
		{
			swap(numArray[1], numArray[2]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[0]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[1],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "unsolvable state " << endl;
		cout << " depth: " << depth << endl;
	}
	
		}
		
	}
		}
		else if(c < a && c < b)
		{
			string snumArray;
			swap(numArray [1],numArray[0]);
			
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[2]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[1],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << " Unsolvable state" << endl;
		cout << "Depth: " << depth << endl;
	}
	
		}
		
	}
		}
		}
////////////////////////////////////////////////////////////		
		if(numArray[2] == 0)
	
		{
			string snumArray;
		    a = abs(numArray[5] - 3);
			b = abs(numArray[1] - 3);
			if(a > b)
			{
				swap(numArray[2],numArray[1]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[2],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
			}
			else
			{
			swap(numArray[2],numArray[5]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[2],numArray[1]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
			
		    }
			if(nodeNum != 0)
			{
				cout << "Unsolvable state " << endl;
				cout << "Depth: " << depth << endl;
			}

			
		
	}
	}
	}
		if(numArray[3] == 0)
	
		{
			string snumArray;
		a = abs(numArray[0] - 4);
		b = abs(numArray[4] - 4);
		c = abs(numArray[6] - 4);
		if(a > b && c > b)
		{
			swap(numArray[3],numArray[4]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[3],numArray[0]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[3],numArray[6]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "Unsolvable state" << endl;
		cout << "depth: " << depth << endl;
	}
	
		}
		}
		}
		else if (a < b && a < c)
		{
			swap(numArray[3], numArray[0]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[3],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[3],numArray[6]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "unsolvable state " << endl;
		cout << " depth: " << depth << endl;
	}
	}
		}
		}

		else if(c < a && c < b)
		{
			string snumArray;
			swap(numArray [3],numArray[6]);
			
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[3],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[3],numArray[0]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << " Unsolvable state" << endl;
		cout << "Depth: " << depth << endl;
	}
	
		}
		
	}
		}
	}
		if(numArray[4] == 0)
	
		{
			a = abs(numArray[1] - 5);
		b = abs(numArray[5] - 5);
		c = abs(numArray[7] - 5);
		d = abs(numArray[3] - 5);
		if(a > b && c > b && d > b)
		{
			string snumArray;
			swap(numArray[4],numArray[5]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[1]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[4],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		swap(numArray[4],numArray[3]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
		  cout << "Unsolveable state " << endl;
		  cout << "depth: " << endl;
		}
	}
	}
		}
		}
		
	else if (c < b && c < a && c < d)
		{
			string snumArray;
			swap(numArray[4], numArray[7]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[4],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		swap(numArray[4],numArray[1]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
		  cout << "Unsolveable state " << endl;
		  cout << "depth: " << endl;
		}
	}
	}
		}
		}
	else if (a < b && a < c && a < d)
		{
			string snumArray;
			swap(numArray[4], numArray[1]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[4],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		swap(numArray[4],numArray[3]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
		  cout << "Unsolveable state " << endl;
		  cout << "depth: " << endl;
		}
		}
	}
		}
		}
	else if (d < b && d < c && d < a)
		{
			string snumArray;
			swap(numArray[4], numArray[3]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[4],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		swap(numArray[4],numArray[7]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
		  cout << "Unsolveable state " << endl;
		  cout << "depth: " << endl;
		}
	}
	}
		}
		}
		}
	if(numArray[5] == 0)
	{
		//three

        string snumArray;
		a = abs(numArray[2] - 6);
		b = abs(numArray[8] - 6);
		c = abs(numArray[4] - 6);
		if(a > b && c > b)
		{
			swap(numArray[6],numArray[8]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[5],numArray[2]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[5],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "Unsolvable state" << endl;
		cout << "depth: " << depth << endl;
	}
	
		}
	}
	
		}
		else if (a < b && a < c)
		{
			swap(numArray[5], numArray[2]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[5],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[5],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "unsolvable state " << endl;
		cout << " depth: " << depth << endl;
	}
	
		}
		
	}
		}

		else if(c < a && c < b)
		{
			swap(numArray [5],numArray[4]);
			
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[5],numArray[2]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[5],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << " Unsolvable state" << endl;
		cout << "Depth: " << depth << endl;
	}
	
		}
		
	}
		}
	
		}
	if(numArray[6] == 0)
	{
		//two 

           string snumArray;
		    a = abs(numArray[3] - 7);
			b = abs(numArray[7] - 7);
			if(a > b)
			{
				swap(numArray[6],numArray[7]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[6],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
		}
			}
			else
			{
			swap(numArray[6],numArray[3]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[6],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
			
		    }
			
	}
	}
		if(numArray[7] == 0)
		{
			//three

        string snumArray;
		a = abs(numArray[4] - 8);
		b = abs(numArray[8] - 8);
		c = abs(numArray[6] - 8);
		if(a > b && c > b)
		{
			swap(numArray[7],numArray[8]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[7],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[7],numArray[6]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "Unsolvable state" << endl;
		cout << "depth: " << depth << endl;
	}
	
		}
	}
	
		}
		else if (a < b && a < c)
		{
			swap(numArray[7], numArray[4]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[7],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[7],numArray[6]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << "unsolvable state " << endl;
		cout << " depth: " << depth << endl;
	}
	
		}
		
	}
		}
	
		else if(c < a && c < b)
		{
			swap(numArray [7],numArray[6]);
			
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[7],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		string snumArray;
		swap(numArray[7],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
	if(nodeNum != 0)
	{
		cout << " Unsolvable state" << endl;
		cout << "Depth: " << depth << endl;
	}
	
		}
		
	}
		}
	}
		
		if(numArray[8] == 0)
		{
			//two 

            string snumArray;
		    a = abs(numArray[5] - 0);
			b = abs(numArray[7] - 1);
			if(a > b)
			{
				swap(numArray[8],numArray[7]);
				for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[8],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
			}
			}
			else
			{
			swap(numArray[8],numArray[5]);
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
			//show the depth and the stuff
		}
		if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[8],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		tree2.push(*numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			cout << "Depth " << depth << endl;
			return;
		}
			
		    }
			
		}
		}
		}
			
output(numArray);
	mymap.clear();
	}
	}
	


void sliders::Depth_first_search(int numArray[])
{
	map <string,int> mymap;
	
	int depth = 0;
	 int goalState[] = {1,2,3,4,5,6,7,8,0};
	int goal = 0;
	int nodeNum = 0;
	int nodeNum2 = 0;
	int nodeNum3 = 0;
	stack <int*> tree3;
    while(!goal)
	{
		//if 0 in the first box
	if(numArray[0] == 0)
	{
		//do the swap accroding to the clockwise then send the array to the storage function
		//where i have a linked list and it will add a node for the new state
		//if it creates a node and the node is not already exist then nodeNum will be 0
		// and then will be pushed in the stack
		swap(numArray[0],numArray[1]);
		string snumArray;
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		if(nodeNum == 0)
		{
		tree3.push(numArray);

		//check if we reached the goal state
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
	// hoewever if the node is already exist then nodeNum = 1
		// and the node is not created and it will move to the second node clockwise and swap with other 
	// value and then do the same process
		else if(nodeNum != 0)
		{
			
		swap(numArray[0],numArray[3]);
		string snumArray;
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum =0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
		{
		tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
		}
		}
		else 
		{
			tree3.pop();
		}
		}
	}


	if(numArray[1] == 0)
	{
		
		swap(numArray[1],numArray[2]);
		string snumArray;
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[1],numArray[0]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else 
		{
			tree3.pop();
		}
		}
		}
		
	}
	if(numArray[2] == 0)
	{
		string snumArray;
		swap(numArray[2],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
	
			swap(numArray[2],numArray[1]);
		
			for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
			if(nodeNum == 0)
				{
					tree3.push(numArray);
		
		 
					if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]

					&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	
					&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])	
		
			
					{
			
		
						cout << "Goal State found" << endl;
			
				
						return;
			//show the depth and the stuff
		
			
					}
			}
			else
			{
				tree3.pop();
			}
		}
	}
	if(numArray [3] == 0)
	{
		string snumArray;
		swap(numArray[3],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

		if(nodeNum == 0)
			{
				tree3.push(numArray);
		
				if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]

				&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
				&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		
				{
			
					cout << "Goal State found" << endl;
			
					return;
			//show the depth and the stuff
		
				}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
			swap(numArray[3],numArray[6]);
		
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }

	
			if(nodeNum == 0)
				{
					tree3.push(numArray);
		
			
					if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	
					&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	
					&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		
			
					{
			
				cout << "Goal State found" << endl;
			
				return;
			//show the depth and the stuff
		
			}
			}
			else
			{
				tree3.pop();
			}
		}
	}
	if(numArray [4] == 0)
	{
		string snumArray;
		swap(numArray[4],numArray[1]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		
				if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	
				&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	
				&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		
				{
			
					cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
		
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		 else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
		
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		
		
		else if (nodeNum != 0)
		{
			string snumArray;
		swap(numArray[4],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
	}
		}
		else 
		{
		  tree3.pop();
		}
		}
		}
		}

	}

	if(numArray [5] == 0)
	{
		string snumArray;
		swap(numArray[5],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[5],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else
		{
			tree3.pop();
		}
		}
	}

	if(numArray[6] == 0)
	{
		string snumArray;
		swap(numArray[6],numArray[3]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[6],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		
		}
		else 
		{
			tree3.pop();
		}
		}

	}

	if(numArray[7] == 0)
	{
		string snumArray;
		swap(numArray[7],numArray[4]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[7],numArray[8]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			  if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		 else if(nodeNum !=0)
		{
			string snumArray;
		swap(numArray[7],numArray[6]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else 
		{
			tree3.pop();
		}
		 }
		}
	}
	if(numArray[8] == 0)
	{
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
	string snumArray;
		swap(numArray[8],numArray[5]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
			{
				tree3.push(numArray);
		
				if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	
				&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	
				&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		
				{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else if(nodeNum != 0)
		{
			string snumArray;
		swap(numArray[8],numArray[7]);
		for(int i = 0; i < 9; i++)
			{
				stringstream ss;
				ss << numArray[i];
				snumArray += ss.str();
			}
			 if ( mymap.find(snumArray) != mymap.end() )
			 {
				 nodeNum = 1;
			 }
			 else 
			 {
				 nodeNum = 0;
				 depth++;
				 mymap.insert(pair<string, int> (snumArray, depth));
				 
			 }
		if(nodeNum == 0)
		{
			tree3.push(numArray);
		if(numArray[0] == goalState[0]&& numArray[1] == goalState[1] && numArray[2] == goalState[2]
	&& numArray[3] == goalState[3] && numArray[4] == goalState[4] && numArray[5] == goalState[5]
	&& numArray[6] == goalState[6] && numArray[7] == goalState[7] && numArray[8] == goalState[8])
		{
			cout << "Goal State found" << endl;
			return;
			//show the depth and the stuff
		}
		}
		else 
		{
			tree3.pop();
		}
		
		}

}
	}

output(numArray);
mymap.clear();
}