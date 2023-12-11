#include"pch.h"
#include "OtterApp.h"
#include"Utilities.h"
#include"Otter.h"
#include"Shader.h"
#include"Picture.h"
#include"Renderer.h"
#include"Unit.h"


namespace ot
{
	template<typename T>
	OtterApp<T>::OtterApp()
	{
		mWindow.Create("Game AW", 1000, 800);

		mRenderer.Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); }); //[](){}
	}

	template<typename T>
	void OtterApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void OtterApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void OtterApp<T>::Run()
	{
		ot::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		// ot::Picture mPic{ "../Assets/Pictures/test.png" };
		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue) 
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());
			// Pic.Bind();
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void OtterApp<T>::OnUpdate()
	{
	}
	
	template<typename T>
	void OtterApp<T>::Draw(int x, int y, Picture& pic)
	{
		mRenderer.Draw(x, y, pic);
	}
	
	template<typename T>
	void OtterApp<T>::Draw(Unit& item) {
		mRenderer.Draw(item.GetXCoord(), item.GetYCoord(), item.mImage);
	}
	


	template<typename T>
	void OtterApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void OtterApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void OtterApp<T>::SetWindowCloseCallback(std::function<void()> callBackFunc)
	{
		mWindow.SetWindowCloseCallback(callBackFunc);
	}

	template<typename T>
	void OtterApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}

}




/*
template<typename T>
void OtterApp<T>::Run()
{
	mWindow.Create("Game AW", 1000, 800);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		OT_ERROR("Failed to initialize GLAD");
		return;
	}

	float vertices[] = {
		100.f, 100.f, 0.0f, 0.0f,
		300.f, 100.f, 1.0f, 0.0f,
		100.f, 300.f, 0.0f, 1.0f,
		300.f, 300.f, 1.0f, 1.0f

	};

	unsigned int indices[] = {
		0, 1, 2,
		1, 2, 3
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	////////////// Shaders /////////////

	ot::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
	shader.SetUniform2Ints("ScreenSize", 1000, 800);

	///////////// Textures //////////

	unsigned int texture; //ot::Picture pic{"......"};
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("../Assets/Pictures/test.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		OT_ERROR("Failed to load a picture from the file!!!");
	}
	stbi_image_free(data);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while (mShouldContinue)
	{
		OnUpdate();

		glClearColor(0.3f, 0.2f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		pic.Bind();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		mWindow.SwapBuffers();
		mWindow.PollEvents();
	}
}
*/