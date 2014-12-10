#include "Folder.h"

void Folder::add_to_folder(Floder &f) {
	for(auto msg : f.msgs) {
		msg->folder.insert(this);
	}
}

void Folder::remove_out_folder() {
	for(auto msg : msgs) {
		msg->folders.erase(this);
	}
}

void Folder::addMsg(const Message *msg) {
	msgs.insert(msg);
}

void Folder::removeMsg(const Message *msg) {
	msgs.erase(msg);
}

Folder::Folder(const Folder &f) : 
	name(f.name), msgs(f.msgs) {
	add_to_folder(f);
}

Folder::Folder &Folder::operator=(const Folder &rhs) {
	remove_out_folder();
	name = rhs.name;
	msgs = rhs.msgs;
	add_to_folder(this);
	return *this;
}
