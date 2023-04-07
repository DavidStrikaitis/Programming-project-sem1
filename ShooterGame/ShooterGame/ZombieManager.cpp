#include "ZombieManager.h"

ZombieManager::ZombieManager()
{
	srand((unsigned)time(nullptr));
}

ZombieManager::~ZombieManager()
{
}

void ZombieManager::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < m_zombieAmount; i++)
	{
		zombies[i].render(t_window);
	}
}

int ZombieManager::getAmountAlive()
{
	int alive{ 0 };
	for (int i = 0; i < m_zombieAmount; i++)
	{
		if (zombies[i].getAlive())
			alive++;
	}
	return alive;
}

void ZombieManager::moveZombiesTowardsPlayer(sf::Vector2f t_location)
{
	m_playerLoc = t_location;
	for (int i = 0; i < m_zombieAmount; i++)
	{
		if(zombies[i].getAlive())
			zombies[i].calculateDirection(m_playerLoc);
	}
#if 0 // this code doesnt work, it may be worked on and fixed later
	for (int i = 0; i < m_zombieAmount; i++)
	{
		if (zombies[i].getAlive())
		{
			for (int u = 0; u < m_zombieAmount; u++)
			{
				if (i != u && zombies[u].returnSpeed() > 0)
				{
					if (zombies[u].getAlive())
					{
						if (zombies[i].getBody().getGlobalBounds().intersects(zombies[u].getBody().getGlobalBounds()))
						{
							zombies[u].setspeed(0);
						}
					}
				}
				else if (!zombies[i].getBody().getGlobalBounds().intersects(zombies[u].getBody().getGlobalBounds()))
				{
					zombies[u].setspeed(3);
				}
			}
		}
	}
#endif // 0


	for (int i = 0; i < m_zombieAmount; i++)
	{
		if(zombies[i].getAlive())
			zombies[i].moveZombie();
	}
}

void ZombieManager::initialiseNewZombie()
{
	int spawnNo = (rand() % 6) + 1;
	int emptySlot{ -1 };
	sf::Vector2f spawnLoc;
	for (int i = 0; i < m_zombieAmount; i++)
	{
		if (!zombies[i].getAlive())
		{
			emptySlot = i;
			break;
		}
	}
	if (emptySlot != -1)
	{
		switch (spawnNo)
		{
		case 1:
			spawnLoc = sf::Vector2f(200, -100);
			break;
		case 2:
			spawnLoc = sf::Vector2f(600, -100);
			break;
		case 3:
			spawnLoc = sf::Vector2f(200, 700);
			break;
		case 4:
			spawnLoc = sf::Vector2f(600, 700);
			break;
		case 5:
			spawnLoc = sf::Vector2f(-100, 300);
			break;
		case 6:
			spawnLoc = sf::Vector2f(900, 300);
			break;
		default:
			break;
		}
		zombies[emptySlot].initZombie(spawnLoc);
		
	}
}
