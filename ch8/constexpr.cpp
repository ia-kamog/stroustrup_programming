struct Point { double x,y; };
constexpr double xscale = 10;
constexpr double yscale = 0.8;
constexpr Point scale(Point p) { return {xscale*p.x, yscale*p.y}; }
void user(Point p1)
{
     constexpr Point p2{10,10};

     Point p3 = scale(p1);
     Point p4 = scale(p2);

     //constexpr Point p5 = scale(p1);
     constexpr Point p6 = scale(p2);
}
