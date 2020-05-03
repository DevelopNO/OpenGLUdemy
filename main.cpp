#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions 
const GLint WIDTH = 1000, HEIGHT = 1000;

int main() {

	// initialize GLFW
	if (!glfwInit()) {
		printf("GLFW Initialization failed!");
		glfwTerminate();
		return 1;
	}

	/// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile - no backward compatiblity
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatibility.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "TestWindow", NULL, NULL);
	if (!mainWindow) {
		printf("GLFW window creation failed");
		glfwTerminate();
		return 1;
	}

	// Get Buffer size information.
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context.
	glfwMakeContextCurrent(mainWindow);

	/// allow modern extenstions
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("glew Init failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, bufferWidth, bufferHeight);

	while (!glfwWindowShouldClose(mainWindow)) {
		// get and handle user events. 
		glfwPollEvents();

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}