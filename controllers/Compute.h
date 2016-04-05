#pragma once


class Compute
{
public:
	Compute(int x, int y);
	~Compute();
	
	void inputMatrix();
	void displayMatrix();

private:
	int** mMatrix;
	int w, h;
};