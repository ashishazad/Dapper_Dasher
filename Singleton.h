// #pragma once
// #include <mutex>

// class Singleton
// {
// protected:
// 	Singleton();
// 	static Singleton* instance;
// 	static std::mutex mutex_;
// 	// Singleton()
// 	// {

// 	// }

// 	static void InitInstance()
// 	{
// 		instance = new Singleton();
// 	}
// public:
// 	Singleton(Singleton& other) = delete;
// 	void operator=(Singleton& other) = delete;

// 	static Singleton* getInstance()
// 	{
// 		std::lock_guard<std::mutex> lock(mutex_);
// 		if (instance == nullptr)
// 		{
// 			InitInstance();
// 		}
// 		return instance;
// 	}
// };

// Singleton* Singleton::instance = nullptr;
// std::mutex Singleton::mutex_;