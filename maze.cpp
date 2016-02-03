#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
int total = 0 ;
int height_mat[1000][1000]={0};
int width = 1000;
int wheight = 1000;
int x_axis = 0,y_axis = 0;
GLFWwindow* window;
#include "important.cpp"

/**************************
 * Customizable functions *
 **************************/

float camera_rotation_angle = 0;
float triangle_rot_dir = 1;
float rectangle_rot_dir = 1;
bool triangle_rot_status = true;
bool rectangle_rot_status = true;
float a = 2;
float factor = 0;
int dir = 1;
/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
#include "keyboard.cpp"
/* Executed when window is resized to 'width' and 'height' */
/* Modify the bounds of the screen here in glm::ortho or Field of View in glm::Perspective */
void reshapeWindow (GLFWwindow* window, int width, int height)
{
    int fbwidth=width, fbheight=height;
    /* With Retina display on Mac OS X, GLFW's FramebufferSize
     is different from WindowSize */
    glfwGetFramebufferSize(window, &fbwidth, &fbheight);

	GLfloat fov = 90.0f;

	// sets the viewport of openGL renderer
	glViewport (0, 0, (GLsizei) fbwidth, (GLsizei) fbheight);

	// set the projection matrix as perspective
	/* glMatrixMode (GL_PROJECTION);
	   glLoadIdentity ();
	   gluPerspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1, 500.0); */
	// Store the projection matrix in a variable for future use
    // Perspective projection for 3D views
    // Matrices.projection = glm::perspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1f, 500.0f);

    // Ortho projection for 2D views
    Matrices.projection = glm::ortho(-150.0f, 150.0f, -150.0f, 150.0f, -150.0f, 150.0f);
}

#include "objects.cpp"
#include "draw.cpp"

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL (GLFWwindow* window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
	// Create the models
	//createTriangle (); // Generate the VAO, VBOs, vertices data & copy into the array buffer
  int i,j,k,he;
  int c = 0;
  for(k=0;k<10;k++){
  for(i = -5;i<5;i++){
  // if(k == 4 && i == 0)
  he = rand()%40 ;
  // else
  // he = 0;
  cube cube_object = createCube(2 + i*15,2,2 - k*15,15,15,he);
  cube_object.height = he;
  height_mat[k][i] = he;
  cube_vec.push_back(cube_object);
 }
 }
  // for(k=0;k<10;k++){
  // for(int j=1;j<=5;j++,i++){
  //   int he = rand()%40;
  //   int toss = rand()%2;
  //   if(toss == 0)
  //   {
  //     cube cube_object = createCube(2 - j*15,2,2 - k*15,15,15,he);
  //     cube_object.height = he;
  //     height_mat[k][j] = he;
  //     cube_vec.push_back(cube_object);
  //   }
  //   else
  //     height_mat[k][j] = 0;
  //   }
  // }
  // for(i = 0;i<5;i++)
  // 	border_obj[i].border = createBorder(2 + i*15,2,2,15,15,15);
  // for(j=1;j<=5;j++,i++)
  //   border_obj[i].border = createBorder(2 - j*15,2,2,15,15,15);
  createPlayer(2,2,-58,15,15,15);

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	// Get a handle for our "MVP" uniform
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


	reshapeWindow (window, width, height);

    // Background color of the scene
	glClearColor (0.4941f, 0.6392f, 0.8f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main (int argc, char** argv)
{

  srand(time(NULL));



  window = initGLFW(width, wheight);
	initGL (window, width, wheight);

    double last_update_time = glfwGetTime(), current_time;

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {

        // OpenGL Draw commands
        draw();
        // Swap Frame Buffer in double buffering
        glfwSwapBuffers(window);

        // Poll for Keyboard and mouse events
        glfwPollEvents();

        // Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
        current_time = glfwGetTime(); // Time in seconds
        if ((current_time - last_update_time) >= 0.1) { // atleast 0.5s elapsed since last frame
            // do something every 0.5 seconds ..
            if(factor >= 30)
              dir = -1;
            if(factor <= -30)
              dir = 1;
            if(dir == 1)
              factor += 5;
            else
              factor -= 5;

            last_update_time = current_time;
        }
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
}
