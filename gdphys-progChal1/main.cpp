#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <cstdlib>
#include <vector>
#include "P6 components/PhysVector.h"
#include "P6 components/PhysParticle.h"
#include "Utils.h"
#include "P6 components/PhysicsWorld.h"

using namespace std;


int main() {
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    Utils utils;
    vector <PhysParticle> orderedFinish;
    int totalUpdateCtr = 0;
    PhysicsWorld pWorld = PhysicsWorld();

    
    sf::RenderWindow window(sf::VideoMode(720, 500), "P6 Test");
    

    sf::Event event;


    //Bourbon
    PhysParticle bparticle;
    bparticle.name = "Bourbon";
    bparticle.velocity = PhysVector(35, 0);
    bparticle.acceleration = PhysVector(8, 0);
    bparticle.position = PhysVector(0,250);

    pWorld.addParticle(&bparticle);

    sf::CircleShape Bourbon(10.0f);
    Bourbon.setFillColor(sf::Color::White);
    Bourbon.setOrigin(Bourbon.getRadius(), Bourbon.getRadius());
    Bourbon.setPosition(bparticle.position.x, bparticle.position.y);

    //Creek
    PhysParticle cparticle;
    cparticle.name = "Creek";
    cparticle.velocity = PhysVector(26, 0);
    cparticle.acceleration = PhysVector(11, 0);
    cparticle.position = PhysVector(0, 150);

    pWorld.addParticle(&cparticle);

    sf::CircleShape Creek(10.0f);
    Creek.setFillColor(sf::Color::Blue);
    Creek.setOrigin(Creek.getRadius(), Creek.getRadius());
    Creek.setPosition(cparticle.position.x, cparticle.position.y);

    //Scarlet
    PhysParticle sparticle;
    sparticle.name = "Scarlet";
    sparticle.velocity = PhysVector(55, 0);
    sparticle.acceleration = PhysVector(3, 0);
    sparticle.position = PhysVector(0, 350);

    pWorld.addParticle(&sparticle);

    sf::CircleShape Scarlet(10.0f);
    Scarlet.setFillColor(sf::Color::Red);
    Scarlet.setOrigin(Scarlet.getRadius(), Scarlet.getRadius());
    Scarlet.setPosition(sparticle.position.x, sparticle.position.y);

    //Finish Line
    sf::RectangleShape finishLine(sf::Vector2f(5.0f,720.0f));
    finishLine.setPosition(500, 0);

    sf::Clock clock;
    sf::Time timeSinceLast = sf::Time::Zero;

    while (1) {

        timeSinceLast += clock.restart();
  
        if (timeSinceLast > TimePerFrame) {

            timeSinceLast -= TimePerFrame;
            
            //cout << TimePerFrame.asMilliseconds()/1000.0f << endl;

            /*
            bparticle.update(TimePerFrame.asMilliseconds()/1000.0f);
            Bourbon.setPosition(bparticle.position.x, bparticle.position.y);


            cparticle.update(TimePerFrame.asMilliseconds()/1000.0f);
            Creek.setPosition(cparticle.position.x, cparticle.position.y);

            sparticle.update(TimePerFrame.asMilliseconds()/1000.0f);
            Scarlet.setPosition(sparticle.position.x, sparticle.position.y);
            */

            pWorld.update(TimePerFrame.asMilliseconds() / 1000.0f);

            Bourbon.setPosition(bparticle.position.x, bparticle.position.y);
            Creek.setPosition(cparticle.position.x, cparticle.position.y);
            Scarlet.setPosition(sparticle.position.x, sparticle.position.y);

            totalUpdateCtr++;
            
            

            window.pollEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

            window.clear();

            if(bparticle.getIsDestroyed() != true)
                window.draw(Bourbon);

            if (sparticle.getIsDestroyed() != true)
                window.draw(Scarlet);

            if (cparticle.getIsDestroyed() != true)
                window.draw(Creek);
            
            window.draw(finishLine);
            window.display();


            if (cparticle.position.x >= 500 + finishLine.getSize().x && cparticle.isFinished == false)
            {
                orderedFinish.push_back(cparticle);
                cparticle.isFinished = true;
                cparticle.setIsDestroyed();
            }
            
            if(bparticle.position.x >= 500 + finishLine.getSize().x && bparticle.isFinished == false) 
            {
                orderedFinish.push_back(bparticle);
                bparticle.isFinished = true;
                bparticle.setIsDestroyed();
            }
            if (sparticle.position.x >= 500 + finishLine.getSize().x && sparticle.isFinished == false)
            {
                orderedFinish.push_back(sparticle);
                sparticle.isFinished = true;
                sparticle.setIsDestroyed();
            }

            if (cparticle.isFinished == true && bparticle.isFinished == true && sparticle.isFinished == true)
            {
                break;
            }
        }
    }
   
    utils.displayStats(orderedFinish, totalUpdateCtr);
    
    
    return 0;
}