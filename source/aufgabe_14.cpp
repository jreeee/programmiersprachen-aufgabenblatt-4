#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>   //std::ostream_iterator<>
#include <functional>
#include <thread>
#include <chrono>

#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"

#include <cmath>


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

    auto comp = [] (std::string const& s, Circle c) {return s == c.name(); };

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        win.close();
        }
        std::cout << "\nthe following circles can be highlighted:\n\n";
        for (auto i : circles) {
            std::cout << i.name() << " ";
        }
        std::cout << "\n\nplease enter the name of the circle you want to highight\n\n";
        std::string str; 
        std::cin >> str;
        bool cont_circ;
        bool found = false;
        for (auto i : circles) {
            cont_circ = comp(str, i);
            cont_circ ? i.draw(win, true, 2.0f) : i.draw(win, false, 2.0f); 
            if (!found && cont_circ) found = true;
        }

        win.update();
        
        if (found) {
            std::cout << "\n-> hightlighting circle " << str << " for 10 seconds\n";
            std::this_thread::sleep_for(std::chrono::seconds(10));
        } else {
            std::cout << "\n-> the specified circle could not be found\n";
        }

        

        
    }
    return 0;
}