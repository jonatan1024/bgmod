#ifndef __BMOD_OBJECT__
#define __BMOD_OBJECT__

#include <stdio.h>
#include <extdll.h>//TODO: is it really nessesary?
#include <btBulletDynamicsCommon.h>

#include <list>

extern btDiscreteDynamicsWorld* g_bt_dynamicsWorld;

#define RAD2DEG 57.2957795

class bmodObject {
private:
	btRigidBody* rigidBody;
	btCollisionShape* shape;
	std::list<int> entities;
public:
	//bmodObject();
	bmodObject(const char * model);
	std::list<int> * getEntities();
	int assignEntity(int entity);
	int removeEntity(int entity);
	void setMass(float mass);
	bool isImmovable();
	btRigidBody* getRigidBody();
	void update();
	~bmodObject();
};

class bmodMotionState : public btMotionState {
public:
	bmodMotionState(bmodObject * obj);
	virtual ~bmodMotionState();
	virtual void getWorldTransform(btTransform &worldTrans) const;
	virtual void setWorldTransform(const btTransform &worldTrans);
protected:
	bmodObject * obj;
};
#endif