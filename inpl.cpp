#include <iostream>
#include <chrono>
#include <thread>
#include "world.h"

void waiting()
{
    for (int i = 0; i < 30; ++i)
    {
        std::cout << ". ";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << std::endl;
}
int LightSource::retLightCount()
{
    return lightCount;
}

void AirSource::createAir(LightSource* cName, int(LightSource::*ptr)())
{
    int outLightCount = cName->retLightCount();
    while (outLightCount)
    {
        this->airCount += 2;
        outLightCount--;
    }
    std::cout << "\nThanks to the Sun for giving light.\n"
                << "Also thanks to the Tree for receiving oxygen from the light." << std::endl;
}

int AirSource::retAirCount()
{
    return airCount;
}

int Food::retFoodCount()
{
    return foodCount;
}

void Animal::eat(Food* cName, int(Food::*ptr)())
{
    std::cout << "I am very hungry. I'm going to eat grass.\n" << std::endl;
    waiting();
    int outFoodCount = cName->retFoodCount();
	while (outFoodCount)
	{
		outFoodCount--;
		this->stomach++;
	}
	std::cout << "\nOh, I ate grass and I'm not hungry anymore.\n" << std::endl;
	waiting();
}

void Animal::awake(bool state)
{
    if (state == false)
    {  
        std::cout << "It's night, I am sleeping.\n" << std::endl;
        waiting();
        state = true;
    }
    if (state == true)
    {
        std::cout << "\nGood morning. It is morning.";
    }
    
}

void Animal::breathes(AirSource* cName, int(AirSource::*ptr)())
{
    int outAirCount = cName->retAirCount();
	while (outAirCount)
	{
		outAirCount--;
	}
	if (outAirCount == 0)
	{
        std::cout << "\nI'm sorry, but I need oxygen.\n" << std::endl;
        waiting();
    }
	return;
}



