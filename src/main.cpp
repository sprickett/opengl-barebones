#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main(int argc,char* argv[])
{
    constexpr int width = 800;
    constexpr int height = 600;

    glfwInit();

    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, keyCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "OpenGL " <<  GLVersion.major << '.' << GLVersion.minor << '\n';

    glViewport(0, 0, width, height);

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate(); // clean up all glfw resources
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << "key: " <<  key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}