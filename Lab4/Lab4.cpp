#include <iostream>
#include <fstream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Shape {
public:
    virtual void printInfo() const = 0;
    virtual double getArea() const = 0;
};
class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getLength() const {
        return 2 * 3.14 * radius;
    }
    double getArea() const override {
        return 3.14 * radius * radius;
    }
    void printInfo() const override {
        cout << "Коло: радіус = " << radius << ", площа = " << getArea()
            << ", довжина = " << getLength() << endl;
    }
};
class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getPerimeter() const {
        return 2 * (width + height);
    }
    double getArea() const override {
        return width * height;
    }
    void printInfo() const override {
        cout << "Прямокутник: ширина = " << width << ", висота = " << height
            << ", площа = " << getArea() << ", периметр = " << getPerimeter() << endl;
    }
};
class RectangleInCircle : public Circle, public Rectangle {
public:
    RectangleInCircle(double r, double w, double h)
        : Circle(r), Rectangle(w, h) {}
    void printInfo() const override {
        cout << "Прямокутник, вписаний у коло:" << endl;
        cout << "Коло: радіус = " << radius << ", площа = " << Circle::getArea()
            << ", довжина = " << getLength() << endl;
        cout << "Прямокутник: ширина = " << width << ", висота = " << height
            << ", площа = " << Rectangle::getArea()
            << ", периметр = " << getPerimeter() << endl;
    }
    void writeToFile(const string& fileName) const {
        ofstream file(fileName);
        if (file.is_open()) {
            file << "Прямокутник, вписаний у коло:\n";
            file << "Коло: радіус = " << radius << ", площа = " << Circle::getArea()
                << ", довжина = " << getLength() << endl;
            file << "Прямокутник: ширина = " << width << ", висота = " << height
                << ", площа = " << Rectangle::getArea()
                << ", периметр = " << getPerimeter() << endl;
            file.close();
        }
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double radius, width, height;
    cout << "Введіть радіус кола: ";
    cin >> radius;
    cout << "Введіть ширину прямокутника: ";
    cin >> width;
    cout << "Введіть висоту прямокутника: ";
    cin >> height;
    RectangleInCircle pvk(radius, width, height);
    pvk.printInfo();
    pvk.writeToFile("figures_info.txt");
    return 0;
}