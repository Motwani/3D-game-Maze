VAO *triangle, *tri,*rect;

// Creates the triangle object used in this sample code
void createTriangle ()
{
  /* ONLY vertices between the bounds specified in glm::ortho will be visible on screen */

  /* Define vertex array as used in glBegin (GL_TRIANGLES) */
  static const GLfloat vertex_buffer_data [] = {
    1, 0,0, // vertex 0
    -1,-1,0, // vertex 1
    1,-1,0, // vertex 2
  };

  static const GLfloat color_buffer_data [] = {
    1,0,0, // color 0
    0,1,0, // color 1
    0,0,1, // color 2
  };

  static const GLfloat vert [] = {
	  1,0,0,
	  -1,-1,0,
	  1,-1.5,0,
  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  triangle = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, color_buffer_data, GL_LINE);
  tri = create3DObject(GL_TRIANGLES, 3 , vert, color_buffer_data, GL_LINE);
}

// Creates the rectangle object used in this sample code
cube createCube (float x,float y,float z,float l,float b,float h)
{
  // GL3 accepts only Triangles. Quads are not supported
  GLfloat vertex_buffer_data [] = {
    x,y,z, // vertex 1
    x+l,y,z, // vertex 2
    x+l,y,z+b, // vertex 3

    x+l,y,z+b, // vertex 3
    x,y,z+b, // vertex 4
    x,y,z,  // vertex 1

    x+l,y,z,
    x+l,y+h,z,
    x+l,y,z+b,

    x+l,y,z+b,
    x+l,y+h,z+b,
    x+l,y+h,z,

    x,y+h,z,
    x+l,y+h,z,
    x+l,y+h,z+b,

    x+l,y+h,z+b,
    x,y+h,z+b,
    x,y+h,z,

    x,y,z+b,
    x,y+h,z+b,
    x,y+h,z,

    x,y+h,z,
    x,y,z+b,
    x,y,z,

    x,y,z+b,
    x,y+h,z+b,
    x+l,y+h,z+b,

    x+l,y+h,z+b,
    x+l,y,z+b,
    x,y,z+b,

    x,y,z,
    x+l,y,z,
    x+l,y+h,z,

    x+l,y+h,z,
    x,y+h,z,
    x,y,z,


  };

  static const GLfloat color_buffer_data [] = {

    0.051,0.1961,0.302, // color 1
    0.051,0.1961,0.302, // color 1
    0.051,0.1961,0.302, // color 1

    0.051,0.1961,0.302, // color 1
    0.051,0.1961,0.302, // color 1
    0.051,0.1961,0.302, // color 1

    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1

    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1

    0,0.447,0.7373, // color 1
    0,0.447,0.7373, // color 2
    0,0.447,0.7373, // color 3

    0,0.447,0.7373, // color 1
    0,0.447,0.7373, // color 2
    0,0.447,0.7373, // color 3

    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1

    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1

    0.1451,0.3608,0.6, // color 1
    0.1451,0.3608,0.6, // color 1
    0.1451,0.3608,0.6, // color 1

    0.1451,0.3608,0.6, // color 1
    0.1451,0.3608,0.6, // color 1
    0.1451,0.3608,0.6, // color 1

    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1

    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1
    0.0588,0.0588,0.2627, // color 1


  };

  cube cube_obj;
  // create3DObject creates and returns a handle to a VAO that can be used later
  cube_obj.vao = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, color_buffer_data, GL_FILL);
  return cube_obj;
}
VAO *player;

VAO* createPlayer (float x,float y,float z,float l,float b,float h)
{
  // GL3 accepts only Triangles. Quads are not supported
  GLfloat vertex_buffer_data [] = {
    x,y,z, // vertex 1
    x+l,y,z, // vertex 2
    x+l,y,z+b, // vertex 3

    x+l,y,z+b, // vertex 3
    x,y,z+b, // vertex 4
    x,y,z,  // vertex 1

    x+l,y,z,
    x+l,y+h,z,
    x+l,y,z+b,

    x+l,y,z+b,
    x+l,y+h,z+b,
    x+l,y+h,z,

    x,y+h,z,
    x+l,y+h,z,
    x+l,y+h,z+b,

    x+l,y+h,z+b,
    x,y+h,z+b,
    x,y+h,z,

    x,y,z+b,
    x,y+h,z+b,
    x,y+h,z,

    x,y+h,z,
    x,y,z+b,
    x,y,z,

    x,y,z+b,
    x,y+h,z+b,
    x+l,y+h,z+b,

    x+l,y+h,z+b,
    x+l,y,z+b,
    x,y,z+b,

    x,y,z,
    x+l,y,z,
    x+l,y+h,z,

    x+l,y+h,z,
    x,y+h,z,
    x,y,z,


  };

  static const GLfloat color_buffer_data [] = {


    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1


    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1


    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1

    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1


    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1
    0.9098,0.7725,0.2784, // color 1


  };

  // create3DObject creates and returns a handle to a VAO that can be used later
  player = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, color_buffer_data, GL_FILL);
  return player;
}
