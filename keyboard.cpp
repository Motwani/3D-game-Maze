void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
     // Function is called first on GLFW_PRESS.

    if (action ==   GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_LEFT:
                camera_rotation_angle -= 1;
                break;
            case GLFW_KEY_RIGHT:
                camera_rotation_angle += 1;
                break;
            case GLFW_KEY_UP:
                a += 0.2;
                break;
            case GLFW_KEY_DOWN:
		            a -= 0.2;
                // do something ..
                break;
            default:
                break;
        }
    }
    else if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                quit(window);
                break;
          case GLFW_KEY_T:
              if(a != 17)
                a = 17;
                else a = 2.8;
                break;
          case GLFW_KEY_A:
                q -= 15;
                x_axis = -1;
                break;
          case GLFW_KEY_D:
                q += 15;
                x_axis = +1;
                break;
          case GLFW_KEY_W:
                w -= 15;
                y_axis = +1;
                break;
          case GLFW_KEY_S:
                w += 15;
                y_axis = -1;
                break;
            default:
                break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{
	switch (key) {
		case 'Q':
		case 'q':
            quit(window);
            break;
		default:
			break;
	}
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
    switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            if (action == GLFW_RELEASE)
                triangle_rot_dir *= -1;
            break;
        case GLFW_MOUSE_BUTTON_RIGHT:
            if (action == GLFW_RELEASE) {
                rectangle_rot_dir *= -1;
            }
            break;
        default:
            break;
    }
}
