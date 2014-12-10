#ifndef CHAPTER13_FOLDER_H
#define CHAPTER13_FOLDER_H


class Folder {
	friend class Message;
	public :
		Folder(std::string str = "") :
			name(str) {}
		Folder(const Folder&);
		Folder& operator=(const Folder&);

		void addMsg(const Message*);
		void removeMsg(const Message*);
	private :
		std::string name;
		std::set<Message *> msgs;
		void add_to_folder(const Folder&);
		void remove_out_folder();
}


#endif
