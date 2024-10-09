// hassan abdi
// this is for attnedee .h file where i decrlare everything i need for my .h file
//

#include "myutil.h"



class attendee {
	private:
		char * name;
		int age;

	public:
		attendee();
		attendee(const char * name);
		attendee(const char * name, int age);
		attendee(const attendee& Aattendee);
		~attendee();
		void input_a();
		const attendee& operator = (const attendee& Aattendee);
		friend ostream& operator< (ostream& out, const attendee& Aattendee);

	};

class child : public attendee {

	private: 


	public:

}

class adult : public attendee {

	private:


	public:

	}

class animal : public attendee {

	private:


	public:


}

