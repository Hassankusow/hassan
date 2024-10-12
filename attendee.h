// hassan abdi
// this is for attnedee .h file where i decrlare everything i need for my .h file
//

#include "myutil.h"

enum class attendee_type { NONE, KID, ADULT, ANIMAL };


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


	public:
		child();
		child(const char * name, attendee_type atype);
		void display() const;
	protected:
		attendee_type atype;
		

};

class adult : public attendee {
	public:
		
		adult();
		adult(const char * name, attendee_type a_type);
		void display const;
	protected:
		attendee_type a_atype;
	

	}

class animal : public attendee {

	public:
		animal();
		animal(const char * name, attendee_type a_atype);
		void display const;
	protected:

		attendee_type a_type;


}

