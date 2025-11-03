#include <iostream>
#include <GLFW/glfw3.h>

GLFWwindow* StartGLFW();

int main(){
    GLFWwindow* window = StartGLFW();

    float centerX = screenWidth / 2.0f;
    float centerY = screenHeight / 2.0f;
    float radius = 50.0f;
    int res = 100;

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centerX, centerY);
        
        for(int i = 0; i <= res; ++i){
            float angle = 2.0f * 3.1415926f * (static_case<float>(i)) / res;
            float x = centerX + cos(angle) * radius;
            float y = centerY + sin(angle) * radius;
            glVertex2d(x, y);
        }

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

GLFWwindow* StartGLFW(){
    if(!glfwInit()){
        std::cerr<<"Failed to initialize GLFW"<<std::endl;
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "gravity sim", NULL, NULL);
}
