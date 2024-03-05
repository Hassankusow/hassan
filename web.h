/*
  Author: Hassan abdi
  Class: CS260
  Project: Project 3
  File: web.h
  Description: Header file for the info for the website.
*/

#pragma once

#include "myutil.h"

class info

{
public:
        info();
        info(const char * topic);
        info(const char * topic, const char * name, int rating, const char * review);
        ~info();
        info(const info& ainfo);
        void inputwebsite();
        const char * get_topic() const;
        const char * get_name() const;
        int get_rating() const;
        const char * get_review() const;
        void set_topic(const char * topic);
        void set_name(const char * name);
        void set_rating(int rating);
        void set_review(const char * review);
        

        const info& operator= (const info& ainfo);
        friend ostream& operator<< (ostream& out, const info& ainfo);

private:
        char* name;
        char* topic;
        char* review;
        int rating;

        void init(const char * topic, const char * name, int rating, const char * review);
       
};
