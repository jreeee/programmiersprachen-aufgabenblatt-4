#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"

#include <cmath>

int main(int argc, char* argv[])
{
    Window win{std::make_pair(800,800)};
    std::multiset<std::string, Circle> circles;
    auto str_crc_pair = std::make_pair<std::string, Circle> ;
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
                              {{800.0f, 800.0f}, 75.0f, {0.4f, 0.6f, 1.0f}, ""}};

    std::for_each(tmp.begin(), tmp.end(), [] 
                  (Circle const& c, std::multiset<Circle> & circles, auto & str_crc_pair) 
                  {circles.emplace(str_crc_pair = (c.name(), c));});

    float passed = win.get_time();


    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        win.close();
        }
        passed = win.get_time();

        /*hr.line(win, 360.0f, passed, 4.0f);
        min.line(win, 60.0f, passed, 3.0f);
        sec.line(win, 1.0f, passed, 2.0f);
        outer.draw(win, false,  5.0f);
       inner.draw(win, false, 5.0f);*/ 
        win.update();
    }
    return 0;
}