#include "decorator.h"
#include <iostream>

int main()
{

    auto text_block1 = new ItalicText(new BoldText(new Text()));
    text_block1->render("Hello world");
    std::cout << std::endl;

    auto text_block2 = new Paragraph(new Text());
    text_block2->render("Hello world");
    std::cout << std::endl;

    auto text_block3 = new Reversed(new Text());
    text_block3->render("Hello world");
    std::cout << std::endl;

    auto text_block4 = new Link(new Text());
    text_block4->render("netology.ru", "Hello world");
    std::cout << std::endl;

    auto text_block5 = new Link(new Paragraph(new ItalicText(new BoldText(new Reversed(new Text())))));
    text_block5->render("netology.ru", "NETOLOGY");
    std::cout << std::endl;

    // exit

    std::cout << std::endl;
    std::cout << "PRESS ENTER...";
    std::cin.get();
    return EXIT_SUCCESS;
}