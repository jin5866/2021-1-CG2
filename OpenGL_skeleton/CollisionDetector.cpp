#include "CollisionDetector.h"
//#include "SphereCollider.h"
#include"MyMath.h"
#include<iostream>
CollisionDetector* CollisionDetector::getInstance()
{
    if (!instance) {
        instance.reset(new CollisionDetector());
    }
    return instance.get();
}

void CollisionDetector::distroy()
{
    delete instance.release();
}

void CollisionDetector::run()
{
   // std::cout << spheres.size() << std::endl;
    for (auto a = spheres.begin(); a != spheres.end(); a++) {

        if (a[0]->getpos()[1] - a[0]->getSize() <= -50) {
            //std::cout << "b" << std::endl;
            a[0]->onCollision({ 0,1,0 });
        }

        if (a[0]->getpos()[1] + a[0]->getSize() >= 50) {
            //std::cout << "b" << std::endl;
            a[0]->onCollision({ 0,-1,0 });
        }

        if (a[0]->getpos()[0] - a[0]->getSize() <= -100) {
            //std::cout << "b" << std::endl;
            a[0]->onCollision({ 1,0,0 });
        }

        if (a[0]->getpos()[0] + a[0]->getSize() >= 100) {
            //std::cout << "b" << std::endl;
            a[0]->onCollision({ -1,0,0 });
        }

        if (a[0]->getpos()[2] - a[0]->getSize() <= -100) {
            //std::cout << "b" << std::endl;
            a[0]->onCollision({ 0,0,1 });
        }

        if (a[0]->getpos()[2] + a[0]->getSize() >= 100) {
            //std::cout << "b" << std::endl;
            a[0]->onCollision({ 0,0,-1 });
        }

        for (auto b = a + 1; b != spheres.end(); b++) {
            if (isCallide(a[0], b[0])) {
                //std::cout << "c" << std::endl;
                a[0]->onCollision(b[0]);
                b[0]->onCollision(a[0]);
                a[0]->onCollisionEnd(b[0]);
                b[0]->onCollisionEnd(a[0]);

            }
        }


    }


}

bool CollisionDetector::isCallide(SphereCollider* a, SphereCollider* b)
{
    auto apos = a->getpos();
    float asize = a->getSize();
    auto bpos = b->getpos();
    float bsize = b->getSize();

    auto dis = (apos - bpos);
    return (dis[0] * dis[0] + dis[1] * dis[1] + dis[2] * dis[2]) <= (asize + bsize) * (asize + bsize);
}



std::unique_ptr<CollisionDetector> CollisionDetector::instance = nullptr;