#include "StructureElement.hpp"

namespace hc
{
    /* --- Constructor --- */
    
    Particle::Particle(MathUtils::Vector initPos, MathUtils::Vector initVel, double initMass, double initRad)
    {
        this->pos = initPos;
        this->vel = initVel;
        this->acc = MathUtils::Vector{0.f, 0.f};
        this->mass = initMass;
        this->rad = initRad;
    }

    /* --- Acessors --- */

    MathUtils::Vector Particle::getPosition()
    {
        return pos;
    }

    void Particle::setPosition(MathUtils::Vector newPos)
    {
        pos = newPos;
    }

    void Particle::move(MathUtils::Vector dPos)
    {
        pos = MathUtils::vectorAdd(pos, dPos);
    }

    MathUtils::Vector Particle::getVelocity()
    {
        return vel;
    }

    void Particle::setVelocity(MathUtils::Vector newVel)
    {
        vel = newVel;
    }

    void Particle::accelerate(MathUtils::Vector dVel)
    {
        vel = MathUtils::vectorAdd(vel, dVel);
    }

    MathUtils::Vector Particle::getAcceleration()
    {
        return acc;
    }

    void Particle::setAcceleration(MathUtils::Vector newAcc)
    {
        acc = newAcc;
    }

    /* --- Functions --- */

    void Particle::applyForce(MathUtils::Vector force)
    {   
        // Changes velocity according to the force applied
        
        MathUtils::Vector dAcc = MathUtils::vectorScale(force, 1/mass);
        acc = MathUtils::vectorAdd(acc, dAcc);
    }

    double Particle::getMass()
    {
        return mass;
    }

    double Particle::getRadius()
    {
        return rad;
    }

    void Particle::update(double dt)
    {   
        // Updating position


        accelerate(MathUtils::vectorScale(acc, dt));
        acc = MathUtils::Vector{0.f, 0.f};
        move(MathUtils::vectorScale(vel, dt));
    }
}