#include "Message.h"

void Message::add_to_folder(const Message &msg) {
	for(auto f : msg.folders) {
		f.addMsg(this);
	}
}

void Message::remove_from_folder() {
	for(auto f : folders) {
		f.removeMsg(this);
	}
}

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
} 

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.removeMsg(this);
}


Message::Message(const Message &msg) :
 contents(msg.contents), folders(msg.folders) {
	 add_to_folders(msg);
}

Message& Message::operator=(const Message &rhs) {
	remove_from_folder();
	content = rhs.content;
	folders = rhs.folders;
	add_to_folder(rhs);
	return *this;
}

Message::~Message() {
	remove_from_folders();
}
