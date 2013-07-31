#include <iostream>
#include "cube.h"
#include <conio.h>
#include <Windows.h>
#include <string>


using namespace std;

int main(){
	string input;
	int cube_size;
	int row_col_num;

	cout << "Enter the size of the cube.  Enter 2 for 2x2, 3 for 3x3, etc. ";
	cin >> input;
	cube_size = atoi( input.c_str() );

	cube *mycube = new cube( cube_size );
	mycube->print_faces();

	cout << "Instructions:" << endl << 
			"l,r,u,d mean left, right, up, and down respectively.  Numbers refer to a column or row.  " <<
			"So 2r means rotate the 2nd row right.  And 3u means rotate the 3rd column up.  " <<
			"You can rotate the whole cube in any direction by typing w for whole and a letter " <<
			"indicating the direction.  " << 
			"Type random to randomize the cube.  It will prompt you for a number of random turns.  " <<
			"Type new to get a new cube.  Type q to quit.  " << endl << endl << 
			"Enter a command: ";
	cin >> input;

	while( input != "q" ){
		if( input[0] == 'w' ){
			if( input[1] == 'u' )
				mycube->rotate_up();
			else if( input[1] == 'd' )
				mycube->rotate_down();
			else if( input[1] == 'r' )
				mycube->rotate_right();
			else if( input[1] == 'l' )
				mycube->rotate_left();
			else
				cout << "Command Invalid." << endl;
		}
		else if( input == "random" ){
			cout << "Enter number of turns ";
			cin >> input;
			int turns = atoi( input.c_str() );
			mycube->randomize( turns );
		}
		else if( input == "new" ){
			delete mycube;
			mycube = new cube(cube_size);
		}
		else{
			string str = string( &input[0] );
			row_col_num = atoi( str.c_str() );
			if( row_col_num > cube_size )
				break;
			else if( input[1] == 'r' )
				mycube->rotate_row_right( row_col_num - 1 );
			else if( input[1] == 'l' )
				mycube->rotate_row_left( row_col_num - 1 );
			else if( input[1] == 'u' )
				mycube->rotate_col_up( row_col_num - 1 );
			else if( input[1] == 'd' )
				mycube->rotate_col_down( row_col_num - 1);
			else
				cout << "Command Invalid." << endl;
		}

		mycube->print_faces();
		cout << "Enter another command ";
		cin >> input;
	}

	return 0;
}