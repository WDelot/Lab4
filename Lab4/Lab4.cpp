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
        cout << "����: ����� = " << radius << ", ����� = " << getArea()
            << ", ������� = " << getLength() << endl;
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
        cout << "�����������: ������ = " << width << ", ������ = " << height
            << ", ����� = " << getArea() << ", �������� = " << getPerimeter() << endl;
    }
};
class RectangleInCircle : public Circle, public Rectangle {
public:
    RectangleInCircle(double r, double w, double h)
        : Circle(r), Rectangle(w, h) {}
    void printInfo() const override {
        cout << "�����������, �������� � ����:" << endl;
        cout << "����: ����� = " << radius << ", ����� = " << Circle::getArea()
            << ", ������� = " << getLength() << endl;
        cout << "�����������: ������ = " << width << ", ������ = " << height
            << ", ����� = " << Rectangle::getArea()
            << ", �������� = " << getPerimeter() << endl;
    }
    void writeToFile(const string& fileName) const {
        ofstream file(fileName);
        if (file.is_open()) {
            file << "�����������, �������� � ����:\n";
            file << "����: ����� = " << radius << ", ����� = " << Circle::getArea()
                << ", ������� = " << getLength() << endl;
            file << "�����������: ������ = " << width << ", ������ = " << height
                << ", ����� = " << Rectangle::getArea()
                << ", �������� = " << getPerimeter() << endl;
            file.close();
        }
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double radius, width, height;
    cout << "������ ����� ����: ";
    cin >> radius;
    cout << "������ ������ ������������: ";
    cin >> width;
    cout << "������ ������ ������������: ";
    cin >> height;
    RectangleInCircle pvk(radius, width, height);
    pvk.printInfo();
    pvk.writeToFile("figures_info.txt");
    return 0;
}