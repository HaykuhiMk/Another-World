class Food
{
public:
	Food()
	{
		foodCount = 30;
	}
public:
	int retFoodCount();
private:
	int foodCount;
};



class LightSource
{
public:
	LightSource()
	{
		lightCount = 50;	
	}
public:
	int retLightCount();
private:
	int lightCount;
};

class AirSource
{
public:
	AirSource()
	{
		airCount = 0;
	}
public:
    void createAir(LightSource* cName, int(LightSource::*ptr)());
	int retAirCount();
private:
	int airCount;
};


class Animal
{
public:
	Animal()
	{
		stomach = 0;
	}

public:
	void eat(Food* obj, int(Food::*ptr)());
	void awake(bool state);
	void breathes(AirSource* cName, int(AirSource::*ptr)());
private:
	int stomach;
	int grassCount;
};
