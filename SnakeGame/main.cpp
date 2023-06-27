﻿#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()
#include <stdio.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_RIGHT	2
#define DIR_LEFT	3

#define BODY_MAX	20

using namespace sf;

class Object {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Snake {
public:
	Snake(int dir, int length) : dir_(dir), length_(length)
	{}

	int GetDir(void) { return dir_; }
	int GetLength(void) { return length_; }

	void SetDir(int dir) { dir_ = dir; }
	void SetLength(int length) { length_ = length; }
	void IncLength(void) { length_++; }

	Object body_[BODY_MAX];
private:
	int dir_;
	int length_;
	
};

class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

int main(void)
{
	const int WIDTH = 1000;							// 픽셀 너비
	const int HEIGHT = 800;							// 픽셀 높이
	const int BLOCK_SIZE = 50;						// 한 칸이 가지고 있는 픽셀
	const int G_WIDTH = WIDTH / BLOCK_SIZE;			// 그리드의 너비
	const int G_HEIGHT = HEIGHT / BLOCK_SIZE;		// 그리드의 높이

	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");

	// 컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다
	// Frame Per Second를 60으로 조절
	window.setFramerateLimit(15);

	Snake snake = Snake(DIR_DOWN, 1);

	for (int i = 0; i < BODY_MAX; i++) {
		snake.body_[i].x_ = -50, snake.body_[i].y_ = -50;			// 뱀의 그리드 좌표
		snake.body_[i].sprite_.setOutlineColor(Color(0, 128, 0));	// 뱀의 테두리 색상
		snake.body_[i].sprite_.setOutlineThickness(5.f);		// 뱀의 두께지정
		snake.body_[i].sprite_.setFillColor(Color::Green);
		snake.body_[i].sprite_.setPosition(snake.body_[i].x_ * BLOCK_SIZE, snake.body_[i].y_ * BLOCK_SIZE);
		snake.body_[i].sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	}
	snake.body_[0].x_ = 3, snake.body_[0].y_ = 3;


	Apple apple;
	apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
	apple.sprite_.setFillColor(Color::Red);
	apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
	apple.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}
		// input
		// 방향키가 동시에 눌러지지 않도록 else 처리
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.SetDir(DIR_RIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.SetDir(DIR_LEFT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.SetDir(DIR_UP);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.SetDir(DIR_DOWN);
		}

		// 머리 이외의 몸통
		for (int i = snake.GetLength()-1; i > 0; i--) {
			snake.body_[i].x_ = snake.body_[i - 1].x_;
			snake.body_[i].y_ = snake.body_[i - 1].y_;
			snake.body_[i].sprite_.setPosition(snake.body_[i].x_ * BLOCK_SIZE, snake.body_[i].y_ * BLOCK_SIZE);
		}

		// update
		// 머리
		if (snake.GetDir() == DIR_UP && snake.body_[0].y_ > 0) {
			snake.body_[0].y_--;
		}
		else if (snake.GetDir() == DIR_DOWN && snake.body_[0].y_ < G_HEIGHT - 1) {
			snake.body_[0].y_++;
		}
		else if (snake.GetDir() == DIR_RIGHT && snake.body_[0].x_ < G_WIDTH - 1) {
			snake.body_[0].x_++;
		}
		else if (snake.GetDir() == DIR_LEFT && snake.body_[0].x_ > 0) {
			snake.body_[0].x_--;
		}
		snake.body_[0].sprite_.setPosition(snake.body_[0].x_ * BLOCK_SIZE, snake.body_[0].y_ * BLOCK_SIZE);

		// 뱀이 사과를 먹었을 때,
		if (snake.body_[0].x_ == apple.x_ && snake.body_[0].y_ == apple.y_) {
			// 사과 위치전환
			apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
			apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);

			// 뱀의 길이를 변화
			if (snake.GetLength() < 20)
				snake.IncLength();
		}


		// render
		window.clear();

		for (int i = 0; i < snake.GetLength(); i++)
			window.draw(snake.body_[i].sprite_);
		window.draw(apple.sprite_);	// draw를 늦게 할 수록 더 위에 있다

		window.display();
	}

	return 0;
}