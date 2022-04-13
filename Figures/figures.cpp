#include <iostream>
using namespace std;

class Figure {
public:
	Figure() = default;
	virtual void FindSquare() = 0;
	virtual void PrintFigure() = 0;
	virtual void Draw() = 0;
	virtual void ChangeRectangle(int w, int h) = 0;
};

class Rectangle : public Figure {
public:
	Rectangle(int w, int h) :Figure(), _W(w), _H(h), _square(_W* _H) {}
	Rectangle() :Figure(), _W(0), _H(0), _square(0) {}

	void FindSquare() override {
		cout << _square << endl;
	}

	void ChangeRectangle(int w, int h) override {
		_W = w;
		_H = h;
		_square = _W * _H;
	}
	void PrintFigure() override {
		cout << "W:" << _W << ", H:" << _H << endl;
	}

	void Draw() override {
		for (int i = 0; i < _H; i++) {
			for (int j = 0; j < _W; j++)
				cout << "#";
			cout << endl;
		}
	}
protected:
	int _W;
	int _H;
	int _square;

};

class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) {}
};

int main() {
	Square s(3);
	s.FindSquare();
	s.PrintFigure();
	s.Draw();

	Rectangle r(2, 3);
	r.FindSquare();
	r.PrintFigure();
	r.Draw();

	r.ChangeRectangle(2, 4);
	r.FindSquare();
	r.PrintFigure();
	r.Draw();

}