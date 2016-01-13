#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
namespace Game_Lib {
	// This enum is a simple 8-bit unsigned int
	enum class EMessageType : unsigned short {
		//0
		INFO = 0,
		//1
		WARNING,
		//2
		ERROR,
		//3
		FATAL_ERROR
	};
	class Debug {
	public:
		// New in C++ 11: this deletes the automatic constructor from being formed if no other constructor is declared
		Debug() = delete;
		// kill off all default constructors for DEBUG class copy constructors , zero parameter constructors
		Debug(const Debug&) = delete;
		Debug(Debug&&) = delete;
		Debug& operator=(const Debug&) = delete;
		Debug& operator=(Debug&&) = delete;
		// prints out the EMessageType , Class string , Method string , file path string , line string , current date string , and a message and apps to an file called Debuglog.txt
		static void Log(const EMessageType MsgType, const std::string& Class, const std::string& Method, const std::string& file, const int& line, const std::string& message);
		static void Log(const EMessageType MsgType, const std::string& Class, const std::string& Method, const std::string& file, const int& line, const std::thread::id& threadid, const std::string& message);
		//cleans the debug file called debuglog.txt
		static void clean();
	protected:
	private:

		// for debugger ONLY, get the current time from time_point and put it into a time_t obj and return time_t as an obj
		static const time_t getCurrentTime(const std::chrono::system_clock::time_point& tp) {
			//time obj
			std::time_t time;
			// convert tTime value into a time_t value
			time = std::chrono::system_clock::to_time_t(tp);
			// return time_t obj time
			return time;
		}
	};
}

#endif