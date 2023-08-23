#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }

    virtual void render(std::string link, const std::string & data) const {
        std::cout << data;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph: public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
    
};

// >>> <p>Hello world</p>

// std::reverse
class Reversed: public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {

        std::string tmp = data;        

        std::reverse(tmp.begin(), tmp.end());
        text_->render(tmp);        
    }
};

// >>> dlrow olleH

class Link: public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(std::string link, const std::string & data) const {
        std::cout << "<a href=" << link << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

// >>> <a href=netology.ru>Hello world</a>