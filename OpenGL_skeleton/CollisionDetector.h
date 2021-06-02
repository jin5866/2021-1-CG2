#pragma once
#include<memory>
#include<vector>
#include"SphereCollider.h"

class CollisionDetector
{


	friend std::unique_ptr<CollisionDetector> std::make_unique<CollisionDetector>();
	friend std::unique_ptr<CollisionDetector>::deleter_type;
public:
	static CollisionDetector* getInstance();
	static void distroy();

	virtual void run();
	void addCollider(SphereCollider* s) {
		spheres.push_back(s);
	}
	
	void removeCollider(SphereCollider* s) {
		for (auto st = spheres.begin(); st != spheres.end(); st++) {
			if (st[0] == s) {
				spheres.erase(st);
				return;
			}
		}
	}

	void draw();

private:
	CollisionDetector() = default;
	~CollisionDetector() = default;
	static std::unique_ptr<CollisionDetector> instance;
	
	std::vector<SphereCollider*> spheres;

	bool isCallide(SphereCollider* a, SphereCollider* b);
};
