#include "circle.hpp"

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"

#include <cmath>
#include <iostream>

Circle::Circle() {
    mid_ = {100.0f, 100.0f};
    rad_ = 50.0f;
    col_ = {};
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}
//4.5
Circle::Circle(float f) {
    mid_ = {1.0f, 1.0f};
    rad_ = f;
}
Circle::Circle(float f, Vec2 const& v) {
    rad_ = f;
    mid_ = v;
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}

Circle::Circle(float f, Vec2 const& v, Color const& c) {
    rad_ = f;
    mid_ = v;
    col_ = c;
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}

Circle::Circle(float f, Vec2 const& v, Color const& c, Color const& h) {
    rad_ = f;
    mid_ = v;
    col_ = c;
    highlight_color_ = h;
}

float Circle::circumference() const {
    return 2 * M_PI * abs(rad_);
}
float Circle::radius() const { //4.5
    return rad_;
}
void Circle::draw(Window const& w) const {
    draw(w, false, 1.0f);
}
void Circle::draw(Window const& w, bool const h, float const t) const {
    Color c;
    h ? c = highlight_color_ : c = col_;
    /* calculating the actual coordinates for a point on the edge 
    of the circle and using it as a template to rotate the following vectors */
    float r = sqrt((rad_ / 2) * (rad_ / 2) * 2 );
    const Vec2 origin {r, r};
    Vec2 v1{origin};
    Vec2 v2{origin};
    int i = 1;
    //made the segments usable for the rotation matrix via part_
    const int seg = 200;
    const float part = seg / (2 * M_PI);
    v2 = v2 + mid_;
    while (i <= seg) {
        v1 = v2;
        v2 = origin;
        v2 = make_rotation_mat2(i / part) * v2;
        v2 = mid_ + v2;
        w.draw_line(v1.x_, v1.y_, v2.x_, v2.y_, c.r_, c.g_, c.b_, t);
        i++;
    }
}

bool Circle::is_inside(Vec2 const& v) const {
    Vec2 vdist = mid_ - v;
    float dist = sqrt((vdist.x_ * vdist.x_) + (vdist.y_ * vdist.y_));
    return (dist <= abs(rad_) ? true : false);
}

//this method is only needed for the clock
void Circle::line(Window const& w, float time, float passed, float thickness, float dist) const {
    float r = sqrt((rad_ / 2) * (rad_ / 2) * 2 );
    const Vec2 origin {r, r};
    Vec2 v1{origin};
    //used to rotate the default vector via rotation matrix to the 12' position
    const float vzero = (3.0f / 4.0f) * M_PI;
    const float part = 60 / (2 * M_PI);
    v1 = make_rotation_mat2(((passed / time) / - part) + vzero) * v1 ;
    if (dist != 0)  {
        //only for the min/quart/hr marks
        Circle c{rad_- dist, mid_,{0.36f, 0.36f, 0.36f}};
        c.line(w, time, passed, thickness + 0.2f);
        v1 = mid_ + v1;
        w.draw_line(v1.x_, v1.y_, mid_.x_, mid_.y_, col_.r_, col_.g_, col_.b_, thickness);
        c.line(w, time, passed, thickness + 0.2f);
    }
    else {
        v1 = mid_ + v1;
        w.draw_line(v1.x_, v1.y_, mid_.x_, mid_.y_, col_.r_, col_.g_, col_.b_, thickness);
    }
}

//4.5
bool operator<(Circle const& rhs, Circle const& lhs) {
    return rhs.radius() < lhs.radius();
}
bool operator>(Circle const& rhs, Circle const& lhs) {
    return rhs.radius() > lhs.radius();
}
bool operator==(Circle const& rhs, Circle const& lhs) {
    return rhs.radius() == lhs.radius();
}