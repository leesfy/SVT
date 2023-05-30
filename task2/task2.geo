//+
Point(1) = {0, 0, 0, 1.0};
//+
Point(2) = {1, 0, 0, 1.0};
//+
Point(3) = {1, 1, 0, 1.0};
//+
Point(4) = {0, 1, 0, 1.0};
//+
Line(1) = {4, 3};
//+
Line(2) = {3, 2};
//+
Line(3) = {2, 1};
//+
Line(4) = {1, 4};
//+
Line(5) = {4, 2};
//+
Curve Loop(1) = {1, 2, -5};
//+
Plane Surface(1) = {1};
//+
Curve Loop(2) = {5, 3, 4};
//+
Plane Surface(2) = {2};
//+
Transfinite Curve {4} = 8 Using Progression 0.5;
//+
Transfinite Curve {2} = 8 Using Progression 0.5;
//+
Transfinite Curve {1} = 8 Using Progression 1.5;
//+
Transfinite Curve {3} = 8 Using Progression 1.5;
//+
Transfinite Curve {5} = 20 Using Progression 1;
