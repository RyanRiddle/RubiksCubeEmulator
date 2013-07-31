/*Ryan Riddle (ryan.riddle@uky.edu)
* This file implements the methods declared in the header file
*/

#include "cube.h"
#include <iostream>
#include <time.h>

cube::cube( int cube_size ) {
	face_size = cube_size;
	face_order.push_back("front" );
	face_order.push_back("left" );
	face_order.push_back("right" );
	face_order.push_back("top" );
	face_order.push_back("bottom" );
	face_order.push_back("back" );

	for( int i = 0; i < 6; i++ ){
		face temp_face(Color(i), cube_size);		//create faces of each color and add them to the faces vector
		faces.push_back(temp_face);
	}
		
}

std::vector<face> cube::get_faces(){
	return faces;
}

void cube::set_faces( vector<face> f ){
	faces = f;
}

void cube::print_faces(){		//print 6 faces side by side
	
	for( int i = 0; i < faces[0].get_size(); i++ ){
		for( int j = 0; j < 6; j++ ){
			face temp(faces[j]);
			temp.print_row( i );		//print each row
		}
		std::cout << std::endl << std::endl;
	}

	//get the right spacing between names
	for( int i = 0; i < 6; i++ ){
		for( int j = 0; j <= face_size; j++ )
			cout << " ";
		//print the name
		cout << face_order[i];
		for( int j = 0; j <= face_size; j++ )
			cout << " ";
	}
	cout << endl;
}

void cube::rotate_down(){
	vector<face> new_faces;
	
	//front becomes bottom, bottom becomes back, back becomes top, top becomes front, left and right are rotated
	new_faces.push_back( faces[3] );
	face temp_face(faces[1]);
	temp_face.rotate_right();
	new_faces.push_back( temp_face );
	temp_face = faces[2];
	temp_face.rotate_left();
	new_faces.push_back( temp_face );
	new_faces.push_back( faces[5] );
	new_faces.push_back( faces[0] );
	new_faces.push_back( faces[4] );
	

	faces = new_faces;
}

void cube::rotate_up(){
	vector<face> new_faces;
	
	//front to top, top to back, back to bottom, bottom to front, rotate right and left faces
	new_faces.push_back( faces[4] );
	face temp_face( faces[1] );
	temp_face.rotate_left();
	new_faces.push_back( temp_face );
	temp_face = faces[2];
	temp_face.rotate_right();
	new_faces.push_back( temp_face );
	new_faces.push_back( faces[0] );
	new_faces.push_back( faces[5] );
	new_faces.push_back( faces[3] );

	faces = new_faces;
	
}

void cube::rotate_right(){
	vector<face> new_faces;
	
	//front to right, right to back, back to left, left to front, top and bottom are rotated
	new_faces.push_back( faces[1] );
	new_faces.push_back( faces[5] );
	new_faces.push_back( faces[0] );
	face temp_face( faces[3] );
	temp_face.rotate_left();
	new_faces.push_back( temp_face );
	temp_face = faces[4] ;
	temp_face.rotate_right();
	new_faces.push_back( temp_face );
	new_faces.push_back( faces[2] );

	faces = new_faces;
	
}

void cube::rotate_left(){
	vector<face> new_faces;
	
	//front to left, left to back, back to right, right to front, bottom and top are rotated
	new_faces.push_back( faces[2] );
	new_faces.push_back( faces[0] );
	new_faces.push_back( faces[5] );
	face temp_face( faces[3] );
	temp_face.rotate_right();
	new_faces.push_back( temp_face );
	temp_face = faces[4];
	temp_face.rotate_left();
	new_faces.push_back( temp_face );
	new_faces.push_back( faces[1] );

	faces = new_faces;
	
}

