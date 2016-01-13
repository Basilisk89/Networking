#include "Debug.h"
// Game lib namespace
using namespace Game_Lib;
// prints out the EMessageType , Class string , Method string , file path string , line string , current date string , and a message and apps to an file called Debuglog.txt
void Debug::Log(const EMessageType MsgType, const std::string& Class, const std::string& Method, const std::string& file, const int& line, const std::string& message) {
	//clock objs
	std::chrono::system_clock::time_point currenttime;
	// initialize time_point
	currenttime = std::chrono::system_clock::now();
	//convert the currenttime obj into a time_t obj
	static time_t debugTime = Debug::getCurrentTime(currenttime);
	// file stream obj
	static std::ofstream debugLog;
	// open the stream obj
	debugLog.open("debugLog.txt", std::ofstream::app | std::ofstream::out);
	//switch statement using what type of message i should be getting
	switch (MsgType) {
		// for info print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::INFO:
		debugLog << "INFO: " << Class << "::" << Method << "() - " << "\n File :: " << file << "\n Line :: " << line << "\n Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		// break for next case
		break;
		// for warning print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::WARNING:
		debugLog << "WARNING: " << Class << "::" << Method << "() - " << "File :: " << file << ", Line :: " << line << ", Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		// break for next statement
		break;
		// for Error print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::ERROR:
		debugLog << "ERROR: " << Class << "::" << Method << "() - " << "File :: " << file << ", Line :: " << line << ", Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		// break for next statement
		break;
		// for FATAL_ERROR print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::FATAL_ERROR:
		debugLog << "FATAL ERROR: " << Class << "::" << Method << "() - " << "File :: " << file << ", Line :: " << line << ", Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		//final break
		break;
	}
	//close the file
	debugLog.close();
}
// LOOK UP LOG DEFINITION , added threadID
void Debug::Log(const EMessageType MsgType, const std::string& Class, const std::string& Method, const std::string& file, const int& line, const std::thread::id& threadid, const std::string& message) {
	//clock objs
	time_t debugTime;
	std::chrono::system_clock::time_point currenttime;
	// initialize time_point
	currenttime = std::chrono::system_clock::now();
	//convert the currenttime obj into a time_t obj
	debugTime = Debug::getCurrentTime(currenttime);
	// file stream obj
	std::fstream debugLog;
	// open the stream obj
	debugLog.open("debugLog.txt", std::fstream::app | std::fstream::out);
	//switch statement using what type of message i should be getting
	switch (MsgType) {
		// for info print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::INFO:
		debugLog << "INFO: " << Class << "::" << Method << "() - " << "\n File :: " << file << "\n Line :: " << line << "\n Date :: " << ctime(&debugTime) << " Thread ID :: " << threadid << "\n Message :: " << message << "\n\n";
		// break for next case
		break;
		// for warning print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::WARNING:
		debugLog << "WARNING: " << Class << "::" << Method << "() - " << "File :: " << file << ", Line :: " << line << ", Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		// break for next statement
		break;
		// for Error print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::ERROR:
		debugLog << "ERROR: " << Class << "::" << Method << "() - " << "File :: " << file << ", Line :: " << line << ", Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		// break for next statement
		break;
		// for FATAL_ERROR print out the Class , Method of class , file path , which line the log was called , current time and date and a message regarding what could or is possibly happening
	case EMessageType::FATAL_ERROR:
		debugLog << "FATAL ERROR: " << Class << "::" << Method << "() - " << "File :: " << file << ", Line :: " << line << ", Date :: " << ctime(&debugTime) << " Message :: " << message << "\n\n";
		//final break
		break;
	}
	//close the file
	debugLog.close();
}
//cleans the debuging file
void Debug::clean() {
	// file stream cleaner obj
	std::fstream cleaner;
	// open the file for the cleaner obj to do its job
	cleaner.open("debugLog.txt", std::fstream::out);
	// then close it , cleaning the whole file
	cleaner.close();
}