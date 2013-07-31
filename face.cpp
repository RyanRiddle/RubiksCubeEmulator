/*Ryan Riddle (ryan.riddle@uky.edu)
* This file implements the methods declared in the header file.
*/

#include "face.h"
#include <iostream>
#include <Windows.h>

using namespace std;

vector<Color> face::get_row( int r ) {
	vector<Color> row;
	for( int i = 0; i < size; i++ )		//iterate through the grid
		row.push_back(squares[r][i]);	//add square in rth row and ith col to return row
	return row;
}

vector<Color>  face::get_col( int c ){
	vector<Color> col(size);
	for( int i = 0; i < size; i++ )		//iterate through the grid
		col[i] = squares[i][c];			//add square in ith row and cth column to the grid
	return col;	
}

void face::rotate_right(){
	vector< vector<Color> > new_squares;
	vector<Color> temp(size);
	for( int i = 0; i < size; i++ )
		new_squares.push_back( temp );		//make new squares the same size as squares grid

	for( int i = 0; i < size; i++ )
		for( int j = 0; j < size; j++ )
			new_squares[j][(size-1)-i] = squares[i][j];		//basically, create a transpose of squares and mirror the columns

	//for( int i = 0; i < size; i++ )
		//for( int j = 0; j < size; j++ )
			//	squares[i][j] = new_squares[i][j];			//set the squares grid to new orientation

	squares = new_squares;
}

void face::rotate_left(){				//see description of rotate_right
	vector< vector<Color> > new_squares;
	vector<Color> temp(size);
	for( int i = 0; i < size; i++ )
		new_squares.push_back( temp );

	for( int i = 0; i < size; i++ )
		for( int j = 0; j < size; j++ )
			new_squares[(size-1)-j][i] = squares[i][j];

	//for( int i = 0; i < size; i++ )
		//for( int j = 0; j < size; j++ )
			//	squares[i][j] = new_squares[i][j];
	squares = new_squares;
}

void face::set_row( int r, vector<Color> rvals ){
	for( int j = 0; j < size; j++ )
		squares[r][j] = rvals[j];		//iterate through rvals and set the rth row of squares to the parameter values
}

void face::set_col( int c , vector<Color> cvals ){
	for( int i = 0; i < size; i++ )
		squares[i][c] = cvals[i];		//iterate through cvals and set the cth column of squares to the parameter values
}

vector< vector<Color> >face::get_squares(){
	return squares;
}

void face::print_squares(){
	HANDLE hConsole;    
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	 
	SetConsoleTextAttribute
	    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);	            
	for( int i = 0; i < size; i++ ){
		for( int j = 0; j < size; j++ ){
			//set the text color of the console
			switch( squares[i][j] ){
				case RED: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); break;						//RED
				case GREEN: SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); break; 					//GREEN
				case BLUE: SetConsoleTextAttribute (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);	break;  					//BLUE
				case WHITE: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;		//WHITE	
				case YELLOW: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );	break;	//YELLOW
				case MAGENTA: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );	break;	//MAGENTA	
			}
			cout << "|||" << " ";
		}
		cout << endl;
	}
}


face::face( enum Color c, int face_size ){
	size = face_size;
	vector<Color> temp;
	for( int i = 0; i < size; i++ ){		//size x size
		for( int j = 0; j < size; j++ )
			temp.push_back(c);				//add Color to grid
		squares.push_back(temp);
	}
}


void face::print_row( int r ){
	HANDLE hConsole;    
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

	vector<Color> temp_row(get_row( r ));
	for( int i = 0; i < size; i++ ){
		//set text color in console
		switch( temp_row[i] ){
			case RED: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); break;						//RED
			case GREEN: SetConsoleTextAttribute (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); break; 					//GREEN
			case BLUE: SetConsoleTextAttribute (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);	break;  					//BLUE
			case WHITE: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;		//WHITE	
			case YELLOW: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );	break;	//YELLOW
			case MAGENTA: SetConsoleTextAttribute (hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );	break;	//MAGENTA		
		}
		cout << "|||" << " ";
	}
	cout << " ";

	//set the text color back to white
	SetConsoleTextAttribute( hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
}

int face::get_size(){
	return size;
}


