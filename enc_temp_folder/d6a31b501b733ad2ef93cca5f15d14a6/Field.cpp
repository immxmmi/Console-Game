#include "Field.h"
Field::Field() {
	this->height = 20 + this->y_edge;	// default Y - WINDOW SIZE 
	this->width = 46 + this->x_edge;   // default X - WINDOW SIZE
}
void Field::drawField() {
	for (int y = 0; y <= this->height; y++) {
		for (int x = 0; x <= this->width; x++) {

			this->field[y][x] = ' ';

			if (x < x_edge - 1) {
				this->field[y][x] = ' ';
			}
			else {

				if (y <= this->height && y > y_edge && x == x_edge - 1) {
					this->field[y][x] = '#';
				}

				if (y == this->height) {
					this->field[y][x] = '#';
				}

				if (y == y_edge) {
					this->field[y][x] = '#';
				}

				if (y <= this->height && y > y_edge && x == this->width)
					this->field[y][x] = '#';
			}
		}
	}
}



char Field::askMe(char input) {
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input != 'y' && input != 'n') { std::cout << "TRY AGAIN" << std::endl; }
	} while (input != 'y' && input != 'n');

	return input;
}



void Field::setHeight() {
	int currentHeight = this->height;
	char input = 'y';


	do {
		this->print_heightMenu();
		std::cout << "Do you want to change the height? y/n" << std::endl;
		input = this->askMe(input);

		if (input == 'y') {
			std::cout << "NEW HEIGHT: ";
			do {
				std::cin >> currentHeight;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (currentHeight > this->max_Height) {
					std::cout << "too BIG" << std::endl;
				}

				if (currentHeight < this->min_Height) {
					std::cout << "too SMALL" << std::endl;
				}

			} while (currentHeight > this->max_Height || currentHeight < this->min_Height);
			this->height = currentHeight + this->y_edge;
		}

	} while (input != 'n');
}




void Field::setWidth() {
	int currentWidth = this->width;
	char input = 'y';

	do {
		this->print_widthMenu();
		std::cout << "Do you want to change the width? y/n" << std::endl;
		input = this->askMe(input);
		if (input == 'y') {
			this->print_widthMenu();
			std::cout << "NEW WIDTH: ";
			do {
				std::cin >> currentWidth;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (currentWidth > this->max_Width) {
					std::cout << "too BIG" << std::endl;
				}

				if (currentWidth < this->min_Width) {
					std::cout << "too SMALL" << std::endl;
				}

			} while (currentWidth > this->max_Width || currentWidth < this->min_Width);
			this->width = currentWidth + this->x_edge;
		}
	} while (input != 'n');
}





int Field::getWidth()
{
	return this->width;
}
int Field::getHeight()
{
	return this->height;
}
int Field::getX_edge()
{
	return this->x_edge;
}
int Field::getY_edge()
{
	return this->y_edge;
}
void Field::printField() {
	this->drawField();
	for (int y = 0; y <= this->height; y++) {
		for (int x = 0; x <= this->width; x++) {
			std::cout << this->field[y][x];
		}
		std::cout << std::endl;
	}
}
void Field::print_heightMenu() {
	system("cls");
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*               HEIGHT             *" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					**      current height: " << this->height - this->y_edge << "        **" << std::endl;
	std::cout << "					**      max height:     " << this->max_Height << "        **" << std::endl;
	std::cout << "					**      min height:     " << this->min_Height << "        **" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*                Momo              *" << std::endl;
	std::cout << "					************************************" << std::endl;
}
void Field::print_widthMenu() {
	system("cls");
	std::cout << std::endl << std::endl << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*               WIDTH              *" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					**      current width: " << this->width - this->x_edge << "         **" << std::endl;
	std::cout << "					**      max width:     " << this->max_Width << "        **" << std::endl;
	std::cout << "					**      min width:     " << this->min_Width << "         **" << std::endl;
	std::cout << "					************************************" << std::endl;
	std::cout << "					*               Momo               *" << std::endl;
	std::cout << "					************************************" << std::endl;
}