void cube::rotate_row_left( int r ){			//rotate rth row left
	vector< vector<Color> > new_rows;

	new_rows.push_back( faces[2].get_row( r ) );
	new_rows.push_back( faces[0].get_row( r ) );
	new_rows.push_back( faces[5].get_row( r ) );
	new_rows.push_back( faces[1].get_row( r ) );
	faces[0].set_row( r, new_rows[0] );
	faces[1].set_row( r, new_rows[1] );
	faces[2].set_row( r, new_rows[2] );
	faces[5].set_row( r, new_rows[3] );
	
	if( r == 0 ){					//if its the first row, rotate the top clockwise
		face temp_face(faces[3]);
		temp_face.rotate_right();
		faces[3] = temp_face;
	}
	else if( r==(face_size-1)){		//if its the last row, rotate the bottom counter-clockwise
		face temp_face(faces[4]);
		temp_face.rotate_left();
		faces[4] = temp_face;
	}
	
}

void cube::rotate_row_right( int r ){		//rotate the rth row right
	vector< vector<Color> > new_rows;

	face temp(faces[1]);
	new_rows.push_back( temp.get_row( r ) );
	new_rows.push_back( faces[5].get_row( r ) );
	new_rows.push_back( faces[0].get_row( r ) );
	new_rows.push_back( faces[2].get_row( r ) );
	faces[0].set_row( r, new_rows[0] );
	faces[1].set_row( r, new_rows[1] );
	faces[2].set_row( r, new_rows[2] );
	faces[5].set_row( r, new_rows[3] );
	
	if( r == 0 ){					//if it's the first row, rotate the top counter-clockwise
		face temp_face(faces[3]);
		temp_face.rotate_left();
		faces[3] = temp_face;
	}
	else if( r==(face_size - 1)){					//if it's the last row, rotate the bottom clockwise
		face temp_face(faces[4]);
		temp_face.rotate_right();
		faces[4] = temp_face;
	}

	
}

void cube::rotate_col_down( int c ){			//rotate the cth column down
	vector<Color> temp_col;
	temp_col = faces[0].get_col( c );
	faces[0].set_col( c, faces[3].get_col( c ));
	faces[3].set_col( c, faces[5].get_col( c ));
	faces[5].set_col( c, faces[4].get_col( c ));
	faces[4].set_col( c, temp_col );
	
	if( c == 0 ){								//if it's the left-most column, rotate the left face clockwise
		face temp_face(faces[1]);
		temp_face.rotate_right();
		faces[1] = temp_face;
	}
	else if ( c == (face_size-1) ){				//if it's the right-most column, rotate the right face counter-clockwise
		face temp_face(faces[2]);
		temp_face.rotate_left();
		faces[2] = temp_face;
	}
}

void cube::rotate_col_up( int c ){				//rotate the cth column up
	vector<Color> temp_col;
	temp_col = faces[0].get_col( c );
	faces[0].set_col( c, faces[4].get_col( c ));
	faces[4].set_col( c, faces[5].get_col( c ));
	faces[5].set_col( c, faces[3].get_col( c ));
	faces[3].set_col( c, temp_col );
	if( c == 0 ){								//if it's the left-most column, rotate the left side counter-clockwise
		face temp_face(faces[1]);
		temp_face.rotate_left();
		faces[1] = temp_face;
	}			
	else if ( c == 2 ){							//if it's the right-most column, rotate the right side clockwise
		face temp_face(faces[2]);
		temp_face.rotate_right();
		faces[2] = temp_face;
	}
}

void cube::randomize(int turns){				//do random rotate operations where turns is the number of random operations
	int rand_num;
	srand(time(NULL));							//seed with time for random values
	for( int i = 0; i < turns; i++ ){
		rand_num = rand() % 8;					//8 operations
		switch( rand_num ){
			case 0: 
				this->rotate_up(); 
				break;
			case 1: 
				this->rotate_down(); 
				break;
			case 2: 
				this->rotate_right(); 
				break;
			case 3: 
				this->rotate_left(); 
				break;
			case 4: 
				rand_num = rand() % face_size;
				this->rotate_row_right(rand_num); 
				break;
			case 5:
				rand_num = rand() % face_size;
				this->rotate_row_left(rand_num); 
				break;
			case 6: 
				rand_num = rand() % face_size;
				this->rotate_col_up(rand_num); 
				break;
			case 7: 
				rand_num = rand() % face_size;
				this->rotate_col_down(rand_num); 
				break;
		}
	}
}



