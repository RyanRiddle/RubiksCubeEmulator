#include "face.h"
/*Ryan Riddle (ryan.riddle@uky.edu)
* This is the header file for the cube class.  A cube has a vector of faces.
* The vector face order exists to remind you the order is (front, left, right,
* top, bottom, back ).  face_size stores the size of the faces.
* There are methods to rotate the entire cube up, down, left, and right.
* There are methods to rotate a row right or left or a column up or down.
* You can randomize the cube.  You can also print all six faces of the cube.
*/

#include <vector>
#include <string>

using namespace std;

class cube {
private:
	vector<face> faces;
	vector<string> face_order;
	int face_size;


public:
	cube( int cube_size );				//constructor for cube_size x cube_size faces
	void set_faces( vector<face> f );	//sets faces to the faces provided in the vector f
	vector<face> get_faces();			//returns faces
	void print_faces();					//prints all six faces with names
	void rotate_right();				//rotates the cube clockwise looking at the front
	void rotate_left();					//rotates the cube counter-clockwise looking at the front
	void rotate_up();					//rotates the cube up (front becomes top)
	void rotate_down();					//rotates the cube down (front becomes bottom)
	void rotate_row_right( int r );		//twists the rth row right
	void rotate_row_left( int r );		//twists the rth row left
	void rotate_col_up( int c );		//twists the cth column up
	void rotate_col_down( int c );		//twists the cth column down
	void randomize( int turns );		//performs random rotation operations
};