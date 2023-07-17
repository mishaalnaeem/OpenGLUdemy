#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const GLint WIDTH = 800, HEIGHT = 600;


int main() {

	// Init GLFW
	if (! glfwInit())
	{
		std::cout << "GLFW Init Failed\n";
		glfwTerminate();
		return 1;
	}

	//GLFW Window Properties

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //cannot use depreciated functions - no backward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //forward compatible

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		std::cout << "Window init failed\n";
		glfwTerminate();
		return 1;
	}

	//Get buffer size
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//Set context for GLFW to use
	glfwMakeContextCurrent(mainWindow); //current window

	glewExperimental = GL_TRUE; // allow modern extension features 

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW init failed\n";
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Set viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		//Get and handle user input events

		//check if any events have happened
		glfwPollEvents();

		//clear window
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);


	}


	return 0;
}