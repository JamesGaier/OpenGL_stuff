// C++ std deps
#include <iostream>

// OpenGL deps
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
}

constexpr unsigned WIDTH = 800;
constexpr unsigned HEIGHT = 600;

int main()
{
    // initialize GLFW
    glfwInit();
    // get the correct version of GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // makes openGL work on mac

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

/*
    float triangle_vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
*/
/*
    float triangles_verticies[] = {
        -0.1f, 0.5f, 0.0f,
        -0.1f, 0.0f, 0.0f, // 3
        -0.5f, 0.0f, 0.0f,

        0.1f, 0.5f, 0.0f,
        0.1f, 0.0f, 0.0f, // 3
        0.5f, 0.0f, 0.0f,
    };
*/
    /*
    float rect_vertices[] = {
        0.5f, 0.5f, 0.0f, // 0
        0.5f, -0.5f, 0.0f, // 1
        -0.5f, -0.5f, 0.0f, // 2
        -0.5f, 0.5f, 0.0f, // 3
    };
    */
    float firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
    };



    unsigned int indices[] = { 
        0, 1, 3, // first triangle the indicies refer the the row of cordinates
        1, 2, 3 // second triangle
    };


// create and compile vertex shader
    const auto vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

// get error message if the vertex shader did not compiled successfully
    int vertexSuccess;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);

    if(!vertexSuccess)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Error shader compilation failed " << infoLog << std::endl;
    }

// fragment shader
    const auto fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

// fragment shader with yellow
    const auto fragmentShaderSourceYellow = R"(
        #version 330 core
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
        }
    )";

    unsigned int fragmentShaderYellow;
    fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, NULL);
    glCompileShader(fragmentShaderYellow);

// create the program and link the vertex shader and fragment shader
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    unsigned shaderProgramYellow;
    shaderProgramYellow = glCreateProgram();

    glAttachShader(shaderProgramYellow, vertexShader);
    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
    glLinkProgram(shaderProgramYellow);

// check if the program compiled correctly
    int shaderSuccess;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderSuccess);
    if(!shaderSuccess)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }


    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShaderYellow);

    


    unsigned VBOs[2], VAOs[2];
    unsigned EBO;

    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(0);


    // bind and populate the element buffer object
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    int nAttrib;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nAttrib);
    std::cout << "The maximum number of attributes supported is: " << nAttrib << std::endl;

    // example of swizzling
    glm::vec2 someVec;
    someVec.x = 1.0f;
    someVec.y = 1.0f;
    // dont swizzle there is a huge performance hit if you do
    // glm::vec3 differentVec = someVec.xyx; // this fills in each component with the specified component


    
    /*
    glm::vec3 anotherVec = differentVec.zyw;
    glm::vec4 otherVec = someVec.xxxx + anotherVec.yxzy;
    */

    while(!glfwWindowShouldClose(window))
    {
        // input 
        processInput(window);

        // rendering commands here

        // clear the screen to a light greenish color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgramYellow);

        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // check and call events and swap the buffers 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    glDeleteProgram(shaderProgramYellow);

    glfwTerminate();
}
