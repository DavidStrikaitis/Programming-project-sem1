#include "bulletManager.h"
#include"ZombieEnemy.h"

bulletManager::bulletManager()
{
}

bulletManager::~bulletManager()
{
	std::cout << "Destroyed bullet manager" << std::endl;
}

void bulletManager::spawnNewBullet(player& t_player)
{
	if (bulletAmount < MAX_BULLETS)
	{
		spawnBulletInArrayPos(bulletAmount, t_player);
		bulletAmount++;
	}
	else if (bulletAmount == MAX_BULLETS)
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].getActive())
				continue;

			spawnBulletInArrayPos(i, t_player);
			break;
		}
	}
}

void bulletManager::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < bulletAmount; i++)
	{
		if(bullets[i].getActive())
			bullets[i].render(t_window);
	}
}

void bulletManager::moveBullets()
{
	for (int i = 0; i < bulletAmount; i++)
	{
		if (bullets[i].getActive())
			bullets[i].moveBullet();
	}
}

void bulletManager::deactivateBullets(sf::RectangleShape props[])
{
	for (int i = 0; i < bulletAmount; i++)
	{
		if (!bullets[i].getActive())
			continue;
		for (int u = 0; u < 5; u++)
		{
			if (props[u].getGlobalBounds().intersects(bullets[i].returnBulletBounds()))
			{
				bullets[i].deactivateBullet();
				break;
			}
		}
	}
}

// ************************************************
// private functions

void bulletManager::spawnBulletInArrayPos(int t_pos, player& t_player)
{
	bullets[t_pos].init(t_player.returnPosition(), t_player.returnAim());
}
