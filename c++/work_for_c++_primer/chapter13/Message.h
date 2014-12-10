#ifndef CHAPTER13_MESSAGE_H
#define CHAPTER13_MESSAGE_H

#include <string>
#include <set>

class Message {
	friend class Folder;
	public :
		explicit Message(std::string &str = "") :
			contents(str) {}
		Message(const Message&);
		Message& operator=(const Message&);
		~Message();

		void svae(Folder&);
		void remove(Folder&)
	private :
		std::string contents;
		std::set<Folder *> folders;
		void add_to_folder(const Message&);
		void remove_from_folder();
};

#endif
