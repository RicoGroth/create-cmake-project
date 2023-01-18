#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	if(glfwInit() != GLFW_TRUE) {
		std::cerr << "[GLFW] glfwInit() failed\n";
		return EXIT_FAILURE;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window{glfwCreateWindow(800, 800, "<PROJECT_NAME>", nullptr, nullptr)};
	if(window == nullptr) {
		std::cerr << "[GLFW] glfwCreateWindow() returned nullptr\n";
		return EXIT_FAILURE;
	}
	glfwMakeContextCurrent(window);
	if(GLenum err = glewInit() != GLEW_OK) {
		std::cerr << "[GLEW] ";
		std::cerr << glewGetErrorString(err) << '\n';
		return EXIT_FAILURE;
	}
	std::cout << "OpenGL " << glGetString(GL_VERSION) << '\n';
	while(!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}
