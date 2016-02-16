/*
 * @File: 			AI.cpp
 * @Description: 	AI class handles algorithms and mathematical problems.
 * @Author: 		Dilpreet Chana
 *
 */

#include "AI.h"
#include "Data.h"

AI::AI()
{
	library = Data::getInstance();
}

AI::~AI()
{
	delete library;
}
