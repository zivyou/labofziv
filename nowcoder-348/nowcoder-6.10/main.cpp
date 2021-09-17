/**
 * Eagle Jump公司正在开发一款新的游戏。Hifumi Takimoto作为其中的员工，获得了提前试玩的机会。现在她正在试图通过一个迷宫。
这个迷宫有一些特点。为了方便描述，我们对这个迷宫建立平面直角坐标系。迷宫中有两条平行直线 L1:Ax+By+C1=0, L2:Ax+By+C2=0，还有 n 个圆 。角色在直线上、圆上、园内行走不消耗体力。在其他位置上由S点走到T点消耗的体力为S和T的欧几里得距离。
Hifumi Takimoto想从 L1 出发，走到 L2 。请计算最少需要多少体力。
 *
 */

// 单源最短路径问题

#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <float.h>

using namespace std;

class Shape {
public:
  virtual float distance(Shape&) = 0;
  int type; // 0: 直线, 1: 圆
  Shape(int type_) {
    type = type_;
  }
  virtual ~Shape() {};
};

class Line : public Shape {
  public:
    int A;
    int B;
    int C;
  public:
    Line(int a, int b, int c) : Shape(0) {
      A = a; B = b; C = c;
    }
    float distance(Shape& shape);
    ~Line(){};
};


class Circle : public Shape {
  public:
    float x1;
    float y1;
    float r;
  public:
    Circle(float x, float y, float r_) : Shape(1) {
      x1 = x; y1 = y; r = r_;
    }
    float distance(Shape& shape);
    ~Circle(){};
};

float Line::distance(Shape& shape) {
  float result = 0.0f;
  if (this == &shape) return 0.0f;
  if (shape.type == 0) {
    Line& l = (Line&)shape;
    return abs(C-l.C) / sqrt((A-l.A)*(A-l.A) + (B-l.B)*(B-l.B)); 
  } else {
    Circle& circle = (Circle&)shape;
    float distance = (abs(A*circle.x1 + B*circle.y1 + C) / (sqrt(A*A + B*B)));
    if (distance < circle.r)  return 0.0f;
    else return distance - circle.r;
  } 
  return result;
} 


float Circle::distance(Shape& shape) {
  float result = 0.0f;
  if (this == &shape) return 0.0f;
  if (shape.type == 0) {
    Line& line =  (Line&)shape;
    float distance = abs(line.A*x1 + line.B*y1 + line.C) / (sqrt(line.A*line.A + line.B*line.B));
    if (distance < r) return 0.0f;
    else return distance - r;
  } else {
    Circle& circle = (Circle&)shape;
    float distance = sqrt((x1-circle.x1)*(x1-circle.x1) + (y1-circle.y1)*(y1-circle.y1));
    if (distance < r+circle.r) return 0;
    else return (distance - r - circle.r);
  } 
  return result;

}

class NullShape : public Shape {
  public:
  NullShape() : Shape(-1) {};
  float distance(Shape& shape) {
   return -1.0f;
  }
  ~NullShape(){};
};

static NullShape nullShape; 
Shape* getNearestFromUnselected(std::unordered_map<Shape*, float>& map, std::unordered_set<Shape*>& selectedShapes) {
  float distance = FLT_MAX;
  Shape* result = &nullShape;
  for (auto elem : map) {
    if (selectedShapes.find(elem.first) == selectedShapes.end()) {
      if (elem.second < distance) {
        distance = elem.second;
        result = elem.first;
      }
    }
  }
  return result;
}

int main() {
  int n, A, B, C1, C2; cin>>n>>A>>B>>C1>>C2;
  Line l1(A, B, C1);
  Line l2(A, B, C2);
  std::vector<Shape*> data;
  data.push_back(&l1);
  data.push_back(&l2);
  int i=0;
  while (i++<n) {
    float x, y, r;
    cin>>x>>y>>r;
    Circle* c = new Circle(x, y, r);
    data.push_back(c); 
  }

  std::vector<std::string> name = {"l1", "l2", "c1", "c2"};
 
  for (int k=0; k<n+2; k++) {
    cout<<name[k]<<": "<<data[k]<<endl;
  }
  std::unordered_map<Shape*, float> result;
  for (auto s : data) {
    if (s == &l1) {
      result[&l1] = 0.0f;
    } else {
      result[s] = FLT_MAX; // FLT_MAX????
    }
  }

  std::unordered_set<Shape*> selectedShapes;
  Shape* shape = getNearestFromUnselected(result, selectedShapes);
  while (shape != &nullShape) {
    for (auto s : data) {
      if (selectedShapes.find(s) == selectedShapes.end()) {
        result[s] = result[shape] + shape->distance(*s);
      } else {
        result[s] = min(result[s], result[shape] + shape->distance(*s));
      }
    }
    selectedShapes.insert(shape);
    shape = getNearestFromUnselected(result, selectedShapes);
  }
 
  for (auto m : result) {
    cout<<m.first<<": "<<m.second<<endl;
  }

  cout<<setiosflags(ios::fixed)<<std::setprecision(7)<<  result[&l2]<< endl;
  for (auto d : data) {
    if (d != &l1 && d != &l2) {
      delete (Circle*)d;
    }
  }
  return 0;
}
