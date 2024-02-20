/*
  Author: Hassan abdi
  Class: CS260
  Project: Project 2
  File: line.h
  Description: Header file for the info of people wating on the line.
*/

#pragma once

#include "myutil.h"

class info

{
public:
	info();
	info(const char * group);
        info(const char * group, const char * name, int number, const char * chair, const char * adress);
        ~info();
        info(const info& ainfo);
	void inputgroup();
	const char * get_group() const;
	const char * getname() const;
	int getnumber() const;
	const char * get_chair() const;
	const char * get_adress() const;
	void set_group(const char * group);
	void set_name(const char * name);
	void set_no(int number);
	void set_chair(const char * chair);
	void set_adress( const char * adress);

	const info& operator= (const info& ainfo);
        friend ostream& operator<< (ostream& out, const info& ainfo);

private:
	char * group;
	char * name;
	char * adress;
	char * chair;
	int number;

	void init(const char * group, const char * name, int number, const char * chair, const char * adress);
	//bool operator< (const info& ainfo);
};
