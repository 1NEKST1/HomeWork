

#include <iostream>
#include <string>

using namespace std;

class Rat {
private:
    double a;
    double b;
public:
    Rat(int a, int b) {
        this->a = a;
        this->b = b;
    }

    ~Rat() {

    }
    void print() {
        cout << a << '/' << b << endl;

    }
    Rat operator+(const Rat& other) {
        Rat result{ *this };
        result.a += other.a;
        result.b += other.b;
        return result;
    }

    Rat operator-(const Rat& other) {
        Rat result{ *this };
        result.a -= other.a;
        result.b -= other.b;
        return result;
    }

    Rat operator*(const Rat& other) {
        Rat result{ *this };
        result.a *= other.a;
        result.b *= other.b;
        return result;
    }

    Rat operator/(const Rat& other) {
        Rat result{ *this };
        result.a /= other.a;
        result.b /= other.b;
        return result;
    }
    void setA(int a){
        this->a = a;
    }

    void setB(int b) {
        this->b = b;
    }

};

class Complex {
private:
	int a;
	int b;
public:
	Complex(int x, int y) {
		this->a = x;
		this->b = y;
	}

	Complex operator +(Complex& object) {
		return Complex{ this->a + object.a, this->b + object.b };
	}

	Complex operator -(Complex& object) {
		return Complex{ this->a - object.a, this->b - object.b };
	}

	Complex operator *(Complex& object) {
		return Complex{ this->a * object.a, this->b * object.b };
	}

	Complex operator /(Complex& object) {
		return Complex{ this->a / object.a, this->b / object.b };
	}

	bool operator ==(Complex& object) {
		return this->a == object.a && this->b == object.b;
	}

	bool operator !=(Complex& object) {
		return this->a != object.a && this->b != object.b;
	}

	bool operator >(Complex& object) {
		return this->a > object.a && this->b > object.b;
	}

	bool operator <(Complex& object) {
		return this->a < object.a && this->b < object.b;
	}

	bool operator >=(Complex& object) {
		return this->a >= object.a && this->b >= object.b;
	}

	bool operator <=(Complex& object) {
		return this->a <= object.a && this->b <= object.b;
	}
	void SetA(int a) {
		this->a = a;
	}

	void SetB(int b) {
		this->b = b;
	}

	void Print() {
		cout << this->a << ' ' << this->b;
	}

};

class Overcoat {
private:
	string type;
	double price;
public:
	Overcoat(string a, double b) {
		this->type = a;
		this->price = b;
	}

	bool operator ==(Overcoat& object) {
		return this->type == object.type;
	}
	
	void operator =(Overcoat& object) {
		this->type = object.type;
		this->price = object.price;
	}

	bool operator >(Overcoat& object) {
		return this->price > object.price;
	}

};

class Overcoat {
private:
	double s;
	double price;
public:
	Overcoat(double a, double b) {
		this->s = a;
		this->price = b;
	}

	bool operator ==(Overcoat& object) {
		return this->s == object.s;
	}

	void operator =(Overcoat& object) {
		this->s = object.s;
		this->price = object.price;
	}

	bool operator >(Overcoat& object) {
		return this->price > object.price;
	}

};


int main()
{
    /*Rat r1{ 1, 2 };
    Rat r2{2, 3};
    Rat r3{ r1 + r2 };*/
    //r3.print();

	/*Overcoat o1{ "пальто", 1000 };
	Overcoat o2{ "пальто", 100 };
	bool c = o1 == o2;
	cout << c;
	bool c = o1 > o2;
	cout << c;*/


}
