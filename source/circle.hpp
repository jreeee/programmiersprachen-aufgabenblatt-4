#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {

    public:
    Circle();
    Circle(float f); //4.5
    Circle(float f, Vec2 const& v);
    Circle(Vec2 const& v, float f);
    Circle(float const f, Vec2 const& v, Color const& c);
    Circle(Vec2 const& v, float const f, Color const& c);
    Circle(float const f, Vec2 const& v, Color const& c, Color const& h);

    float circumference() const;
    void draw(Window const& w) const;
    void draw(Window const& w, bool highlight = false, float t = 1.0f) const;
    bool is_inside(Vec2 const& v) const;
    void line(Window const& w, float time, float passed, float thickness, float dist = 0.0f) const;

    private:
    Vec2 mid_;
    float rad_;
    Color col_;
    Color highlight_color_;
};

//added for 4.5
bool operator<(Circle const& rhs, Circle const& lhs);
bool operator>(Circle const& rhs, Circle const& lhs);
bool operator==(Circle const& rhs, Circle const& lhs);

#endif