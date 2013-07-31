/*Ryan Riddle (ryan.riddle@uky.edu)
* This is the header file for the face class.  A face encapsulates a grid of arbitrary size.
* The grid is implemented as a vector of vectors of Colors.  Each element of the grid can
* be one of six colors--like the face of a rubiks cube.  
* Various methods can be applied to a face, including getting a row or column from the grid,
* setting a row or column from the grid or rotating (turning) the clockwise or counterclockwise
* (right or left).
*/


#ifndef _FACE_H_
#define _FACE_H_
#endif
#include <vector>

using namespace std;

enum Color {RED, GREEN, BLUE, WHITE, YELLOW, MAGENTA };

class face {
	private:
		int size;
		vector< vector<Color> > squares;

	public:
		vector<Color> get_row( int r );				//get the rth row
		vector<Color> get_col( int c );				//get the cth column
		void print_row( int r );					//print the rth row
		vector< vector<Color> > get_squares();		//get the grid
		void rotate_right();						//rotate the grid clockwise
		void rotate_left();							//rotate the grid counter-clockwise
		void set_row( int r, vector<Color> rvals );	//set the rth row to rvals
		void set_col( int c, vector<Color> cvals );	//set the cth column to cvals
		void print_squares();						//print the grid
		face( enum Color c, int face_size );		//constuctor creates face_size x face_size grid where elements have color c
		int get_size();								//get size of face

};