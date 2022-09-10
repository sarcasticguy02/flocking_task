#include "CohesionRule.h"
#include "../gameobjects/Boid.h"
using namespace std;

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce = Vector2(0, 0);

    if (neighborhood.size() > 0)
    {
        for (int i = 0; i < neighborhood.size(); i++)
        {
            cohesionForce += neighborhood[i]->getPosition();
        }
        cohesionForce = (cohesionForce / neighborhood.size()) - boid->getPosition();
    }

    return cohesionForce.normalized();
}