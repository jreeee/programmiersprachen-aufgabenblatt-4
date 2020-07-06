#include "window.hpp"   //fensterchen
#include <GLFW/glfw3.h> //window & draw
#include <set>          //std:set<>
#include <vector>       //std::vector<>
#include <iostream>    //std::cout, std::cin
#include <thread>      //for sleeping
#include <chrono>      //for sleeping

#include "circle.hpp"

/*
First I initialize all Circles in a vector, since that is the most convenient way for me.
I then initialize the multiset and fill it with copys  the circles of the vector.
Then I write a comparison function in a lambda to check if a string is equal to the name of a circle.
After that I show all of the circle names so the user doesn't have to guess them. 
They are then prompted to enter one of the names.
If there are one or more circles with that name they get highlighted for 10 seconds.
Otherwise the user is told, that there are no circles with the entered name.
*/

int main(int argc, char* argv[])
{
    Window win{std::make_pair(800,800)};
    
    std::vector<Circle> tmp {{{400.0f, 400.0f}, 380.0f, {0.1f, 0.3f, 0.6f}, "hans"},
                              {{100.0f, 100.0f}, 100.0f, {0.2f, 0.4f, 0.9f}, "fritz"},
                              {{700.0f, 700.0f}, 100.0f, {0.2f, 0.4f, 0.9f}, "dieter"},
                              {{100.0f, 700.0f}, 100.0f, {0.2f, 0.4f, 0.9f}, "karl"},
                              {{700.0f, 100.0f}, 100.0f, {0.2f, 0.4f, 0.9f}, "klaus"},
                              {{400.0f, 600.0f}, 50.0f, {0.3f, 0.8f, 0.4f}, "emil"},
                              {{600.0f, 400.0f}, 50.0f, {0.3f, 0.8f, 0.4f}, "bob"},
                              {{200.0f, 400.0f}, 50.0f, {0.3f, 0.8f, 0.4f}, "alice"},
                              {{400.0f, 200.0f}, 50.0f, {0.3f, 0.8f, 0.4f}, "emma"},
                              {{400.0f, 400.0f}, 200.0f, {0.2f, 0.5f, 0.2f}, "anna"},
                              {{400.0f, 400.0f}, 100.0f, {0.6f, 0.8f, 0.8f}, "kim"},
                              {{400.0f, 400.0f}, 10.0f, {0.8f, 0.9f, 0.9f}, "karl"},
                              {{0.0f, 0.0f}, 75.0f, {0.4f, 0.6f, 1.0f}, "alice"},
                              {{0.0f, 800.0f}, 75.0f, {0.4f, 0.6f, 1.0f}, "dora"},
                              {{800.0f, 0.0f}, 75.0f, {0.4f, 0.6f, 1.0f}, "luise"},
                              {{800.0f, 800.0f}, 75.0f, {0.4f, 0.6f, 1.0f}, "test"}};

    std::multiset<Circle> circles;

    for (auto i : tmp) {
        circles.emplace(i);
    }

    auto comp = [] (std::string const& s, Circle const& c) {return s == c.name(); };

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        win.close();
        }
        std::cout << "\nthe following circles can be highlighted:\n\n";
        for (auto i : circles) {
            std::cout << i.name() << " ";
        }
        std::cout << "\n\nplease enter the name of the circle you want to highight\n\n>";
        std::string str; 
        std::cin >> str;

        bool found = false;
        for (auto i : circles) {
            comp(str, i) ? i.draw(win, true, 2.0f) : i.draw(win, false, 2.0f); 
            if (!found && comp(str, i)) found = true;
        }

        win.update();

        if (found) {
            std::cout << "\n-> hightlighting circle " << str << " for 10 seconds\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(10));
        } else {
            std::cout << "\n-> the specified circle could not be found\n\n";
        }
    }
    return 0;
}